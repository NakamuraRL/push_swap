/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:43:04 by grocha-l          #+#    #+#             */
/*   Updated: 2022/09/20 14:13:47 by grocha-l         ###   ########.fr       */
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

int		ft_get_biggest(t_list *list)
{
	int		big;
	int		size;
	t_stack *node;

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

int		ft_get_smallest(t_list *list)
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

int		ft_get_position(t_list *list, int nbr)
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

int		ft_get_antecessor(t_list *list, int nbr)
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
			{
				ant1 = ant2;
			}
			if (ant2 > ant1)
			{
				ant1 = ant2;
			}
		}
		node = node->next;
		size--;
	}
	return (ant1);
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

void	ft_sort_5(t_list *list_a, t_list *list_b)
{
	int	b;
	int	x;
	
	if (list_a->size == 5)
	{	
		ft_pb(list_a, list_b);
	}
	ft_pb(list_a, list_b);
	ft_sort_3(list_a);
	
	x = 2;
	while (x != 0)
	{
		b = list_b->begin->nbr;
		if (x == 2 && (b > ft_get_biggest(list_a) || b < ft_get_smallest(list_a)))
		{
			ft_pa(list_a, list_b);
			if (list_a->size + list_b->size == 4)
			{
				x--;
			}
			x--;
			continue ;
		}
		ft_ra_or_rra(list_a, b);
		ft_pa(list_a, list_b);
		if (list_a->size + list_b->size == 4)
		{
			x--;
		}
		x--;
	}
	ft_sort_order(list_a);
}

int		*ft_ordered_index(t_list *list_a)
{
	int	*index;
	int	size;
	int	i;
	int temp;

	index = malloc(sizeof(list_a->size));
	i = 0;
	while (i != list_a->size)
	{
		index[i] = list_a->begin->nbr;
		i++;
		ft_rotate(list_a);
	}
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

int		ft_get_index(t_list *list_a, int nbr)
{
	int	i;
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

void	ft_print_changed_list(t_list *list_a)
{
	int		size;
	t_stack *node;
	
	size = list_a->size;
	node = list_a->begin;
	while (size != 0)
	{
		printf("%i\n", node->nbr);
		size--;
		node = node->next;
	}
}

int		ft_get_limit(t_list *list_a, t_list *list_b)
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

int		ft_get_limit_500(t_list *list_a, t_list *list_b)
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
	{
		lim = ft_get_limit(list_a, list_b);
	}
	else
	{
		lim = ft_get_limit_500(list_a, list_b);
	}
	size_b = list_b->size;
	size_c = lim;
	while (lim > 0)
	{
		hold_1 = -1;
		hold_2 = -1;
		node = list_a->begin;
		while (hold_1 == -1)
		{
			if (node->nbr > size_b && node->nbr <= size_c + size_b)
			{
				hold_1 = node->nbr;
			}
			node = node->next;
		}
		node = list_a->begin;
		size = list_a->size;
		while (size > 0)
		{
			if (node->nbr > size_b && node->nbr <= size_c + size_b)
			{
				hold_2 = node->nbr;
			}
			size--;
			if (size == 0)
			{
				break ;
			}
			node = node->next;
		}
		ft_h1_or_h2(list_a, list_b, hold_1, hold_2);
		lim--;
	}
}

void	ft_sort_100(t_list *list_a, t_list *list_b)
{
	int	size;
	int	b;

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
	while (size != 0)
	{
		b = list_b->begin->nbr;
		if (size == list_a->size && (b > ft_get_biggest(list_a) || b < ft_get_smallest(list_a)))
		{
			ft_pa(list_a, list_b);
			size--;
			continue ;
		}
		ft_ra_or_rra(list_a, b);
		ft_pa(list_a, list_b);
		size--;	
	}
	ft_sort_order(list_a);
}

void	ft_sort_500(t_list *list_a, t_list *list_b)
{
	int	size;
	int	b;
	
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
	while (size != 0)
	{
		b = list_b->begin->nbr;
		if (size == list_a->size && (b > ft_get_biggest(list_a) || b < ft_get_smallest(list_a)))
		{
			ft_pa(list_a, list_b);
			size--;
			continue ;
		}
		ft_ra_or_rra(list_a, b);
		ft_pa(list_a, list_b);
		size--;	
	}
	ft_sort_order(list_a);
}

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
