/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieure <lprieure@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:44:23 by lprieure          #+#    #+#             */
/*   Updated: 2023/02/26 18:07:42 by lprieure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (unsigned char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
}

void	inter(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (ft_strchr(s2, s1[i]) != NULL && ft_strchr(s1, s1[i]) == s1 + i)
			write(1, &s1[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	inter(argv[1], argv[2]);
	return (0);
}
