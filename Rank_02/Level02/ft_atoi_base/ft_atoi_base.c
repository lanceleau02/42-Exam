/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:04:53 by laprieur          #+#    #+#             */
/*   Updated: 2023/03/01 10:33:38 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_blank(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	base(int c, int str_base)
{
	int		i;
	char	base_maj[] = "0123456789ABCDEF";
	char	base_min[] = "0123456789abcdef";

	i = 0;
	while (i < str_base)
	{
		if (c == base_maj[i] || c == base_min[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	while (ft_is_blank(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	nb = 0;
	while (base(str[i], str_base) != -1)
	{
		nb *= str_base;
		nb += base(str[i], str_base);
		i++;
	}
	nb *= sign;
	return (nb);
}
