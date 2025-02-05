#include "libft_malloc.h"

t_heap  my_heap;

t_zone  *get_page(size_t size)
{
    if (size > (size_t)SMALL_SIZE)
        return get_large_page(size);
    else if (size <= (size_t)TINY_SIZE)
        return find_available_page(TINY_HEAP_SIZE, &my_heap.tiny_zones);
    return NULL;
}

void    *ft_malloc(size_t size)
{
    t_zone 	*page = NULL;
    t_block	*block = NULL;
    page = get_page(size);
    if (page == NULL)
        return NULL;
    // Start working on this block = get_block(size);
    // if (block == NULL)
    //		return NULL;
    //	return block; // block is the addr of the beginning of the block
    return page;
}
