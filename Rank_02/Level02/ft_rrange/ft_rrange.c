/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:21:08 by laprieur          #+#    #+#             */
/*   Updated: 2023/03/01 16:01:29 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long int	define_tab_size(int start, int end)
{
	long int	long_start;
	long int	long_end;
	long int	size;

	long_start = (long int)start;
	long_end = (long int)end;
	if (long_end > long_start)
		size = long_end - long_start;
	else
		size = long_start - long_end;
	return (size);
}

int	*ft_rrange(int start, int end)
{
	long int	tab_size;
	int			*tab;
	long int	i;

	tab_size = define_tab_size(start, end);
	tab = malloc(sizeof(int) * tab_size);
	i = 0;
	if (end > start)
	{
		while (end >= start)
		{
			tab[i] = end;
			end--;
			i++;
		}
	}
	else
	{
		while (end <= start)
		{
			tab[i] = end;
			end++;
			i++;
		}
	}
	return (tab);
}
