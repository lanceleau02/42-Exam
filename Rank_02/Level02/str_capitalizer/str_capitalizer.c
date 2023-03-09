/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:30:16 by laprieur          #+#    #+#             */
/*   Updated: 2023/03/09 17:05:42 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

void	str_capitalizer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i - 1] == ' ' || str[i - 1] == '\t')
			&& (str[i] >= 'a' && str[i] <= 'z')
			&& ft_isalpha(str[i + 1]) == 1)
			str[i] -= 32;
		else if ((str[i] >= 'A' && str[i] <= 'Z') && (ft_isalpha(str[i + 1]) == 1 || str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
			str[i] += 32;
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
