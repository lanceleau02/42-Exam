/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:59:47 by laprieur          #+#    #+#             */
/*   Updated: 2023/03/03 14:11:12 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	pgcd(int a, int b)
{
	int	pgcd;

	if (a > b)
		pgcd = a;
	else
		pgcd = b;
	while (1)
	{
		if (a % pgcd == 0 && b % pgcd == 0)
		{
			printf("%d\n", pgcd);
			return ;
		}
		pgcd--;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("\n");
		return (1);
	}
	pgcd(atoi(argv[1]), atoi(argv[2]));
	return (0);
}
