/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:02:47 by grocha-l          #+#    #+#             */
/*   Updated: 2022/09/28 15:44:24 by grocha-l         ###   ########.fr       */
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

void	ft_free_stack(t_list *list_a)
{
	t_stack	*aux;
	int		size;

	size = list_a->size;
	while (size != 0)
	{
		aux = list_a->begin->next;
		free(list_a->begin);
		list_a->begin = aux;
		size--;
	}
}
