#ifndef TSOSCCOMMUNICATOR_HPP
#define TSOSCCOMMUNICATOR_HPP

#ifdef METAMODULE_NO_OSC
// MetaModule version - no OSC functionality
class TSOSCCommunicator {
public:
    TSOSCCommunicator() {}
    ~TSOSCCommunicator() {}
};
#else
// Original OSC includes would go here
#include "TSOSCCommunicator.hpp"
#endif

#endif // TSOSCCOMMUNICATOR_HPP 