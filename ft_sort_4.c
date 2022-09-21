/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:45:14 by grocha-l          #+#    #+#             */
/*   Updated: 2022/09/21 16:44:50 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_limit(t_list *list_a, t_list *list_b)
{
	int			limit;
	static int	rest;

	if (list_b->size == 0 && (list_a->size + list_b->size) % 5 != 0)
	{
		rest = list_a->size % 5;
	}
	if ((list_a->size + list_b->size) % 5 == 0)
	{
		limit = (list_a->size + list_b->size) / 5;
		return (limit);
	}
	else if (rest != 0)
	{
		limit = ((list_a->size + list_b->size) / 5) + 1;
		rest--;
		return (limit);
	}
	else
	{
		limit = (list_a->size + list_b->size) / 5;
		return (limit);
	}
	return (limit);
}

int	ft_get_limit_500(t_list *list_a, t_list *list_b)
{
	int			limit;
	static int	rest;

	if (list_b->size == 0 && (list_a->size + list_b->size) % 11 != 0)
	{
		rest = list_a->size % 11;
	}
	if ((list_a->size + list_b->size) % 11 == 0)
	{
		limit = (list_a->size + list_b->size) / 11;
		return (limit);
	}
	else if (rest != 0)
	{
		limit = ((list_a->size + list_b->size) / 11) + 1;
		rest--;
		return (limit);
	}
	else
	{
		limit = (list_a->size + list_b->size) / 11;
		return (limit);
	}
	return (limit);
}

void	ft_push_chunk(t_list *list_a, t_list *list_b)
{
	int		hold_1;
	int		hold_2;
	int		size;
	int		size_b;
	int		size_c;
	int		lim;
	t_stack	*node;

	if (list_a->size + list_b->size <= 100)
		lim = ft_get_limit(list_a, list_b);
	else
		lim = ft_get_limit_500(list_a, list_b);
	size_b = list_b->size;
	size_c = lim;
	while (lim > 0)
	{
		hold_1 = ft_hold_1(list_a, size_b, size_c);
		hold_2 = -1;
		node = list_a->begin;
		size = list_a->size;
		while (size > 0)
		{
			if (node->nbr > size_b && node->nbr <= size_c + size_b)
				hold_2 = node->nbr;
			size--;
			if (size == 0)
				break ;
			node = node->next;
		}
		ft_h1_or_h2(list_a, list_b, hold_1, hold_2);
		lim--;
	}
}

int	ft_hold_1(t_list *list_a, int size_b, int size_c)
{
	int		h1;
	t_stack	*node;

	h1 = -1;
	node = list_a->begin;
	while (h1 == -1)
	{
		if (node->nbr > size_b && node->nbr <= size_c + size_b)
			h1 = node->nbr;
		node = node->next;
	}
	return (h1);
}
