/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:03:36 by grocha-l          #+#    #+#             */
/*   Updated: 2022/06/27 17:05:20 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_atoi(const char *str)
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
