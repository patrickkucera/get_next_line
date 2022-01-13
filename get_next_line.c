/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakucera <pakucera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:55:26 by pakucera          #+#    #+#             */
/*   Updated: 2022/01/13 13:09:49 by pakucera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int	ft_serline(const char *str, int c)
{
	char	find;
	int		i;

	find = (unsigned char)c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == find)
		{
			printf ("\n%d", i);
			return (i);}
		i++;
	}
	return (0);
}

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	char *ret;
	static char *strlcpy_stock;
	char *line;
	int variable;
	int r;
	int i;

	i = 0;
	if (strlcpy_stock == NULL)
		strlcpy_stock = malloc((10000) * sizeof(char)); 
		
	ret = malloc((BUFFER_SIZE + 1) * sizeof(char)); //enlever par la suite le malloc via un *
	r = read(fd, ret, BUFFER_SIZE);
		
	ft_strlcpy(strlcpy_stock, ret, BUFFER_SIZE +1); 
	
	variable = ft_serline(strlcpy_stock, '\n');
	line = malloc((variable +1 ) * sizeof(char));
	ft_strlcpy(line, strlcpy_stock, variable + 1); 
	
	if (r == 0)
		return (0);
	return(line);
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