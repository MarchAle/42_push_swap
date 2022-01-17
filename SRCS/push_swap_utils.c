/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:42:28 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/17 17:00:14 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

int	ft_do_quicksort(t_list **stack_a, t_list **stack_b, int lst_size)
{
	if (lst_size > 400)
	{
		if (!ft_quicksort(stack_a, stack_b, 28))
			return (0);
	}
	else
	{
		if (!ft_quicksort(stack_a, stack_b, 10))
			return (0);
	}
	return (1);
}

void	ft_free_all(int *medians, t_med *m)
{
	free(medians);
	free(m);
}
