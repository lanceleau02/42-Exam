/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:57:47 by laprieur          #+#    #+#             */
/*   Updated: 2023/03/03 12:06:54 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	wdmatch(char *s1, char *s2)
{
	int		i;
	int		j;
	char	str[10000];

	i = 0;
	j = 0;
	while (s1[i])
	{
		while (s2[j])
		{
			if (s1[i] == s2[j])
			{
				str[i] = s1[i];
				break ;
			}
			j++;
		}
		i++;
	}
	if (ft_strcmp(s1, str) == 0)
		ft_putstr(s1);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	wdmatch(argv[1], argv[2]);
	return (0);
}
