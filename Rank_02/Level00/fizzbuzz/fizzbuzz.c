/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieure <lprieure@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:35:12 by lprieure          #+#    #+#             */
/*   Updated: 2023/02/25 15:49:34 by lprieure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	fizzbuzz(void)
{
	int	nb;

	nb = 1;
	while (nb <= 100)
	{
		if (nb % 3 == 0 && nb % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (nb % 3 == 0)
			write(1, "fizz", 4);
		else if (nb % 5 == 0)
			write(1, "buzz", 4);
		else if (nb > 10)
		{
			ft_putchar((nb / 10) + '0');
			ft_putchar((nb % 10) + '0');
		}
		else
			ft_putchar(nb + '0');
		write(1, "\n", 1);
		nb++;
	}
}

int	main(void)
{
	fizzbuzz();
	return (0);
}
