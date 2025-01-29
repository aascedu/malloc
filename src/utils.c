#include "libft_malloc.h"

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

void	*ft_memset(void *s, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)s)[i] = (char)c;
		i++;
	}
	return (s);
}