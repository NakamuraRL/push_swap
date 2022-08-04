/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:43:04 by grocha-l          #+#    #+#             */
/*   Updated: 2022/08/03 16:25:24 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check(t_list *list_a, t_list *list_b)
{
	int		size;
	t_stack	*node;

	if (list_b->size != 0)
	{
		return (0);
	}
	size = list_a->size;
	node = list_a->begin;
	while (size > 1)
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

void	ft_sort_order(t_list *list)
{
	int		size;
	t_stack	*node;

	size = list->size;
	node = list->begin;
	while (size != 1)
	{
		if (node->nbr > node->next->nbr)
		{
			break ;
		}
		size--;
		node = node->next;
	}
	while (node->nbr != list->end->nbr)
	{
		if (size <= (list->size /  2) + 1)
		{
			ft_rra(list);
		}
		if (size > (list->size / 2) + 1)
		{
			ft_ra(list);
		}
	}
}

void	ft_sort_3(t_list *list_a, t_list *list_b)
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
	int	b;
	
	if (list_a->size == 5)
	{	
		ft_pb(list_a, list_b);
	}
	ft_pb(list_a, list_b);
	ft_sort_3(list_a, list_b);
	
	b = list_b->begin->nbr;
	
	if (b > list_a->end->nbr || b < list_a->begin->nbr)
	{
		ft_pa(list_a, list_b);
	}
	if (b > list_a->begin->nbr && b < list_a->begin->next->nbr)
	{
		ft_ra(list_a);
		ft_pa(list_a, list_b);
	}
	if (b > list_a->begin->next->nbr && b < list_a->end->nbr)
	{
		ft_rra(list_a);
		ft_pa(list_a, list_b);
	}
	ft_sort_order(list_a);
	if (ft_check(list_a, list_b) == 1)
	{
		return ;
	}
	b = list_b->begin->nbr;
	if (b < list_a->begin->nbr || b > list_a->end->nbr)
	{
		ft_pa(list_a, list_b);
	}
	if (b > list_a->begin->nbr && b < list_a->begin->next->nbr)
	{
		ft_ra(list_a);
		ft_pa(list_a, list_b);
	}
	if (b > list_a->begin->next->nbr && b < list_a->begin->next->next->nbr)
	{
		ft_ra(list_a);
		ft_ra(list_a);
		ft_pa(list_a, list_b);
	}
	if (b > list_a->begin->next->next->nbr && b < list_a->end->nbr)
	{
		ft_rra(list_a);
		ft_pa(list_a, list_b);
	}
	ft_sort_order(list_a);
}

void	ft_sort(t_list *list_a, t_list *list_b)
{
	if (ft_check(list_a, list_b) == 1)
	{
		return ;
	}
	if (list_a->size == 2 && list_a->begin->nbr > list_a->begin->next->nbr)
	{
		ft_sa(list_a);
	}
	if (list_a->size == 3)
	{
		ft_sort_3(list_a, list_b);
	}
	if (list_a->size > 3 && list_a->size <= 5)
	{
		ft_sort_5(list_a, list_b);
	}
	return ;
}
