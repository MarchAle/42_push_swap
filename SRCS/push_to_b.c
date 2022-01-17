/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:38:06 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/17 15:10:48 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	ft_do_not_push(t_list **stk_a, t_list **stk_b, int *med, t_med *m)
{
	t_list	*current;
	t_list	*current_b;

	current = *stk_a;
	current_b = *stk_b;
	ft_rr_waiting(stk_a, stk_b, med, m);
	if (ft_not_to_be_push(*stk_a, med, m))
		ra(stk_a);
}

void	ft_wait(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_a;
	t_list	*current_b;

	current_a = *stack_a;
	current_b = *stack_b;
	if (ft_lstsize(*stack_b) > 1)
	{
		while (current_b && current_b->wait == TRUE
			&& current_a->content < current_b->content)
		{
			current_b->wait = FALSE;
			current_b = current_b->next;
			rb(stack_b);
		}
	}
	current_a->wait = TRUE;
	pb(stack_a, stack_b);
}

int	ft_not_to_be_push(t_list *stack_a, int *medians, t_med *m)
{
	if (stack_a->content > medians[m->highmed]
		|| stack_a->content <= medians[m->lowmed])
		return (TRUE);
	else
		return (FALSE);
}

void	ft_push_under(t_list **stk_a, t_list **stk_b, int *med, t_med *m)
{
	ft_wait(stk_a, stk_b);
	ft_dorr(stk_a, stk_b, med[m->lowmed], med[m->highmed]);
	if (++m->nb_low % m->chunk_size == 0)
		m->lowmed--;
}

void	ft_push_on_top(t_list **stack_a, t_list **stack_b, t_med *m)
{
	ft_freewait(stack_b);
	pb(stack_a, stack_b);
	if (++m->nb_high % m->chunk_size == 0)
		m->highmed++;
}
