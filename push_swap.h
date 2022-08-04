/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:14:28 by grocha-l          #+#    #+#             */
/*   Updated: 2022/08/03 15:07:35 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
    int				nbr;
    struct s_stack	*next;
}	t_stack;

typedef struct s_list
{
	t_stack *begin;
	t_stack *end;
	int size;
}	t_list;

int		main(int argc, char **argv);

t_stack	*ft_new_node(t_list *list, int nbr);

void	ft_put_tail(t_list *l, int nbr);

void	ft_print_stacks(t_list *list_a, t_list *list_b);

void	ft_putnbr(int n);
int		ft_atoi(const char *str);

void	ft_swap(t_list *list);
void	ft_sa(t_list *list_a);
void	ft_sb(t_list *list_b);
void	ft_ss(t_list *list_a, t_list *list_b);

void	ft_push(t_list *list_a, t_list *list_b);
void	ft_pa(t_list *list_a, t_list *list_b);
void	ft_pb(t_list *list_a, t_list *list_b);

void	ft_rotate(t_list *list);
void	ft_ra(t_list *list_a);
void	ft_rb(t_list *list_b);
void	ft_rr(t_list *list_a, t_list *list_b);

void	ft_reverse_rotate(t_list *list);
void	ft_rra(t_list *list_a);
void	ft_rrb(t_list *list_b);
void	ft_rrr(t_list *list_a, t_list *list_b);

void	ft_sort(t_list *list_a, t_list *list_b);
void	ft_sort_order(t_list *list);
void	ft_sort_3(t_list *list_a, t_list *list_b);
void	ft_sort_5(t_list *list_a, t_list *list_b);
int		ft_check(t_list *list_a, t_list *list_b);

#endif
