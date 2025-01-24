#ifndef LIBFT_MALLOC_H
# define LIBFT_MALLOC_H

# include <sys/mman.h>
# include <unistd.h>

# define MAP_FAILED (void *)-1

void    *malloc(site_t size);

#endif