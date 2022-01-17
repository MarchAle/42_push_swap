/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_dataset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:22:14 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/17 15:03:24 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	ft_sort_three(t_list **a)
{
	t_list	*current;

	current = *a;
	while (!ft_checksort(*a))
	{
		if (current->content > current->next->content)
			sa(a);
		else if (current->next->content > current->next->next->content)
			rra(a);
		current = *a;
	}
}

int	ft_get_distance(t_list *a)
{
	int		distance;
	int		index;
	int		min;
	t_list	*current;

	index = 0;
	distance = 0;
	current = a;
	min = current->content;
	while (current)
	{
		if (current->content < min)
		{
			distance = index;
			min = current->content;
		}
		index++;
		current = current->next;
	}
	return (distance);
}

void	ft_sort_four(t_list **a, t_list **b)
{
	int		distance;

	distance = ft_get_distance(*a);
	if (distance == 1)
		ra(a);
	if (distance == 2)
	{
		rra(a);
		rra(a);
	}
	if (distance == 3)
		rra(a);
	pb(a, b);
	ft_sort_three(a);
	pa(a, b);
}

void	ft_sort_five(t_list **a, t_list **b)
{
	int		distance;

	distance = ft_get_distance(*a);
	if (distance == 1)
		ra(a);
	if (distance == 2)
	{
		ra(a);
		ra(a);
	}
	if (distance == 3)
	{
		rra(a);
		rra(a);
	}
	if (distance == 4)
		rra(a);
	pb(a, b);
	ft_sort_four(a, b);
	pa(a, b);
}

void	ft_sort_small_dataset(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		ra(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		ft_sort_three(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		ft_sort_four(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		ft_sort_five(stack_a, stack_b);
}
