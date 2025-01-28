#ifndef LIBFT_MALLOC_H
# define LIBFT_MALLOC_H

# include <sys/mman.h>
# include <unistd.h>
# include <stdbool.h>

void    *malloc(size_t size);

# define TINY_HEAP_SIZE (4 * sysconf(_SC_PAGESIZE))
# define TINY_SIZE (TINY_HEAP_SIZE / 64)
# define SMALL_HEAP_SIZE (16 * sysconf(_SC_PAGESIZE))
# define SMALL_SIZE (SMALL_HEAP_SIZE / 128)

typedef struct s_heap t_heap;
typedef struct s_pages t_pages;
typedef struct s_block t_block;

struct s_block {
    t_block *prev;
    t_block *next;
    size_t  size;
    bool    free;
};

struct s_pages {
    t_pages *prev;
    t_pages *next;
    size_t  page_size;
    t_block *blocks;
};

struct s_heap {
    t_pages *tiny_pages;
    t_pages *small_pages;
    t_pages *large_pages;
};

#endif