/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:31:22 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/17 17:02:55 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	ft_init(t_list **stk_a, int *medians, t_med *m, int chunk_size)
{
	m->index = ft_get_medians(medians, *stk_a, chunk_size);
	m->lowmed = m->index / 2 - 1;
	m->nb_low = 0;
	m->highmed = m->index / 2 + 1;
	m->nb_high = 0;
	m->chunk_size = chunk_size;
}

int	ft_to_push_under(t_list *stack_a, int *medians, t_med *m)
{
	if (stack_a->content < medians[m->index / 2]
		&& stack_a->content >= medians[m->lowmed])
		return (TRUE);
	else
		return (FALSE);
}

int	ft_to_push_on_top(t_list *stack_a, int *medians, t_med *m)
{
	if (stack_a->content >= medians[m->index / 2]
		&& stack_a->content <= medians[m->highmed])
		return (TRUE);
	else
		return (FALSE);
}

void	ft_freewait(t_list **stack_b)
{
	t_list	*current_b;

	current_b = *stack_b;
	if (ft_lstsize(*stack_b) > 1)
	{
		while (current_b->wait == TRUE)
		{
			current_b->wait = FALSE;
			current_b = current_b->next;
			rb(stack_b);
		}
	}
}

int	ft_quicksort(t_list **stack_a, t_list **stack_b, int chunk_size)
{
	int		*medians;
	t_med	*m;

	m = malloc(sizeof(t_med));
	if (!m)
		return (0);
	medians = malloc(sizeof(int) * (ft_lstsize(*stack_a) / chunk_size));
	if (!medians)
	{
		free(m);
		return (0);
	}
	ft_init(stack_a, medians, m, chunk_size);
	while (*stack_a)
	{
		if (ft_to_push_under(*stack_a, medians, m))
			ft_push_under(stack_a, stack_b, medians, m);
		else if (ft_to_push_on_top(*stack_a, medians, m))
			ft_push_on_top(stack_a, stack_b, m);
		else
			ft_do_not_push(stack_a, stack_b, medians, m);
	}	
	ft_freewait(stack_b);
	ft_free_all(medians, m);
	return (1);
}
