/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:16:24 by grocha-l          #+#    #+#             */
/*   Updated: 2022/09/08 14:57:44 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int				i;
	static t_list	stack_a;
	static t_list	stack_b;

	i = 2;
	stack_a.begin = ft_new_node(&stack_a, ft_atoi(argv[1]));
	stack_a.end = stack_a.begin;
	while (argc != 2)
	{
		ft_put_tail(&stack_a, ft_atoi(argv[i]));
		i++;
		argc--;
	}

	ft_sort(&stack_a, &stack_b);
}
