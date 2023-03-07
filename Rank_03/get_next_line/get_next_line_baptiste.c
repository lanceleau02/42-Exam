/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieure <lprieure@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 12:01:16 by lprieure          #+#    #+#             */
/*   Updated: 2023/03/07 14:05:50 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(int size)
{
	int		i;
	char	*s;

	s = malloc(sizeof(char) * size);
	i = 0;
	while (i < size)
	{
		s[i] = 0;
		i++;
	}
	return (s);
}

char	*ft_strjoin(char *pile, char *buf)
{
	size_t	i;
	char	*str;
	int		pilelen;
	int		buflen;

	i = 0;
	pilelen = ft_strlen(pile);
	buflen = ft_strlen(buf);
	str = NULL;
	while (!str)
		str = ft_calloc(pilelen + buflen + 1);
	while (pile[i])
	{
		str[i] = pile[i];
		i++;
	}
	while (buf[i - pilelen])
	{
		str[i] = buf[i - pilelen];
		i++;
	}
	free(pile);
	str[i] = '\0';
	return (str);
}

int	ft_endline(char *pile, char *buf)
{
	int		i;
	int		j;

	i = 0;
	while (pile[i])
	{
		if (pile[i] == '\n')
		{
			j = 0;
			buf[j++] = pile[++i];
			if (pile[i] == '\0')
				return (1);
			pile[i++] = '\0';
			while (pile[i])
				buf[j++] = pile[i++];
			buf[j] = '\0';
			return (1);
		}
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	ssize_t			buflen;
	static char		*buf = NULL;
	char			*pile;

	pile = ft_calloc(1);
	if (!buf)
		buf = ft_calloc(BUFFER_SIZE + 1);
	while (1)
	{
		pile = ft_strjoin(pile, buf);
		if (ft_endline(pile, buf) != 0)
			return (pile);
		buflen = read(fd, buf, BUFFER_SIZE);
		if (buflen < 1)
		{
			free(buf);
			buf = NULL;
			if (pile[0])
				return (pile);
			free(pile);
			return (NULL);
		}
		buf[buflen] = '\0';
	}
}
