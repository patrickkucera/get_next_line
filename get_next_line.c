/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakucera <pakucera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:55:26 by pakucera          #+#    #+#             */
/*   Updated: 2022/01/13 10:58:04 by pakucera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../../Rank00/libft/libft.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;

	while (str[i])
	{
		ft_putchar(str[i]);
		i += 1;
	}
}

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
#endif

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{	
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	find;
	int		i;

	find = (unsigned char)c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == find)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == find)
		return ((char *)str + i);
	return (0);
}

char	*get_next_line(int fd)
{
	char *ret;
	char *strlcpy_dst;
	int r;
	int i;

	strlcpy_dst = malloc((10000) * sizeof(char)); 
	ret = malloc((BUFFER_SIZE + 1) * sizeof(char)); 
	r = read(fd, ret, BUFFER_SIZE);
	i = 0;
	
	ft_strlcpy(strlcpy_dst, ret,BUFFER_SIZE); 
	ft_strchr(strlcpy_dst, '\n');
	if (&ft_strchr != 0)
	{
		//printf ("gnl %s", strlcpy_dst);
	}
	if (r == 0)
		return (0);
	return(strlcpy_dst);
}




int main ()
{
	int fd;
	char *ret;
			
	fd = open("Text", O_RDONLY);
	ret = (char *)1;
	if (fd == -1)
	{
		ft_putstr("open() error");
		return (1);
	}
	while (ret != NULL)
	{
		ret = get_next_line (fd);
		printf ("%s", ret);
	}
	return (0);
}