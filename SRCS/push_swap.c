/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:37:57 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/17 16:48:27 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

int	ft_check_av(char **av)
{
	int	i;
	int	k;

	i = -1;
	while (av[++i])
	{	
		k = -1;
		while (av[i][++k])
		{
			if (((av[i][k] < '0' && av[i][k] != '-') || av[i][k] > '9')
				|| (av[i][k] == '-' && k != 0)
				|| (av[i][0] == '-' && av[i][1] == '\0'))
				return (FALSE);
		}
		k = 1;
		while (av[i + k])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[i + k]))
				return (FALSE);
			k++;
		}
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
			return (FALSE);
	}
	return (TRUE);
}

t_list	*ft_fill_stack_a(t_list *stack_a, char **av)
{
	t_list	*new_node;
	int		i;

	i = 0;
	while (av[i])
	{
		new_node = ft_lstnew(ft_atoi(av[i]));
		if (!new_node)
		{
			ft_lstclear(&stack_a);
			return (NULL);
		}
		ft_lstadd_back(&stack_a, new_node);
		i++;
	}
	return (stack_a);
}

int	ft_checksort(t_list	*stack_a)
{
	t_list	*temp;

	temp = stack_a;
	while (temp->next)
	{
		if (temp->content > temp->next->content)
		{
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}

int	ft_push_swap(char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_fill_stack_a(stack_a, av);
	if (!ft_checksort(stack_a))
	{
		if (ft_lstsize(stack_a) <= 5)
			ft_sort_small_dataset(&stack_a, &stack_b);
		else
		{
			if (!ft_do_quicksort(&stack_a, &stack_b, ft_lstsize(stack_a)))
			{
				ft_lstclear(&stack_a);
				return (0);
			}
			ft_insertsort(&stack_a, &stack_b);
		}
	}
	ft_lstclear(&stack_a);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		av = &av[1];
	if (av[0])
	{
		if (ft_check_av(av) == FALSE)
			write(2, "Error\n", 6);
		else
			ft_push_swap(av);
	}
	if (ac == 2)
		ft_split_clear(av);
	return (0);
}
