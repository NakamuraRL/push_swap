/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:43:04 by grocha-l          #+#    #+#             */
/*   Updated: 2022/09/21 15:41:54 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_list *list_a, t_list *list_b)
{
	if (list_a->size == 2)
	{
		if (list_a->begin->nbr > list_a->end->nbr)
		{
			ft_sa(list_a);
		}
	}
	if (list_a->size == 3)
	{
		ft_sort_3(list_a);
	}
	if (list_a->size > 3 && list_a->size <= 5)
	{
		ft_sort_5(list_a, list_b);
	}
	if (list_a->size > 5 && list_a->size <= 100)
	{
		ft_sort_100(list_a, list_b);
	}
	if (list_a->size > 100 && list_a->size <= 500)
	{
		ft_sort_500(list_a, list_b);
	}
}

void	ft_sort_3(t_list *list_a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = list_a->begin->nbr;
	n2 = list_a->begin->next->nbr;
	n3 = list_a->end->nbr;
	if (n1 > n2 && n2 > n3 && n1 > n3)
	{
		ft_sa(list_a);
		ft_rra(list_a);
	}
	if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		ft_sa(list_a);
		ft_ra(list_a);
	}
	if (n1 > n2 && n2 < n3 && n1 < n3)
		ft_sa(list_a);
	if (n1 > n2 && n2 < n3 && n1 > n3)
		ft_ra(list_a);
	if (n1 < n2 && n2 > n3 && n1 > n3)
		ft_rra(list_a);
}

void	ft_sort_5(t_list *list_a, t_list *list_b)
{
	int	x;

	if (list_a->size == 5)
		ft_pb(list_a, list_b);
	ft_pb(list_a, list_b);
	ft_sort_3(list_a);
	x = 2;
	ft_final_sort(list_a, list_b, x);
}

void	ft_sort_100(t_list *list_a, t_list *list_b)
{
	int	size;

	ft_change_list(list_a, ft_ordered_index(list_a));
	while (list_a->size != 0)
		ft_push_chunk(list_a, list_b);
	ft_pa(list_a, list_b);
	ft_pa(list_a, list_b);
	ft_pa(list_a, list_b);
	ft_sort_3(list_a);
	size = list_b->size;
	ft_final_sort(list_a, list_b, size);
}

void	ft_sort_500(t_list *list_a, t_list *list_b)
{
	int	size;

	ft_change_list(list_a, ft_ordered_index(list_a));
	while (list_a->size != 0)
	{
		ft_push_chunk(list_a, list_b);
	}
	ft_pa(list_a, list_b);
	ft_pa(list_a, list_b);
	ft_pa(list_a, list_b);
	ft_sort_3(list_a);
	size = list_b->size;
	ft_final_sort(list_a, list_b, size);
}
