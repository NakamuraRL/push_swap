/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:11:02 by grocha-l          #+#    #+#             */
/*   Updated: 2022/09/28 16:16:30 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (size <= (list->size / 2) + 1)
		{
			ft_rra(list);
		}
		if (size > (list->size / 2) + 1)
		{
			ft_ra(list);
		}
	}
}

void	ft_ra_or_rra(t_list *list_a, int nbr)
{
	int	ant;
	int	pos;

	ant = ft_get_antecessor(list_a, nbr);
	if (ant == nbr)
	{
		ant = ft_get_biggest(list_a);
		nbr = ant;
	}
	pos = ft_get_position(list_a, nbr);
	while (ant != list_a->end->nbr)
	{
		if (pos > (list_a->size / 2))
		{
			ft_rra(list_a);
		}
		else
		{
			ft_ra(list_a);
		}
	}
}

int	*ft_ordered_index(t_list *list_a)
{
	int	*index;
	int	size;
	int	i;
	int	temp;

	index = ft_create_array(list_a);
	size = list_a->size;
	while (size > 0)
	{
		i = 0;
		while (i < list_a->size - 1)
		{
			if (index[i] > index[i + 1])
			{
				temp = index[i];
				index[i] = index[i + 1];
				index[i + 1] = temp;
			}
			i++;
		}
		size--;
	}
	return (index);
}

int	*ft_create_array(t_list *list_a)
{
	int	*index;
	int	j;

	index = malloc((sizeof(int) * (list_a->size + 1)));
	if (!index)
		return (NULL);
	j = 0;
	while (j < list_a->size)
	{
		index[j] = list_a->begin->nbr;
		j++;
		ft_rotate(list_a);
	}
	index[j] = '\0';
	return (index);
}

void	ft_final_sort(t_list *list_a, t_list *list_b, int size)
{
	int	b;

	while (size != 0)
	{
		b = list_b->begin->nbr;
		ft_ra_or_rra(list_a, b);
		ft_pa(list_a, list_b);
		size--;
	}
	ft_sort_order(list_a);
}
