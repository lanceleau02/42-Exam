/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieure <lprieure@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 12:01:16 by lprieure          #+#    #+#             */
/*   Updated: 2023/03/07 12:04:32 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
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
	while (s1[i])
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
	free (s1);
	new_s[i] = '\0';
	return (new_s);
}

int	ft_check_line(char *line, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			j = 0;
			buffer[j++] = line[++i];
			if (line[i] == '\0')
				return (1);
			line[i++] = '\0';
			while (line[i])
				buffer[j++] = line[i++];
			buffer[j] = '\0';
			return (1);
		}
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	ssize_t		bytes_read;

	line = malloc(1);
	line[0] = '\0';
	if (!buffer)
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	buffer[0] = '\0';
	buffer[BUFFER_SIZE] = '\0';
	while (1)
	{
		line = ft_strjoin(line, buffer);
		if (ft_check_line(line, buffer) == 1)
			return (line);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 1)
		{
			free (buffer);
			buffer = NULL;
			if (line[0] != '\0')
				return (line);
			free (line);
			line = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
	}
}
