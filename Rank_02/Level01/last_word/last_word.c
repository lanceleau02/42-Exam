/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieure <lprieure@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:22:15 by lprieure          #+#    #+#             */
/*   Updated: 2023/02/26 18:39:15 by lprieure         ###   ########.fr       */
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

void	last_word(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i > 0 && (str[i] == ' ' || str[i] == '\t'))
		i--;
	while (i > 0 && str[i] != ' ' && str[i] != '\t')
		i--;
	i++;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	last_word(argv[1]);
	return (0);
}
