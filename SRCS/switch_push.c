/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:57:16 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/17 17:23:42 by amarchal         ###   ########.fr       */
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
		write(1, "ss\n", 3);
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
		write(1, "sa\n", 3);
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
		write(1, "sb\n", 3);
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
		write(1, "pa\n", 3);
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
		write(1, "pb\n", 3);
	}
}
