/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_push_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:57:16 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/17 12:00:57 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	ss(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		temp = *stack_a;
		*stack_a = temp->next;
		temp->next = temp->next->next;
		temp2 = *stack_a;
		temp2->next = temp;
		temp = *stack_b;
		*stack_b = temp->next;
		temp->next = temp->next->next;
		temp2 = *stack_b;
		temp2->next = temp;
	}
}

void	sa(t_list **stack_a)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_lstsize(*stack_a) > 1)
	{
		temp = *stack_a;
		*stack_a = temp->next;
		temp->next = temp->next->next;
		temp2 = *stack_a;
		temp2->next = temp;
	}
}

void	sb(t_list **stack_b)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_lstsize(*stack_b) > 1)
	{
		temp = *stack_b;
		*stack_b = temp->next;
		temp->next = temp->next->next;
		temp2 = *stack_b;
		temp2->next = temp;
	}
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b)
	{
		temp = *stack_b;
		*stack_b = temp->next;
		temp->next = *stack_a;
		*stack_a = temp;
	}
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_a)
	{
		temp = *stack_a;
		*stack_a = temp->next;
		temp->next = *stack_b;
		*stack_b = temp;
	}
}
