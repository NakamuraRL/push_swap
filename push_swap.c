/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:16:24 by grocha-l          #+#    #+#             */
/*   Updated: 2022/09/22 21:16:05 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int				i;
	static t_list	stack_a;
	static t_list	stack_b;

	i = 2;
	if (argc == 1)
		return (0);
	if (ft_check(argc, argv) == 1)
	{
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
}

int	ft_check(int argc, char **argv)
{
	if (ft_check_type(argc, argv) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ft_check_range(argc, argv) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ft_check_dup(argc, argv) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	ft_check_range(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i != argc)
	{
		if (ft_atol(argv[i]) > 2147483647 || ft_atol(argv[i]) < -2147483648)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_dup(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i != argc)
	{
		j = i + 1;
		while (j != argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_type(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i != argc)
	{
		if (ft_strcmp(argv[i], "0") == 0)
		{
			i++;
			continue ;
		}
		if (ft_strcmp(argv[i], "0") != 0 && ft_atoi(argv[i]) == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
