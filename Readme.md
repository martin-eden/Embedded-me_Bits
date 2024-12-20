## What

(2024-10)

Bits access. Arduino library. In growing.

Currently there's only set-bit/get-bit functions for bytes.
I can write `v & ~(5 << 1) >> 5`, no worries. But I don't like it.

## Code

* [Example][Example]
* [Interface][Interface]
* [Implementation][Implementation]

## Requirements

  * arduino-cli
  * bash

## Install/remove

Easy way is to clone [GetLibs][GetLibs] repo and run it's code.

## Compile

Zero-warnings compilation:

```bash
arduino-cli compile --fqbn arduino:avr:uno --quiet --warnings all . --build-property compiler.cpp.extra_flags="-std=c++1z"
```

## See also

* [My other embedded C++ libraries][Embedded]
* [My other repositories][Repos]

[Example]: examples/me_Bits/me_Bits.ino
[Interface]: src/me_Bits.h
[Implementation]: src/me_Bits.cpp

[GetLibs]: https://github.com/martin-eden/Embedded-Framework-GetLibs

[Embedded]: https://github.com/martin-eden/Embedded_Crafts/tree/master/Parts
[Repos]: https://github.com/martin-eden/contents
