#ifndef MODULE_MULTISEQ_SIMPLE_HPP
#define MODULE_MULTISEQ_SIMPLE_HPP

#include "rack.hpp"
#include "trowaSoft.hpp"
#include "TSColors.hpp"
#include "TSTempoBPM.hpp"

using namespace rack;

// Simplified multiSeq64 module for MetaModule
struct MultiSeq64 : Module {
    enum ParamIds {
        BPM_PARAM,
        RUN_PARAM,
        RESET_PARAM,
        STEPS_PARAM,
        NUM_PARAMS
    };
    
    enum InputIds {
        BPM_INPUT,
        EXT_CLOCK_INPUT,
        RESET_INPUT,
        STEPS_INPUT,
        NUM_INPUTS
    };
    
    enum OutputIds {
        CHANNELS_OUTPUT,
        NUM_OUTPUTS = CHANNELS_OUTPUT + 16  // 16 channels
    };
    
    enum LightIds {
        RUNNING_LIGHT,
        RESET_LIGHT,
        CHANNEL_LIGHTS,
        NUM_LIGHTS = CHANNEL_LIGHTS + 16
    };

    // Basic sequencer state
    bool running = true;
    int index = 0;
    int maxSteps = 64;
    float currentBPM = 120.0f;
    
    // Step data (simplified - just triggers)
    bool triggerState[64][16];  // 64 steps, 16 channels
    
    // Triggers
    dsp::SchmittTrigger clockTrigger;
    dsp::SchmittTrigger runningTrigger;
    dsp::SchmittTrigger resetTrigger;
    
    MultiSeq64() {
        config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
        
        configParam(BPM_PARAM, 30.0f, 300.0f, 120.0f, "BPM");
        configParam(RUN_PARAM, 0.0f, 1.0f, 1.0f, "Run");
        configParam(RESET_PARAM, 0.0f, 1.0f, 0.0f, "Reset");
        configParam(STEPS_PARAM, 1.0f, 64.0f, 64.0f, "Steps");
        
        // Initialize trigger states
        for (int step = 0; step < 64; step++) {
            for (int ch = 0; ch < 16; ch++) {
                triggerState[step][ch] = false;
            }
        }
    }
    
    void process(const ProcessArgs& args) override {
        // Handle run button
        if (runningTrigger.process(params[RUN_PARAM].getValue())) {
            running = !running;
        }
        
        // Handle reset
        if (resetTrigger.process(params[RESET_PARAM].getValue()) || 
            resetTrigger.process(inputs[RESET_INPUT].getVoltage())) {
            index = 0;
        }
        
        // Update BPM
        currentBPM = params[BPM_PARAM].getValue() + inputs[BPM_INPUT].getVoltage() * 10.0f;
        currentBPM = clamp(currentBPM, 30.0f, 300.0f);
        
        // Update max steps
        maxSteps = (int)clamp(params[STEPS_PARAM].getValue() + inputs[STEPS_INPUT].getVoltage() * 8.0f, 1.0f, 64.0f);
        
        // Clock detection
        bool clockTriggered = clockTrigger.process(inputs[EXT_CLOCK_INPUT].getVoltage());
        
        if (running && clockTriggered) {
            // Output current step
            for (int ch = 0; ch < 16; ch++) {
                outputs[CHANNELS_OUTPUT + ch].setVoltage(triggerState[index][ch] ? 10.0f : 0.0f);
                lights[CHANNEL_LIGHTS + ch].setBrightness(triggerState[index][ch] ? 1.0f : 0.0f);
            }
            
            // Advance to next step
            index = (index + 1) % maxSteps;
        }
        
        // Update lights
        lights[RUNNING_LIGHT].setBrightness(running ? 1.0f : 0.0f);
        lights[RESET_LIGHT].setBrightness(0.0f);
    }
    
    void onReset() override {
        for (int step = 0; step < 64; step++) {
            for (int ch = 0; ch < 16; ch++) {
                triggerState[step][ch] = false;
            }
        }
        index = 0;
        running = true;
    }
    
