/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:02:47 by grocha-l          #+#    #+#             */
/*   Updated: 2022/09/21 14:53:45 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(t_list *list, int nbr)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->nbr = nbr;
	new_node->next = NULL;
	list->size++;
	return (new_node);
}

void	ft_put_tail(t_list *list, int nbr)
{
	t_stack	*node;

	node = ft_new_node(list, nbr);
	list->end->next = node;
	list->end = node;
}
