/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:40:39 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/17 17:00:55 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct m_list
{
	int		index;
	int		lowmed;
	int		nb_low;
	int		highmed;
	int		nb_high;
	int		chunk_size;
}				t_med;

int			ft_lstmin(t_list *stack);
int			ft_lstmax(t_list *stack);
int			ft_get_medians(int *medians, t_list *stack_a, int chunk_size);
int			ft_dorr(t_list **stk_a, t_list **stk_b, int lowmed, int highmed);
void		ft_rr_waiting(t_list **stk_a, t_list **stk_b, int *med, t_med *m);
t_list		*ft_lstnew(long content);
void		ft_lstadd_front(t_list **alst, t_list *new_node);
void		ft_lstadd_back(t_list **alst, t_list *new_node);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstbeforelast(t_list *lst);
long int	ft_atoi(const char *str);
void		ft_lstclear(t_list **lst);
int			ft_lstsize(t_list *lst);
int			ft_dorr(t_list **stk_a, t_list **stk_b, int lowmed, int highmed);
void		ft_do_not_push(t_list **stk_a, t_list **stk_b, int *med, t_med *m);
void		ft_wait(t_list **stack_a, t_list **stack_b);
int			ft_not_to_be_push(t_list *stack_a, int *medians, t_med *m);
void		ft_push_under(t_list **stk_a, t_list **stk_b, int *med, t_med *m);
void		ft_push_on_top(t_list **stack_a, t_list **stack_b, t_med *m);
void		ft_init(t_list **stk_a, int *medians, t_med *m, int chunk_size);
int			ft_to_push_under(t_list *stack_a, int *medians, t_med *m);
int			ft_to_push_on_top(t_list *stack_a, int *medians, t_med *m);
void		ft_freewait(t_list **stack_b);
int			ft_check_av(char **av);
int			ft_checksort(t_list	*stack_a);
t_list		*ft_fill_stack_a(t_list *stack_a, char **av);
int			ft_do_quicksort(t_list **stack_a, t_list **stack_b, int lst_size);
int			ft_quicksort(t_list **stack_a, t_list **stack_b, int chunk_size);
void		ft_free_all(int *medians, t_med *m);
void		ft_do_ra(t_list **stack_a, t_list **stack_b);
void		ft_do_rra(t_list **stack_a, t_list **stack_b);
void		ft_check_higher(t_list **stack_a);
void		ft_insertsort(t_list **stack_a, t_list **stack_b);
void		rr(t_list **stack_a, t_list **stack_b);
void		ra(t_list **stack_a);
void		rb(t_list **stack_b);
void		rra(t_list **stack_a);
void		rrb(t_list **stack_b);
void		ss(t_list **stack_a, t_list **stack_b);
void		sa(t_list **stack_a);
void		sb(t_list **stack_b);
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
int			ft_get_distance(t_list *a);
void		ft_sort_three(t_list **stack_a);
void		ft_sort_four(t_list **a, t_list **b);
void		ft_sort_five(t_list **a, t_list **b);
void		ft_sort_small_dataset(t_list **stack_a, t_list **stack_b);

#endif