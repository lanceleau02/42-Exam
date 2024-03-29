/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieure <lprieure@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:59:48 by lprieure          #+#    #+#             */
/*   Updated: 2023/03/09 14:57:30 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

void	rstr_capitalizer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') && ft_isalpha(str[i + 1]) == 1)
			str[i] += 32;
		else if ((str[i] >= 'a' && str[i] <= 'z')
			&& (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
			str[i] -= 32;
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		rstr_capitalizer(argv[i]);
		++i;
	}
	return (0);
}
