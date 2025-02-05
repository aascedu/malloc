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
    t_zone *page = NULL;

    page = get_page(size);
    if (page == NULL)
        return NULL;
    return page;
}
