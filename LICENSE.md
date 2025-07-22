# License Information

This project is licensed under the **GNU General Public License v3.0 or later** (GPL-3.0-or-later).

## Project License

This MetaModule conversion of the trowaSoft multiSeq64 plugin is licensed under the GNU General Public License v3.0 or later. This means you are free to:

- Use the software for any purpose
- Change the software to suit your needs
- Share the software with others
- Share the changes you make

However, if you distribute this software (or a work based on it), you must:
- Provide the complete source code
- Include this license and all original license notices
- State any changes you made
- License the entire work under GPL-3.0-or-later

## Original Software and Licenses

### trowaSoft-VCV Plugin
- **Copyright**: (c) j4s0n-c
- **License**: GNU General Public License v3.0 or later (GPL-3.0-or-later)
- **Original Repository**: https://github.com/j4s0n-c/trowaSoft-VCV
- **Contact**: trowasoft.vcv@gmail.com

The original trowaSoft-VCV plugin is the foundation of this MetaModule conversion. All original functionality has been preserved except for the OSC (Open Sound Control) features, which were removed for MetaModule compatibility.

### MetaModule SDK
- **Copyright**: (c) MetaModule team
- **License**: GNU General Public License v3.0 (GPL-3.0)
- **Purpose**: Provides the interface between VCV Rack plugins and the MetaModule platform

The MetaModule SDK enables VCV Rack plugins to run on the MetaModule hardware platform.

### VCV Rack Dependencies

The following libraries are used by the VCV Rack framework and are included in the MetaModule SDK:

#### GLEW (OpenGL Extension Wrangler Library)
- **Copyright**: (c) 2002-2007, Milan Ikits, Marcelo E. Magallon, Lev Povalahev
- **License**: Modified BSD License
- **Purpose**: OpenGL extension loading

#### GLFW
- **Copyright**: (c) 2002-2006 Marcus Geelnard, (c) 2006-2011 Camilla Berglund
- **License**: zlib/libpng license
- **Purpose**: OpenGL context creation and window management

#### jansson
- **Copyright**: (c) 2009-2016 Petri Lehtinen
- **License**: MIT License
- **Purpose**: JSON parsing and manipulation

#### OpenSSL
- **Copyright**: (c) 1998-2017 The OpenSSL Project
- **License**: OpenSSL License + SSLeay License
- **Purpose**: Cryptographic functions

#### curl
- **Copyright**: (c) 1996 - 2017, Daniel Stenberg
- **License**: MIT License
- **Purpose**: HTTP client library

#### Zstandard
- **Copyright**: (c) 2016-present, Facebook, Inc.
- **License**: BSD 3-Clause License
- **Purpose**: Data compression

#### libarchive
- **Copyright**: (c) 2003-2018 Tim Kientzle
- **License**: BSD 2-Clause License
- **Purpose**: Archive file handling

#### libspeexdsp
- **Copyright**: (c) 2002-2008 Xiph.org Foundation and contributors
- **License**: BSD 3-Clause License
- **Purpose**: Audio processing

#### libsamplerate
- **Copyright**: (c) 2012-2016, Erik de Castro Lopo
- **License**: BSD 2-Clause License
- **Purpose**: Audio sample rate conversion

#### RtMidi
- **Copyright**: (c) 2003-2017 Gary P. Scavone
- **License**: MIT License
- **Purpose**: MIDI I/O

#### RtAudio
- **Copyright**: (c) 2001-2017 Gary P. Scavone
- **License**: MIT License
- **Purpose**: Audio I/O

#### nanovg
- **Copyright**: (c) 2013 Mikko Mononen
- **License**: MIT License
- **Purpose**: Vector graphics rendering

#### nanosvg
- **Copyright**: (c) 2013-14 Mikko Mononen
- **License**: MIT License
- **Purpose**: SVG parsing

#### Blendish
- **Copyright**: (c) 2014 Leonard Ritter
- **License**: MIT License
- **Purpose**: UI styling

#### osdialog
- **Copyright**: Various contributors
- **License**: CC0 1.0 Universal
- **Purpose**: Native dialog boxes

#### pffft
- **Copyright**: (c) 2013 Julien Pommier
- **License**: BSD 3-Clause License
- **Purpose**: FFT implementation

#### fuzzysearchdatabase
- **Copyright**: 2020 Nils Jonas Norberg
- **License**: BSD 3-Clause License
- **Purpose**: Fuzzy search functionality

#### ghc/filesystem
- **Copyright**: (c) 2018, Steffen Schümann
- **License**: MIT License
- **Purpose**: Filesystem operations

#### tinyexpr
- **Copyright**: (c) 2015-2018 Lewis Van Winkle
- **License**: zlib License
- **Purpose**: Mathematical expression parsing

#### simde
- **Copyright**: (c) 2017 Evan Nemerson
- **License**: MIT License
- **Purpose**: SIMD instruction emulation

## License Compliance

This package complies with the GPL-3.0-or-later license by:

1. **Providing Complete Source Code**: All source files used to build this plugin are included
2. **Build Instructions**: Complete build instructions are provided in README.md
3. **Original License Preservation**: All original license notices are maintained
4. **Proper Attribution**: All original authors are properly credited
5. **License Documentation**: This file provides comprehensive license information

## Distribution Requirements

When distributing this software, you must include:

1. **Complete source code** for the plugin
2. **Build instructions** (README.md)
3. **All license files** (this directory)
4. **Original license notices** from all dependencies
5. **Attribution** to all original authors

## Modifications

This MetaModule conversion includes the following modifications from the original trowaSoft-VCV plugin:

1. **OSC Removal**: Open Sound Control functionality has been removed for MetaModule compatibility
2. **UI Adaptation**: Interface elements have been adapted for the MetaModule platform
3. **Build System**: Adapted to use the MetaModule SDK and build system
4. **Memory Optimization**: Code has been optimized for MetaModule's resource constraints

All modifications maintain the original functionality while ensuring compatibility with the MetaModule platform.

## Contact Information

For questions about:
- **Original trowaSoft plugin**: Contact j4s0n-c at trowasoft.vcv@gmail.com
- **MetaModule platform**: Refer to MetaModule documentation
- **This conversion**: No Support Offered

## Full License Texts

Complete license texts for all dependencies are available in the `licenses/` directory:
- `LICENSE-GPLv3.txt` - GNU General Public License v3.0
- `LICENSE-dist.md` - VCV Rack dependency licenses
- `trowaSoft-VCV-README.md` - Original trowaSoft plugin documentation

---

**Note**: This is a community conversion of the original trowaSoft-VCV plugin. The original plugin and its author (j4s0n-c) are not affiliated with this MetaModule conversion. 