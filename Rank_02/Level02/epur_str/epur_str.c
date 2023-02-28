/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:29:14 by laprieur          #+#    #+#             */
/*   Updated: 2023/02/28 15:53:01 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	epur_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		if (str[i + 1] && (str[i] == ' ' || str[i] == '\t'))
		{
			while (str[i + 1] && (str[i] == ' ' || str[i] == '\t'))
				i++;
			if (str[i + 1] != '\0')
				write(1, " ", 1);
		}
		if (str[i] != ' ' && str[i] != '\t')
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
	epur_str(argv[1]);
	return (0);
}
