/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:11:39 by laprieur          #+#    #+#             */
/*   Updated: 2023/02/28 14:27:58 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_prime(int nb)
{
	int	i;

	if (nb == 2)
		return (1);
	else if (nb <= 1 || nb % 2 == 0)
		return (0);
	i = 3;
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_atoi(char *nptr)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	nb = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = (nb * 10) + (nptr[i] - '0');
		i++;
	}
	nb = nb * sign;
	return (nb);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	if (nb < 10)
		ft_putchar(nb + '0');
}

void	add_prime_sum(int nb)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < nb)
	{
		if (ft_is_prime(i) == 1)
			res += i;
		i++;
	}
	ft_putnbr(res + nb);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || ft_atoi(argv[1]) < 0)
	{
		write(1, "0\n", 2);
		return (1);
	}
	add_prime_sum(ft_atoi(argv[1]));
	return (0);
}
