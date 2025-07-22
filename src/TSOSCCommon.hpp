#ifndef TSOSCCOMMON_HPP
#define TSOSCCOMMON_HPP

#ifdef METAMODULE_NO_OSC
// MetaModule version - no OSC functionality
#define OSC_ADDRESS_DEF "127.0.0.1"
#define OSC_OUTPORT_DEF 8000
#define OSC_INPORT_DEF 9000
#define OSC_DEFAULT_NS "/trowaSoft"
#define OSC_ADDRESS_BUFFER_SIZE 128

struct TSOSCConnectionInfo {
    const char* address;
    int outPort;
    int inPort;
};

struct TSOSCInfo {
    const char* address;
    int outPort;
    int inPort;
};

enum OSCClient {
    GenericClient = 0
};

#else
// Original OSC includes would go here
#include "TSOSCCommon.hpp"
#endif

#endif // TSOSCCOMMON_HPP 