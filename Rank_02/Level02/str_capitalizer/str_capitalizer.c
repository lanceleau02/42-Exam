/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:30:16 by laprieur          #+#    #+#             */
/*   Updated: 2023/03/10 14:30:30 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isalpha_blank(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	if (c == ' ' || c == '\t')
		return (2);
	return (0);
}

void	str_capitalizer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((ft_isalpha_blank(str[i - 1]) == 0
				|| ft_isalpha_blank(str[i - 1]) == 1)
			&& (str[i] >= 'A' && str[i] <= 'Z')
			&& (ft_isalpha_blank(str[i + 1]) == 1
				|| ft_isalpha_blank(str[i + 1]) == 2 || str[i + 1] == '\0'))
			str[i] += 32;
		else if ((i == 0 || ft_isalpha_blank(str[i - 1]) == 2)
			&& (str[i] >= 'a' && str[i] <= 'z')
			&& (ft_isalpha_blank(str[i + 1]) == 1 || str[i + 1] == '\0'
				|| i == 0))
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
		str_capitalizer(argv[i]);
		++i;
	}
	return (0);
}
