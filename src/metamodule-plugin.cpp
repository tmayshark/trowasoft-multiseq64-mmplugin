#include "Module_multiSeq_simple.hpp"

// The pluginInstance-wide instance of the Plugin class
Plugin *pluginInstance;

void init(rack::Plugin *p) {
	pluginInstance = p;
	
	// Register the multiSeq64 module for MetaModule
	p->addModel(modelMultiSeq64);
	
	// Note: For MetaModule conversion, we're focusing on the multiSeq64 module
	// Other modules from the original trowaSoft plugin are not included
	// to reduce complexity and focus on the core sequencer functionality
	
	return;
} 