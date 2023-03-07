/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:06:19 by laprieur          #+#    #+#             */
/*   Updated: 2023/03/07 16:39:38 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	/*static char	*buffer = NULL;
	char		*line;
	ssize_t		read_bytes;
	static int	i;
	int	j = 0;
	static int	flip = 0;

	if (!buffer)
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
	}
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		j++;
		i++;
	}
	i++;
	line = malloc(sizeof(char) * j + 1);
	line = ft_strcpy(line, &buffer[flip]);
	flip = i;
	return (line);*/

	char	*buffer;
	static char	*line = NULL;
	ssize_t		read_bytes;

	read_bytes = BUFFER_SIZE;
	while (read_bytes == BUFFER_SIZE && line[i] != '\n')
	{
		if (!buffer)
		{
			buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
			read_bytes = read(fd, buffer, BUFFER_SIZE);
			buffer[read_bytes] = '\0';
		}
		line = join buffer et line
		i++;
	}
}

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int		fd;
	int		i = 1;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
		line = NULL;
		i++;
	}
	printf("%s", line);
	free(line);
	return(0);
}
