/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieure <lprieure@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:15:03 by lprieure          #+#    #+#             */
/*   Updated: 2023/02/25 16:31:25 by lprieure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char c, char *alphabet)
{
	int	i;

	i = 0;
	while (alphabet[i])
	{
		if (alphabet[i] == c)
			break ;
		i++;
	}
	while (i >= 0)
	{
		write(1, &c, 1);
		i--;
	}
}

void	repeat_alpha(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			print(str[i], "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
		else if (str[i] >= 'a' && str[i] <= 'z')
			print(str[i], "abcdefghijklmnopqrstuvwxyz");
		else
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
	repeat_alpha(argv[1]);
	return (0);
}
