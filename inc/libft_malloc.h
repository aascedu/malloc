#ifndef LIBFT_MALLOC_H
# define LIBFT_MALLOC_H

# include <sys/mman.h>
# include <unistd.h>

void    *ft_malloc(size_t size);

# define TINY_HEAP_SIZE (4 * sysconf(_SC_PAGESIZE))
# define TINY_SIZE (TINY_HEAP_ALLOC_SIZE / 64)
# define SMALL_HEAP_SIZE (16 * sysconf(_SC_PAGESIZE))
# define SMALL_SIZE (SMALL_HEAP_SIZE / 128)

typedef struct s_heap t_heap;
typedef struct s_block t_block;

struct s_heap {
    t_heap  *prev;
    t_heap  *next;
    size_t  size;
}

struct s_block {
    t_block *prev;
    t_block *next;
    size_t  size;
    bool    free;
}

#endif