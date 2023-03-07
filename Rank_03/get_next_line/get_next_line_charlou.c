#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
	str = malloc(pilelen + buflen +1);
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

	pile = malloc(1);
	pile[0] = '\0';
	if (!buf)
		buf = malloc(BUFFER_SIZE + 1);
	buf[0] = '\0';
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