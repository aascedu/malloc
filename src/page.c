#include "libft_malloc.h"

void	add_page_to_global(size_t size, t_zone *new_zone, t_zone *zone)
{
	(void)size;
	(void)new_zone;
	(void)zone;
	return;	
}

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
    add_page_to_global(size, new_zone, *zones);
    return new_zone;
}

t_zone  *get_large_page(size_t size)
{
    (void)size;
    return NULL;
}

