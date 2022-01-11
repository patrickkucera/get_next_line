/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakucera <pakucera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:38:09 by pakucera          #+#    #+#             */
/*   Updated: 2022/01/11 15:38:32 by pakucera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif

int main ()
{
	char buffer[BUFFER_SIZE + 1];
	
	read("text", buffer, BUFFER_SIZE); 
	printf("%s", buffer);
	return (0);
}