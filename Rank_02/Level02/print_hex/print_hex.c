/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieure <lprieure@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:39:20 by lprieure          #+#    #+#             */
/*   Updated: 2023/03/04 18:50:37 by lprieure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	nbr;

	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	nbr = nbr * sign;
	return (nbr);
}

void	print_hex(int nb)
{
	char	base[] = "0123456789abcdef";

	if (nb >= 16)
		print_hex(nb / 16);
	write(1, &base[nb % 16], 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}
