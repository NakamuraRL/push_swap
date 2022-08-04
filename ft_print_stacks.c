/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:40:01 by grocha-l          #+#    #+#             */
/*   Updated: 2022/07/29 12:35:36 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stacks(t_list *list_a, t_list *list_b)
{
	int		size;
	t_stack	*nbr_a;
	t_stack	*nbr_b;

	size = list_a->size;
	nbr_a = list_a->begin;
	nbr_b = list_b->begin;
	if (list_a->size > list_b->size)
	{
		size = list_a->size;
	}
	if (list_a->size < list_b->size)
	{
		size = list_b->size;
	}
	write(1, "A   B\n", 6);
	write(1, "-----\n", 6);
	while (size > 0)
	{
		if (!nbr_a)
		{
			write(1, " ", 1);
		}
		if (nbr_a)
		{
			ft_putnbr(nbr_a->nbr);
			nbr_a = nbr_a->next;
		}
		write(1, " | ", 3);
		if (!nbr_b)
		{
			write(1, " ", 1);
		}
		if (nbr_b)
		{
			ft_putnbr(nbr_b->nbr);
			nbr_b = nbr_b->next;
		}
		write(1, "\n", 1);
		size--;
	}
}
