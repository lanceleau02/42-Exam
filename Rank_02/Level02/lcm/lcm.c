/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:20:49 by laprieur          #+#    #+#             */
/*   Updated: 2023/03/03 12:28:28 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	lcm;

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		lcm = a;
	else
		lcm = b;
	while (1)
	{
		if (lcm % a == 0 && lcm % b == 0)
			return (lcm);
		lcm++;
	}
}
