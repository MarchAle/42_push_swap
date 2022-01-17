/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:21:42 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/13 15:20:20 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"
#include "../libft/libft.h"

void	rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = *stack_a;
	*stack_a = temp->next;
	ft_lstlast(*stack_a)->next = temp;
	temp->next = NULL;
	temp = *stack_b;
	*stack_b = temp->next;
	ft_lstlast(*stack_b)->next = temp;
	temp->next = NULL;
	write(1, "rr\n", 3);
}

void	ra(t_list **stack_a)
{
	t_list	*temp;

	if (ft_lstsize(*stack_a) > 1)
	{
		temp = *stack_a;
		*stack_a = temp->next;
		ft_lstlast(*stack_a)->next = temp;
		temp->next = NULL;
		write(1, "ra\n", 3);
	}
}

void	rb(t_list **stack_b)
{
	t_list	*temp;

	if (ft_lstsize(*stack_b) > 1)
	{
		temp = *stack_b;
		*stack_b = temp->next;
		ft_lstlast(*stack_b)->next = temp;
		temp->next = NULL;
		write(1, "rb\n", 3);
	}
}

void	rra(t_list **stack_a)
{
	t_list	*temp;

	if (ft_lstsize(*stack_a) > 1)
	{
		temp = ft_lstlast(*stack_a);
		ft_lstbeforelast(*stack_a)->next = NULL;
		temp->next = *stack_a;
		*stack_a = temp;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_list **stack_b)
{
	t_list	*temp;

	if (ft_lstsize(*stack_b) > 1)
	{
		temp = ft_lstlast(*stack_b);
		ft_lstbeforelast(*stack_b)->next = NULL;
		temp->next = *stack_b;
		*stack_b = temp;
		write(1, "rrb\n", 4);
	}
}
