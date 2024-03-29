/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:45:39 by laprieur          #+#    #+#             */
/*   Updated: 2023/03/03 12:16:14 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hidenp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		while (s2[j] && s1[i] != s2[j])
			j++;
		if (s2[j] == '\0')
		{
			write(1, "0\n", 2);
			return ;
		}
		i++;
		j++;
	}
	write(1, "1\n", 2);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	hidenp(argv[1], argv[2]);
	return (0);
}
