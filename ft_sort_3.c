/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:40:42 by grocha-l          #+#    #+#             */
/*   Updated: 2022/09/22 21:07:28 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_change_list(t_list *list_a, int *index)
{
	int	size;
	int	i;

	size = 0;
	while (size != list_a->size)
	{
		i = 0;
		while (list_a->begin->nbr != index[i])
		{
			i++;
		}
		list_a->begin->nbr = i + 1;
		ft_rotate(list_a);
		size++;
	}
	return ;
}

void	ft_h1_or_h2(t_list *list_a, t_list *list_b, int hold_1, int hold_2)
{
	int	ind_1;
	int	ind_2;

	ind_1 = ft_get_index(list_a, hold_1);
	ind_2 = ft_get_index(list_a, hold_2);
	while (ind_1)
	{
		if (ind_1 <= list_a->size - ind_2)
		{
			while (list_a->begin->nbr != hold_1)
			{
				ft_ra(list_a);
			}
			break ;
		}
		if (ind_1 > list_a->size - ind_2)
		{
			while (list_a->begin->nbr != hold_2)
			{
				ft_rra(list_a);
			}
			break ;
		}
	}
	ft_pb(list_a, list_b);
}

void	ft_push_in_order(t_list *list_a, t_list *list_b)
{
	if (list_b->size < 2)
	{
		ft_pb(list_a, list_b);
		return ;
	}
	ft_pb(list_a, list_b);
}

int		ft_is_sorted(t_list *list_a)
{
	int		size;
	t_stack	*node;

	size = list_a->size;
	node = list_a->begin;
	while (size != 1)
	{
		if (node->nbr > node->next->nbr)
		{
			return (0);
		}
		node = node->next;
		size--;
	}
	return (1);
}
