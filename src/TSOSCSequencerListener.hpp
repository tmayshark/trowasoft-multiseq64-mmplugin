#ifndef TSOSCSEQUENCERLISTENER_HPP
#define TSOSCSEQUENCERLISTENER_HPP

#ifdef METAMODULE_NO_OSC
// MetaModule version - no OSC functionality
class TSOSCSequencerListener {
public:
    TSOSCSequencerListener() {}
    ~TSOSCSequencerListener() {}
};
#else
// Original OSC includes would go here
#include "TSOSCSequencerListener.hpp"
#endif

#endif // TSOSCSEQUENCERLISTENER_HPP 