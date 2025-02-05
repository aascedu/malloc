#ifndef LIBFT_MALLOC_H
# define LIBFT_MALLOC_H

# include <sys/mman.h>
# include <unistd.h>
# include <stdbool.h>

void    *ft_malloc(size_t size);

int     ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);
void	*ft_memset(void *s, int c, size_t len);

typedef struct s_heap t_heap;
typedef struct s_zone t_zone;
typedef struct s_block t_block;

// page.c
void	add_page_to_global(size_t size, t_zone *new_zone, t_zone *zone);
t_zone	*find_available_page(size_t size, t_zone **zones);
t_zone	*get_large_page(size_t size);

struct s_block {
    t_block *prev;
    t_block *next;
    size_t  size;
    bool    free;
};

struct s_zone {
    t_zone *prev;
    t_zone *next;
    size_t  size_total;
    size_t  size_available;
    t_block *blocks;
};

struct s_heap {
    t_zone *tiny_zones;
    t_zone *small_zones;
    t_zone *large_zones;
};

# define TINY_HEAP_SIZE (4 * sysconf(_SC_PAGESIZE))
# define TINY_SIZE (TINY_HEAP_SIZE / 128)
# define SMALL_HEAP_SIZE (16 * sysconf(_SC_PAGESIZE))
# define SMALL_SIZE (SMALL_HEAP_SIZE / 128)

#endif
