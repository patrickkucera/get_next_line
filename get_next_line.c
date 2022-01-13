/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakucera <pakucera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:55:26 by pakucera          #+#    #+#             */
/*   Updated: 2022/01/13 12:12:32 by pakucera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif

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
	
	ft_strlcpy(strlcpy_dst, ret,BUFFER_SIZE +1); 
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
		printf ("| %s", ret);
	}
	return (0);
}