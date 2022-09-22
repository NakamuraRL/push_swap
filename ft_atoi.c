/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:03:36 by grocha-l          #+#    #+#             */
/*   Updated: 2022/09/22 08:45:55 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	long	cont;
	int		minus;
	long	ret;

	cont = 0;
	minus = 1;
	ret = 0;
	while (str[cont] == 32 || (str[cont] >= 9 && str[cont] <= 13))
		cont++;
	if (str[cont] == '+' || str[cont] == '-')
	{
		if (str[cont] == '-')
			minus *= -1;
		cont++;
	}
	while (str[cont] >= '0' && str[cont] <= '9')
	{
		ret = ret * 10 + (str[cont] - '0');
		cont++;
	}
	return (ret * minus);
}

long long	ft_atol(const char *str)
{
	long long	result;
	int			sign;
	int			i;

	if (!str)
		return (0);
	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
