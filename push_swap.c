/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:16:24 by grocha-l          #+#    #+#             */
/*   Updated: 2022/07/31 15:59:21 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	static t_list stack_a;
	static t_list stack_b;

	i = 2;
	stack_a.begin = ft_new_node(&stack_a, *argv[1]);
	stack_a.end = stack_a.begin;
	while (argc != 2)
	{
		ft_put_tail(&stack_a, *argv[i]);
		i++;
		argc--;
	}

	write(1, "\nUnsolved\n\n", 11);
	ft_print_stacks(&stack_a, &stack_b);
	write(1, "\n", 1);
	ft_sort(&stack_a, &stack_b);
	write(1, "\nSolved\n\n", 9);
	ft_print_stacks(&stack_a, &stack_b);
}
