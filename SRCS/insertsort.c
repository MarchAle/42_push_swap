/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:34:10 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/13 14:03:00 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	ft_do_ra(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_a;
	t_list	*current_b;

	current_b = *stack_b;
	current_a = *stack_a;
	while (current_b->content > current_a->content
		&& current_a->higher == FALSE)
	{
		current_a = current_a->next;
		ra(stack_a);
		current_a = *stack_a;
		if (ft_lstsize(*stack_b) > 2 && current_b->content > current_a->content
			&& current_b->content < current_a->next->content
			&& current_b->next->content < current_b->next->next->content)
		{
			pa(stack_a, stack_b);
			ss(stack_a, stack_b);
			current_a = *stack_a;
			current_b = *stack_b;
		}
	}
}

void	ft_do_rra(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_a;
	t_list	*current_b;

	current_b = *stack_b;
	current_a = *stack_a;
	while (current_b->content < ft_lstlast(*stack_a)->content
		&& ft_lstlast(*stack_a)->higher == FALSE)
	{
		rra(stack_a);
		current_a = *stack_a;
	}
}

void	ft_check_higher(t_list **stack_a)
{
	t_list	*current_a;

	current_a = *stack_a;
	if (ft_lstsize(*stack_a) > 1
		&& current_a->next->higher == TRUE
		&& current_a->content > current_a->next->content)
	{
		current_a->next->higher = FALSE;
		current_a->higher = TRUE;
		sa(stack_a);
	}
}

void	ft_insertsort(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_a;

	pa(stack_a, stack_b);
	current_a = *stack_a;
	current_a->higher = TRUE;
	while (*stack_b)
	{
		ft_do_ra(stack_a, stack_b);
		ft_do_rra(stack_a, stack_b);
		pa(stack_a, stack_b);
		ft_check_higher(stack_a);
	}
	while (ft_lstlast(*stack_a)->higher == FALSE)
		rra(stack_a);
}
