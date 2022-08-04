/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:42:54 by grocha-l          #+#    #+#             */
/*   Updated: 2022/07/29 16:25:59 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *list)
{
	t_stack	*temp;

	if (list->size <= 1)
	{
		return ;
	}
	temp = list->begin->next;
	list->begin->next = list->begin->next->next;
	temp->next = list->begin;
	list->begin = temp;
}

void	ft_sa(t_list *list_a)
{
	ft_swap(list_a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_list *list_b)
{
	ft_swap(list_b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_list *list_a, t_list *list_b)
{
	ft_swap(list_a);
	ft_swap(list_b);
	write(1, "ss\n", 3);
}
