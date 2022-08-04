/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:05:39 by grocha-l          #+#    #+#             */
/*   Updated: 2022/07/29 16:32:43 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_list *list)
{
	int	i;
	
	if (list->size <= 2)
	{
		if (list->size == 2)
		{
			ft_swap(&*list);
		}
		return ;
	}
	i = list->size - 1;
	while (i > 0)
	{
		ft_rotate(&*list);
		i--;
	}
}

void	ft_rra(t_list *list_a)
{
	ft_reverse_rotate(list_a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_list *list_b)
{
	ft_reverse_rotate(list_b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_list *list_a, t_list *list_b)
{
	ft_reverse_rotate(&*list_a);
	ft_reverse_rotate(&*list_b);
	write(1, "rrr\n", 4);
}
