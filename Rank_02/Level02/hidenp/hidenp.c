/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:45:39 by laprieur          #+#    #+#             */
/*   Updated: 2023/03/01 16:59:43 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	char_is_in_str(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	hidenp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (char_is_in_str(s1[i], s2) == 0)
		{
			write(1, "0\n", 2);
			return ;
		}
		i++;
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
