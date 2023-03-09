#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	nl_idx(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-2);
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (-1);
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	if (s1)
		free(s1);
	return (str);
}

char	*clear_and_return(char *line, int code)
{
	int		i;
	int		nl;
	char	*out;

	i = 0;
	nl = nl_idx(line);
	if (nl >= 0)
	{
		if (code == 0)
		{
			out = malloc(sizeof(char) * (nl + 2));
			while (i <= nl)
			{
				out[i] = line[i];
				i++;
			}
			out[i] = '\0';
		}
		else
		{
			i = nl + 1;
			out = malloc(sizeof(char) * (ft_strlen(line) - nl + 2));
			while (i < ft_strlen(line))
			{
				out[i - (nl + 1)] = line[i];
				i++;
			}
			free(line);
			out[i - (nl + 1)] = '\0';
		}
		return (out);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*out;
	static char	*line;
	char		*buf;
	ssize_t		read_bytes;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	read_bytes = BUFFER_SIZE;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	buf[0] = '\0';
	while (read_bytes <= BUFFER_SIZE && nl_idx(buf) < 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		line = ft_strjoin(line, buf);
	}
	free(buf);
	if (nl_idx(line) == -1)
		return (line);
	out = clear_and_return(line, 0);
	line = clear_and_return(line, 1);
	return (out);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}
