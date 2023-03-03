/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:29:18 by laprieur          #+#    #+#             */
/*   Updated: 2023/03/03 12:33:15 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	if (nbr < 10)
		ft_putchar(nbr + '0');
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
	{
		write(1, "0\n", 2);
		return (1);
	}
	ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}
