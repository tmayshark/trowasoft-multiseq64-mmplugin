# trowaSoft multiSeq64 MetaModule Plugin

A MetaModule-compatible version of the trowaSoft multiSeq64 sequencer module, converted from the original VCV Rack plugin.

## Overview

This is completely untested as the person who mangled it together doesn't have a 
MetaModule. But I'm curious if it works at all!

This package contains a MetaModule plugin version of the trowaSoft multiSeq64 sequencer, which provides a 64-step trigger/variable voltage/note sequencer. The original OSC (Open Sound Control) functionality has been removed to ensure compatibility with the MetaModule platform.

### Features

- **64-step sequencer** with 16 channels (outputs)
- **64 patterns** for complex sequencing
- **Multiple output modes** per channel:
  - **TRIG** (trigger) - 0 or 10V trigger output
  - **RTRG** (retrigger) - 0 or 10V retrigger output  
  - **GATE** (continuous) - 0 or 10V gate output
  - **VOLT** - Variable voltage (-10V to +10V)
  - **NOTE** - MIDI note output (-5V to +5V)
  - **PATT** - Pattern control (-10V to +10V)
- **Pattern management** with copy/paste functionality
- **Advanced randomization** options
- **Song Mode** internal pattern sequencer (up to 64 sequences)

## Build Requirements

This package includes a complete build environment using Flox and direnv. The following tools are automatically installed:

- **cmake** v3.22 or later
- **ninja** build system
- **gcc-arm-embedded-12** toolchain
- **python3** for build scripts

## Quick Start

1. **Clone or download** this package
2. **Initialize git submodules** (if cloning from git):
   ```bash
   git submodule update --init --recursive
   ```
3. **Navigate** to the package directory
4. **Activate the environment**:
   ```bash
   direnv allow
   ```
5. **Build the plugin**:
   ```bash
   mkdir build
   cd build
   cmake ..
   ninja
   ```
6. **Install on MetaModule**:
   - Copy `trowaSoft-multiSeq64.mmplugin` from `build/` to your MetaModule device
   - The plugin will appear as "trowaSoft multiSeq64" in your MetaModule plugin list

## Detailed Build Instructions

### Prerequisites

- **Flox**: Package manager for reproducible environments
- **direnv**: Automatic environment activation
- **Git**: For version control (optional)

### Environment Setup

The package includes a complete Flox environment that automatically installs all required build tools:

```bash
# The .envrc file will automatically activate the Flox environment
direnv allow

# Verify the environment is active
which cmake
which ninja
which arm-none-eabi-gcc
```

### Build Process

1. **Create build directory**:
   ```bash
   mkdir build
   cd build
   ```

2. **Configure with CMake**:
   ```bash
   cmake ..
   ```

3. **Build the plugin**:
   ```bash
   ninja
   ```

4. **Verify the build**:
   ```bash
   ls -la trowaSoft-multiSeq64.mmplugin
   ```

### Build Output

The build process will create:
- `trowaSoft-multiSeq64.mmplugin` - The MetaModule plugin file (approximately 120KB)
- Various intermediate build files in the build directory

## Installation

1. **Copy the plugin file** to your MetaModule device:
   ```bash
   cp build/trowaSoft-multiSeq64.mmplugin /path/to/metamodule/plugins/
   ```

2. **Restart your MetaModule** or reload plugins

3. **Access the plugin** in your MetaModule's plugin browser under "trowaSoft multiSeq64"

## Usage

### Basic Operation

1. **Add the module** to your MetaModule patch
2. **Connect a clock** to the CLOCK input
3. **Set the pattern** using the PATTERN knob (1-64)
4. **Adjust BPM** using the BPM knob
5. **Set step length** using the LENGTH knob
6. **Configure output modes** for each channel as needed

### Pattern Programming

- **Click on grid cells** to toggle steps on/off
- **Drag across multiple cells** to set multiple steps
- **Use the channel selector** to program different channels
- **Copy/paste patterns** using the context menu

### Advanced Features

- **Randomization**: Use the RANDOM button for pattern generation
- **Song Mode**: Configure automatic pattern changes
- **Channel modes**: Set different output modes per channel
- **Pattern linking**: Use PATT mode to control other sequencers

## Troubleshooting

### Build Issues

1. **Environment not activated**:
   ```bash
   direnv allow
   source .envrc
   ```

2. **Missing build tools**:
   ```bash
   flox install cmake ninja gcc-arm-embedded-12
   ```

3. **CMake configuration errors**:
   - Ensure you're in the build directory
   - Check that the MetaModule SDK path is correct

### Plugin Issues

1. **Plugin not appearing**:
   - Verify the .mmplugin file is in the correct directory
   - Check file permissions
   - Restart the MetaModule

2. **Plugin crashes**:
   - Check for sufficient memory
   - Verify all connections are correct
   - Try a simpler patch first

## License Information

This project is licensed under the **GNU General Public License v3.0 or later** (GPL-3.0-or-later).

### Original Authors and Licenses

- **trowaSoft-VCV**: Copyright (c) j4s0n-c, licensed under GPL-3.0-or-later
- **MetaModule SDK**: Copyright (c) MetaModule team, licensed under GPL-3.0
- **VCV Rack Dependencies**: Various licenses (see `licenses/LICENSE-dist.md`)

### License Compliance

This package complies with the GPL-3.0-or-later license by:
- Providing complete source code
- Including build instructions
- Maintaining all original license notices
- Properly attributing all original authors

## Source Code Structure

```
src/
├── metamodule-plugin.cpp          # Main plugin entry point
├── Module_multiSeq_simple.hpp     # Simplified multiSeq implementation
├── trowaSoftCLights.hpp          # Color definitions
├── TSColors.hpp                   # Color utilities
├── TSParamQuantity.hpp           # Parameter handling
├── TSParamTextField.hpp          # Text field parameters
├── TSTextField.hpp               # Text field components
├── TSTempoBPM.hpp                # Tempo handling
├── TSModuleBase.hpp              # Base module class
├── TSSModuleWidgetBase.hpp       # Base widget class
├── trowaSoft.hpp                 # Main plugin header
└── Features.hpp                  # Feature definitions
```

## Modifications from Original

This MetaModule version includes the following modifications from the original trowaSoft-VCV plugin:

1. **OSC Removal**: Open Sound Control functionality has been removed for MetaModule compatibility
2. **UI Simplification**: Some complex UI elements have been adapted for the MetaModule interface
3. **Memory Optimization**: Code has been optimized for MetaModule's resource constraints
4. **Build System**: Adapted to use the MetaModule SDK and build system

## Support

Nope.

## Acknowledgments

- **j4s0n-c**: Original trowaSoft-VCV plugin author
- **MetaModule team**: MetaModule platform and SDK
- **VCV Rack team**: VCV Rack framework and dependencies

## Version Information

- **Plugin Version**: 2.0.9 (based on original trowaSoft-VCV version)
- **MetaModule SDK**: Compatible with current MetaModule platform
- **Build Date**: See build timestamp in the .mmplugin file

---

**Note**: This is a community conversion of the original trowaSoft-VCV plugin. The original plugin and its author (j4s0n-c) are not affiliated with this MetaModule conversion. 