/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:33:01 by grocha-l          #+#    #+#             */
/*   Updated: 2022/06/23 10:29:03 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_tail(t_list *list, int nbr)
{
	t_stack	*node;

	node = ft_new_node(list, nbr);
	list->end->next = node;
	list->end = node;
}
