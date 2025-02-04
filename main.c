#include "libft_malloc.h"

int main(void)
{
    void *m = ft_malloc(1);
    (void)m;
    m = ft_malloc(127);
    return 0;
}