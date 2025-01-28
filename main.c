#include "libft_malloc.h"

int main(void)
{
    void *m = malloc(1);
    if (m == NULL)
        return 1;
    return 0;
}