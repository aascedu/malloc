# malloc
Slab Allocator using mmap and munmap system calls.

## Comment compiler la lib ?
Sous Linux :
  `make`

Sous Docker :

-  `./launch.sh` 
-  `make -j` pour compiler la lib uniquement, `make -j test` pour compiler un programme de test.

Pour utiliser gdb :

- `gdb ./test`
- `set environment LD_PRELOAD lib/libft_malloc.so`
