/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:21:16 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/17 15:12:35 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

int	ft_dorr(t_list **stk_a, t_list **stk_b, int lowmed, int highmed)
{
	t_list	*current_a;
	t_list	*current_b;

	current_a = *stk_a;
	current_b = *stk_b;
	if (ft_lstsize(*stk_a) > 1 && ft_lstsize(*stk_b) > 1)
	{
		if ((current_a->content < lowmed || current_a->content > highmed))
		{
			rr(stk_a, stk_b);
			return (TRUE);
		}
	}
	rb(stk_b);
	return (FALSE);
}

void	ft_rr_waiting(t_list **stk_a, t_list **stk_b, int *med, t_med *m)
{
	t_list	*current;
	t_list	*current_b;

	current = *stk_a;
	current_b = *stk_b;
	while (current_b && current_b->next
		&& (current->content > med[m->highmed]
			|| current->content < med[m->lowmed])
		&& current_b->wait == TRUE)
	{
		current_b->wait = FALSE;
		rr(stk_a, stk_b);
	}
}
