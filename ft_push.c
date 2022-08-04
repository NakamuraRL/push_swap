/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:03:10 by grocha-l          #+#    #+#             */
/*   Updated: 2022/07/29 16:36:30 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list *list_a, t_list *list_b)
{
	t_stack	*temp;

	temp = list_b->begin->next;
	if (list_a->size == 0)
	{
		list_b->begin->next = NULL;
		list_a->begin = list_b->begin;
		list_a->end = list_a->begin;
		list_b->begin = temp;	
	}
	if (list_a->size > 0)
	{
		list_b->begin->next = list_a->begin;
		list_a->begin = list_b->begin;
		list_b->begin = temp;
	}
	list_a->size++;
	list_b->size--;
}

void	ft_pa(t_list *list_a, t_list *list_b)
{
	ft_push(list_a, list_b);
	write(1, "pa\n", 3);
}

void	ft_pb(t_list *list_a, t_list *list_b)
{
	ft_push(list_b, list_a);
	write(1, "pb\n", 3);
}
