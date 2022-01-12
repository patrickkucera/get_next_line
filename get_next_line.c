/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakucera <pakucera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:38:09 by pakucera          #+#    #+#             */
/*   Updated: 2022/01/12 14:41:30 by pakucera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../../Rank00/libft/libft.h"



# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 22
#endif

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

int main ()
{
	int fd;
	int ret;
	char buffer[BUFFER_SIZE + 1];
	
	fd = open("Text", O_RDONLY);
	if (fd ==-1)
	{
		ft_putstr("open() error");
		return (1);
	}
	while (ret = read(fd, buffer, BUFFER_SIZE))
	{
		buffer[ret] = '\0';
		ft_putnbr(ret);
		ft_putstr(buffer);
	}
	buffer[ret] = '\0';
	ft_putnbr(ret);
	if (close(fd) == -1)
	{
		ft_putstr(buffer);
		return (1);
	}

	return (0);
}