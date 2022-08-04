/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:43:35 by grocha-l          #+#    #+#             */
/*   Updated: 2022/07/29 16:24:13 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list *list)
{
	t_stack	*temp;

	if (list->size <= 2)
	{
		if (list->size == 2)
		{
			ft_swap(&*list);
		}
		return ;
	}
	temp = list->begin->next;
	list->begin->next = NULL;
	list->end->next = list->begin;
	list->end = list->begin;
	list->begin = temp;
}

void	ft_ra(t_list *list_a)
{
	ft_rotate(list_a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_list *list_b)
{
	ft_rotate(list_b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_list *list_a, t_list *list_b)
{
	ft_rotate(list_a);
	ft_rotate(list_b);
	write(1, "rr\n", 3);
}
