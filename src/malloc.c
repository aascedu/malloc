#include "libft_malloc.h"

t_heap  my_heap;

t_zone *find_available_page(size_t size, t_zone **zones)
{
    t_zone  *zone = *zones;
    while (zone)
    {
        if (zone->size_available > 0)
            return zone;
        if (zone->next != NULL)
            zone = zone->next;
    }

    t_zone  *new_zone;
    new_zone = mmap(NULL, size, PROT_READ | PROT_WRITE, \
                    MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (new_zone == MAP_FAILED)
    {
        ft_putstr_fd("mmap() returned MAP_FAILED\n", 2);
        return NULL;
    }
    new_zone->size_total = size;
    new_zone->size_available = size - sizeof(t_zone);
    ft_memset(new_zone, 0, sizeof(t_zone));
    return new_zone;
}

t_zone  *get_large_page(size_t size)
{
    (void)size;
    return NULL;
}

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
    return NULL;
}