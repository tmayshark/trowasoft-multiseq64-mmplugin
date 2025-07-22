cmake_minimum_required(VERSION 3.22)

if(NOT "${METAMODULE_SDK_DIR}" STREQUAL "")
	message("METAMODULE_SDK_DIR set by CMake variable ${METAMODULE_SDK_DIR}")
elseif (DEFINED ENV{METAMODULE_SDK_DIR})
    set(METAMODULE_SDK_DIR "$ENV{METAMODULE_SDK_DIR}")
	message("METAMODULE_SDK_DIR set by environment variable ${METAMODULE_SDK_DIR}")
else()
    set(METAMODULE_SDK_DIR "${CMAKE_CURRENT_LIST_DIR}/../metamodule-plugin-sdk")
	message("METAMODULE_SDK_DIR set to default: ${METAMODULE_SDK_DIR}")
endif()

include(${METAMODULE_SDK_DIR}/plugin.cmake)

project(trowaSoftModules 
    VERSION 2.0.9
    DESCRIPTION "trowaSoft Plugin for MetaModule" 
    LANGUAGES C CXX ASM
)

add_library(trowaSoftModules STATIC)

set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/../../trowaSoft-VCV)

# Core trowaSoft source files (simplified for MetaModule - no OSC)
target_sources(trowaSoftModules PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/metamodule-plugin.cpp
    
    # MultiSeq module (simplified for MetaModule)
    ${CMAKE_CURRENT_LIST_DIR}/src/Module_multiSeq_simple.hpp
    
    # Essential utility classes only
    ${SOURCE_DIR}/src/trowaSoftCLights.hpp
    ${SOURCE_DIR}/src/TSColors.hpp
    
    # Parameter handling (headers only)
    ${SOURCE_DIR}/src/TSParamQuantity.hpp
    ${SOURCE_DIR}/src/TSParamTextField.hpp
    
    # Text field components (header only)
    ${SOURCE_DIR}/src/TSTextField.hpp
    
    # Tempo handling (header only)
    ${SOURCE_DIR}/src/TSTempoBPM.hpp
    
    # Base module classes
    ${SOURCE_DIR}/src/TSModuleBase.hpp
    ${SOURCE_DIR}/src/TSSModuleWidgetBase.hpp
    
    # Main plugin files (simplified)
    ${SOURCE_DIR}/src/trowaSoft.hpp
    
    # Features
    ${SOURCE_DIR}/src/Features.hpp
)

# Add includes and compile options for source repo
target_include_directories(trowaSoftModules 
    PRIVATE 
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/src
    ${SOURCE_DIR}/src
    ${SOURCE_DIR}/lib
)

target_compile_options(trowaSoftModules PRIVATE 
$<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-enum-float-conversion>
$<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-enum-enum-conversion>
$<$<COMPILE_LANGUAGE:CXX>:-Wno-array-bounds>
$<$<COMPILE_LANGUAGE:CXX>:-Wno-unused-variable>
$<$<COMPILE_LANGUAGE:CXX>:-Wno-unused-function>
$<$<COMPILE_LANGUAGE:CXX>:-DMETAMODULE_NO_OSC>
$<$<COMPILE_LANGUAGE:CXX>:-fexceptions>
)

if("${INSTALL_DIR}" STREQUAL "")
    set(INSTALL_DIR ${CMAKE_CURRENT_LIST_DIR}/metamodule-plugins)
endif()

create_plugin(
    SOURCE_LIB      trowaSoftModules                   # This is the cmake target name (defined in add_target)
    PLUGIN_NAME     trowaSoft-multiSeq64               # This must match the brand "slug" used in VCV Rack
    PLUGIN_JSON     ${CMAKE_CURRENT_LIST_DIR}/plugin.json          # Path to the plugin.json file used by VCV Rack
    SOURCE_ASSETS   ${CMAKE_CURRENT_LIST_DIR}/assets   # Path to the assets/ dir containing the PNGs
    DESTINATION     ${INSTALL_DIR}                     # Dir where plugin .mmplugin file should be put
) 