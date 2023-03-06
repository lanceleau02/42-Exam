/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieure <lprieure@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 12:01:16 by lprieure          #+#    #+#             */
/*   Updated: 2023/03/06 17:02:24 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_s;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new_s == NULL)
		return (NULL);
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
	new_s[i] = '\0';
	return (new_s);
}

static int	ft_check_line(char *line)
{
	
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	ssize_t		readed_bytes;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer = NULL)
		return (NULL);
	while (1)
	{
		line = ft_strjoin(line, buffer);
		if (ft_check_line(line) == 1)
			return (line);
		readed_bytes = read(fd, buffer, BUFFER_SIZE);
		if (readed_bytes < 1)
		{
			free (buffer);
			buffer = NULL;
			if (line[0] != '\0')
				return (line);
			free (line);
			line = NULL;
			return (NULL);
		}
		buffer[readed_bytes] = '\0';
	}
}
