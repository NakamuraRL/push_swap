/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:39:47 by grocha-l          #+#    #+#             */
/*   Updated: 2022/09/21 15:49:37 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_biggest(t_list *list)
{
	int		big;
	int		size;
	t_stack	*node;

	big = list->begin->nbr;
	size = list->size;
	node = list->begin;
	while (size != 0)
	{
		if (big < node->nbr)
		{
			big = node->nbr;
		}
		node = node->next;
		size--;
	}
	return (big);
}

int	ft_get_smallest(t_list *list)
{
	int		small;
	int		size;
	t_stack	*node;

	small = list->begin->nbr;
	size = list->size;
	node = list->begin;
	while (size != 0)
	{
		if (small > node->nbr)
		{
			small = node->nbr;
		}
		node = node->next;
		size--;
	}
	return (small);
}

int	ft_get_position(t_list *list, int nbr)
{
	int		ant;
	int		pos;
	t_stack	*node;

	ant = ft_get_antecessor(list, nbr);
	pos = 1;
	node = list->begin;
	while (ant != node->nbr)
	{
		pos++;
		node = node->next;
	}
	return (pos);
}

int	ft_get_antecessor(t_list *list, int nbr)
{
	int		ant1;
	int		ant2;
	int		size;
	t_stack	*node;

	node = list->begin;
	ant1 = nbr;
	size = list->size;
	while (size != 0)
	{
		if (node->nbr < nbr)
		{
			ant2 = node->nbr;
			if (ant1 == nbr)
				ant1 = ant2;
			if (ant2 > ant1)
				ant1 = ant2;
		}
		node = node->next;
		size--;
	}
	return (ant1);
}

int	ft_get_index(t_list *list_a, int nbr)
{
	int		i;
	t_stack	*node;

	i = 0;
	node = list_a->begin;
	while (nbr)
	{
		if (node->nbr == nbr)
		{
			break ;
		}
		i++;
		node = node->next;
	}
	return (i);
}
