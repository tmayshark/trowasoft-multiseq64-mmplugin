#ifndef TSOSCSEQUENCEROUTPUTMESSAGES_HPP
#define TSOSCSEQUENCEROUTPUTMESSAGES_HPP

#ifdef METAMODULE_NO_OSC
// MetaModule version - no OSC functionality
struct SeqOSCOutputMsg {
    static const int NUM_OSC_OUTPUT_MSGS = 0;
};
#else
// Original OSC includes would go here
#include "TSOSCSequencerOutputMessages.hpp"
#endif

#endif // TSOSCSEQUENCEROUTPUTMESSAGES_HPP 