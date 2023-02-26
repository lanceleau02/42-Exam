/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieure <lprieure@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:51:23 by lprieure          #+#    #+#             */
/*   Updated: 2023/02/26 15:01:42 by lprieure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	do_op(int nb1, int nb2, char operator)
{
	if (operator == '+')
		printf("%d\n", nb1 + nb2);
	else if (operator == '-')
		printf("%d\n", nb1 - nb2);
	else if (operator == '*')
		printf("%d\n", nb1 * nb2);
	else if (operator == '/')
		printf("%d\n", nb1 / nb2);
	else if (operator == '%')
		printf("%d\n", nb1 % nb2);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		printf("\n");
		return (1);
	}
	do_op(atoi(argv[1]), atoi(argv[3]), argv[2][0]);
	return (0);
}
