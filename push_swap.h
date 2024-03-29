/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <grocha-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:14:28 by grocha-l          #+#    #+#             */
/*   Updated: 2022/09/28 16:33:08 by grocha-l         ###   ########.fr       */
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
	t_stack	*begin;
	t_stack	*end;
	int		size;
}	t_list;

int			ft_atoi(const char *str);
long long	ft_atol(const char *str);

int			ft_get_biggest(t_list *list);
int			ft_get_smallest(t_list *list);
int			ft_get_position(t_list *list, int nbr);
int			ft_get_antecessor(t_list *list, int nbr);
int			ft_get_index(t_list *list_a, int nbr);

t_stack		*ft_new_node(t_list *list, int nbr);
void		ft_put_tail(t_list *l, int nbr);
void		ft_free_stack(t_list *list_a);

void		ft_push(t_list *list_a, t_list *list_b);
void		ft_pa(t_list *list_a, t_list *list_b);
void		ft_pb(t_list *list_a, t_list *list_b);

void		ft_reverse_rotate(t_list *list);
void		ft_rra(t_list *list_a);
void		ft_rrb(t_list *list_b);
void		ft_rrr(t_list *list_a, t_list *list_b);

void		ft_rotate(t_list *list);
void		ft_ra(t_list *list_a);
void		ft_rb(t_list *list_b);
void		ft_rr(t_list *list_a, t_list *list_b);

void		ft_sort(t_list *list_a, t_list *list_b);
void		ft_sort_3(t_list *list_a);
void		ft_sort_5(t_list *list_a, t_list *list_b);
void		ft_sort_100(t_list *list_a, t_list *list_b);
void		ft_sort_500(t_list *list_a, t_list *list_b);

void		ft_sort_order(t_list *list);
void		ft_ra_or_rra(t_list *list_a, int nbr);
int			*ft_ordered_index(t_list *list_a);
int			*ft_create_array(t_list *list_a);
void		ft_final_sort(t_list *list_a, t_list *list_b, int size);

void		ft_change_list(t_list *list_a, int *index);
void		ft_h1_or_h2(t_list *list_a, t_list *list_b, int hold_1, int hold_2);
void		ft_push_in_order(t_list *list_a, t_list *list_b);
int			ft_is_sorted(t_list *list_a);

int			ft_get_limit(t_list *list_a, t_list *list_b);
int			ft_get_limit_500(t_list *list_a, t_list *list_b);
void		ft_push_chunk(t_list *list_a, t_list *list_b);
int			ft_hold_1(t_list *list_a, int size_b, int size_c);
int			ft_hold_2(t_list *list_a, int size_b, int size_c);

int			ft_strcmp(const char *s1, const char *s2);

void		ft_swap(t_list *list);
void		ft_sa(t_list *list_a);
void		ft_sb(t_list *list_b);
void		ft_ss(t_list *list_a, t_list *list_b);

int			main(int argc, char **argv);
int			ft_check(int argc, char **argv);
int			ft_check_range(int argc, char **argv);
int			ft_check_dup(int argc, char **argv);
int			ft_check_type(int argc, char **argv);

#endif
