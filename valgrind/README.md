## Valgrind Memory Leak Detection

Install `valgrind` and the debug packages for all dependencies like
`glibc` and `libreadline`.

Use the following command to check for memory leaks:
```
valgrind --leak-check=full --show-reachable=yes --suppressions=valgrind/suppressions.txt <command>
```

Scanmem uses `libreadline` and that library does not have a proper cleanup
function. So leak reporting is suppressed for functions known for leaking
memory only once which is needed until process termination.
This avoids false-positives.

Link to a good Valgrind tutorial:
https://wiki.blender.org/wiki/Tools/Debugging/Valgrind
