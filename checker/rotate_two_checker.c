/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_two_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:21:42 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/17 13:46:27 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"
#include "../libft/libft.h"

void	rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		temp = ft_lstlast(*stack_a);
		ft_lstbeforelast(*stack_a)->next = NULL;
		temp->next = *stack_a;
		*stack_a = temp;
		temp = ft_lstlast(*stack_b);
		ft_lstbeforelast(*stack_b)->next = NULL;
		temp->next = *stack_b;
		*stack_b = temp;
	}
}
