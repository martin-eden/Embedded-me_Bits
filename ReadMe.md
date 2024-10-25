# What

(2024-10)

Bits access. Arduino library. In growing.

Currently there's only set-bit/get-bit functions for bytes.
I can write `v & ~(5 << 1) >> 5`, no worries. But I don't like it.

## Requirements

  * arduino-cli
  * bash


## Install

Run [Install.sh](Install.sh).


## Remove

Run [Remove.sh](Remove.sh).


# Compile

Zero-warnings compilation:

```bash
arduino-cli compile --fqbn arduino:avr:uno --quiet --warnings all . --build-property compiler.cpp.extra_flags="-std=c++1z"
```

# Code

* [Example][Example]
* [Interface][Interface]
* [Implementation][Implementation]


# See also

* [My other embedded C++ libraries][Embedded]
* [My other repositories][Repos]

[Example]: examples/me_Bits/me_Bits.ino
[Interface]: src/me_Bits.h
[Implementation]: src/me_Bits.cpp

[Embedded]: https://github.com/martin-eden/Embedded_Crafts/tree/master/Parts
[Repos]: https://github.com/martin-eden/contents
