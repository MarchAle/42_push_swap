/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medians.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:25:05 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/13 14:03:22 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

int	ft_lstmin(t_list *stack)
{
	t_list	*current;
	int		min;

	current = stack;
	min = current->content;
	while (current)
	{
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	return (min);
}

int	ft_lstmax(t_list *stack)
{
	t_list	*current;
	int		max;

	current = stack;
	max = current->content;
	while (current)
	{
		if (current->content > max)
			max = current->content;
		current = current->next;
	}
	return (max);
}

int	ft_get_medians(int *medians, t_list *stack_a, int chunk_size)
{
	int		index;
	int		lower_than;
	t_list	*temp;
	t_list	*temp2;

	index = 1;
	temp = stack_a;
	while (temp)
	{
		lower_than = chunk_size / 2;
		temp2 = stack_a;
		while (temp2)
		{
			if (temp2->content < temp->content)
				lower_than++;
			temp2 = temp2->next;
		}
		if (lower_than % chunk_size == 0 && lower_than != 0 && index++ > 0)
			medians[lower_than / chunk_size] = temp->content;
		temp = temp->next;
	}
	medians[0] = ft_lstmin(stack_a);
	medians[index] = ft_lstmax(stack_a);
	return (index);
}
