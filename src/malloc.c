#include "libft_malloc.h"

#include <stdio.h>

int ft_malloc(size_t size)
{
    (void)size;
    long int tiny_size;

    tiny_size = TINY_SIZE;
    int pagesize;
    pagesize = sysconf(_SC_PAGESIZE);
    printf("%d\n", pagesize);
    return tiny_size + pagesize;
}