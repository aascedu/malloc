# malloc
Slab Allocator using mmap and munmap system calls.

## How to compile ?
On Linux :
  `make`

With Docker :

-  `./launch.sh` 
-  `make -j` to compile only the lib, `make -j test` to compile a test program in addition.

To use gdb :

- `gdb ./test`
- `set environment LD_PRELOAD lib/libft_malloc.so`
