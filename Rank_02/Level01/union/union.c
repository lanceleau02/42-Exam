/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:17:50 by laprieur          #+#    #+#             */
/*   Updated: 2023/02/28 12:08:40 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_union(char *s1, char *s2)
{
	int	i;
	int	seen[128] = {0};

	i = 0;
	while (s1[i])
	{
		if (seen[(int)s1[i]] == 0)
		{
			seen[(int)s1[i]] = 1;
			write(1, &s1[i], 1);
		}
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (seen[(int)s2[i]] == 0)
		{
			seen[(int)s2[i]] = 1;
			write(1, &s2[i], 1);
		}
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
	ft_union(argv[1], argv[2]);
	return (0);
}
