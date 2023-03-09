/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:06:19 by laprieur          #+#    #+#             */
/*   Updated: 2023/03/08 16:46:22 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_s;
	int		i;
	int		j;

	new_s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	while (s1 && s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_s[i] = s2[j];
		i++;
		j++;
	}
	if (s1)
		free(s1);
	new_s[i] = '\0';
	return (new_s);
}

int	ft_check_nl(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strcpy_nl(char *dest, char *src)
{
	int	i;

	dest = malloc(sizeof(char) * (ft_check_nl(src) + 2));
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\n';
	dest[i + 1] = '\0';
	return (dest);
}

char	*ft_clear_tmp(char *tmp)
{
	int	i;
	int	j;
	char *new;

	i = 0;
	while (tmp && tmp[i] && tmp[i] != '\n')
		i++;
	i++;
	new = malloc(sizeof(char) * (ft_strlen(tmp) - i + 1));
	j = 0;
	while (tmp && tmp[i])
	{
		new[j] = tmp[i];
		j++;
		i++;
	}
	new[j] = '\0';
	free(tmp);
	tmp = NULL;
	return (new);
}

#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*line = NULL;
	ssize_t		read_bytes;
	static char	*tmp = NULL;
	char	*buffer = NULL;

	read_bytes = BUFFER_SIZE;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buffer[0] = '\0';
	tmp = NULL;
	while (read_bytes <= BUFFER_SIZE && ft_check_nl(buffer) < 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
		if (read_bytes <= 0)
		{
			free(buffer);
			free(tmp);
			tmp = NULL;
			return (NULL);
		}
		tmp = ft_strjoin(tmp, buffer);
	}
	line = ft_strcpy_nl(line, tmp);
	tmp = ft_clear_tmp(tmp);
	free(buffer);
	return (line);
}

#include <fcntl.h>

int main(void)
{
	int		fd;
	int		i = 1;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("i = %d et %s", i, line);
		free(line);
		line = NULL;
		i++;
	}
	printf("%s", line);
	free(line);
	return(0);
}
