# ostep-utilities

C implementations of the OSTEP utilities projects — wcat, wgrep, wzip and others.

## Projects

* [wcat](./wcat): implementation of the Linux `cat` command in C
* [wgrep](./wgrep): implementation of the Linux `grep` command in C
* [wzip](./wzip): implementation of a simple file compression tool in C
* [wunzip](./wunzip): implementation of a simple file decompression tool in C

## Building

Each utility has its own directory. To build any of them:

```bash
cd <utility>
gcc -o <utility> <utility>.c -Wall -Werror
```

## Reference

Based on the [OSTEP Projects](https://github.com/remzi-arpacidusseau/ostep-projects) by Remzi Arpaci-Dusseau.