    json_t* dataToJson() override {
        json_t* rootJ = json_object();
        
        json_object_set_new(rootJ, "running", json_boolean(running));
        json_object_set_new(rootJ, "index", json_integer(index));
        json_object_set_new(rootJ, "maxSteps", json_integer(maxSteps));
        json_object_set_new(rootJ, "currentBPM", json_real(currentBPM));
        
        // Save trigger states
        json_t* triggerArrayJ = json_array();
        for (int step = 0; step < 64; step++) {
            json_t* stepArrayJ = json_array();
            for (int ch = 0; ch < 16; ch++) {
                json_array_append_new(stepArrayJ, json_boolean(triggerState[step][ch]));
            }
            json_array_append_new(triggerArrayJ, stepArrayJ);
        }
        json_object_set_new(rootJ, "triggerState", triggerArrayJ);
        
        return rootJ;
    }
    
    void dataFromJson(json_t* rootJ) override {
        json_t* runningJ = json_object_get(rootJ, "running");
        if (runningJ) running = json_boolean_value(runningJ);
        
        json_t* indexJ = json_object_get(rootJ, "index");
        if (indexJ) index = json_integer_value(indexJ);
        
        json_t* maxStepsJ = json_object_get(rootJ, "maxSteps");
        if (maxStepsJ) maxSteps = json_integer_value(maxStepsJ);
        
        json_t* currentBPMJ = json_object_get(rootJ, "currentBPM");
        if (currentBPMJ) currentBPM = json_real_value(currentBPMJ);
        
        // Load trigger states
        json_t* triggerArrayJ = json_object_get(rootJ, "triggerState");
        if (triggerArrayJ) {
            for (int step = 0; step < 64; step++) {
                json_t* stepArrayJ = json_array_get(triggerArrayJ, step);
                if (stepArrayJ) {
                    for (int ch = 0; ch < 16; ch++) {
                        json_t* triggerJ = json_array_get(stepArrayJ, ch);
                        if (triggerJ) {
                            triggerState[step][ch] = json_boolean_value(triggerJ);
                        }
                    }
                }
            }
        }
    }
};

// Model definition
struct MultiSeq64Widget : ModuleWidget {
    MultiSeq64Widget(MultiSeq64* module) {
        setModule(module);
        setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/multiSeq.svg")));
        
        addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
        addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
        addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
        addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
        
        // Add basic controls
        addParam(createParamCentered<RoundBlackKnob>(Vec(67.5, 73), module, MultiSeq64::BPM_PARAM));
        addParam(createParamCentered<CKSS>(Vec(67.5, 115), module, MultiSeq64::RUN_PARAM));
        addParam(createParamCentered<RoundBlackKnob>(Vec(67.5, 157), module, MultiSeq64::STEPS_PARAM));
        
        addInput(createInputCentered<PJ301MPort>(Vec(22.5, 73), module, MultiSeq64::BPM_INPUT));
        addInput(createInputCentered<PJ301MPort>(Vec(22.5, 115), module, MultiSeq64::EXT_CLOCK_INPUT));
        addInput(createInputCentered<PJ301MPort>(Vec(22.5, 157), module, MultiSeq64::STEPS_INPUT));
        addInput(createInputCentered<PJ301MPort>(Vec(22.5, 199), module, MultiSeq64::RESET_INPUT));
        
        // Add outputs
        for (int i = 0; i < 16; i++) {
            addOutput(createOutputCentered<PJ301MPort>(Vec(112.5, 73 + i * 20), module, MultiSeq64::CHANNELS_OUTPUT + i));
            addChild(createLightCentered<MediumLight<RedLight>>(Vec(112.5, 73 + i * 20), module, MultiSeq64::CHANNEL_LIGHTS + i));
        }
        
        // Add lights
        addChild(createLightCentered<MediumLight<GreenLight>>(Vec(67.5, 115), module, MultiSeq64::RUNNING_LIGHT));
    }
};

Model* modelMultiSeq64 = createModel<MultiSeq64, MultiSeq64Widget>("MultiSeq64");

#endif // MODULE_MULTISEQ_SIMPLE_HPP 