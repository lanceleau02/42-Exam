/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieure <lprieure@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:17:33 by lprieure          #+#    #+#             */
/*   Updated: 2023/02/25 19:35:07 by lprieure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	camel_to_snake(char *str)
{
	int	i;

	if (str[0] <= 'a' && str[0] >= 'z')
		return ;
	i = 0;
	while (str[i])
	{
		if (str[i + 1] >= 'A' && str[i + 1] <= 'Z')
		{
			write(1, &str[i], 1);
			write(1, "_", 1);
			i++;
		}
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
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
	camel_to_snake(argv[1]);
	return (0);
}
