/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieure <lprieure@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:17:26 by lprieure          #+#    #+#             */
/*   Updated: 2023/02/25 18:47:09 by lprieure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

int	ft_isalpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

void	search_and_replace(char *str, char search, char replace)
{
	int	i;

	if (ft_isalpha(search) == 0 || ft_isalpha(replace) == 0)
		return ;
	i = 0;
	while (str[i])
	{
		if (str[i] == search)
			str[i] = replace;
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (ft_strlen(argv[2]) > 1 || ft_strlen(argv[3]) > 1)
	{
		ft_putstr(argv[1]);
		write(1, "\n", 1);
		return (0);
	}
	else if (argc != 4)
	{
		write(1, "\n", 1);
		return (1);
	}
	search_and_replace(argv[1], argv[2][0], argv[3][0]);
	return (0);
}
