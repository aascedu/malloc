#include "libft_malloc.h"
#include <stdio.h>

t_heap  my_heap;

t_zone  *get_page(size_t size)
{
    printf("%ld\n", TINY_SIZE);
    if (size > (size_t)SMALL_SIZE)
        return get_large_page(size);
    else if (size <= (size_t)TINY_SIZE)
        return find_available_page(TINY_HEAP_SIZE, &my_heap.tiny_zones);
    return NULL;
}

t_block	*get_block(size_t size, t_zone *page)
{
	if (size <= (size_t)TINY_SIZE)
		return find_available_block(TINY_SIZE, page);
	return NULL;
}	

void    *ft_malloc(size_t size)
{
    t_zone 	*page = NULL;
    t_block	*block = NULL;
    page = get_page(size);
    if (page == NULL)
        return NULL;
    block = get_block(size, page);
    if (block == NULL)
    	return NULL;
    return block; // block is the addr of the beginning of the block
}
