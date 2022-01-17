/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:24:01 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/17 17:17:26 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../INCLUDES/push_swap.h"

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

int	ft_do_command(t_list **stack_a, t_list **stack_b, char *command)
{
	if (!ft_strcmp(command, "pb\n"))
		pb(stack_a, stack_b);
	else if (!ft_strcmp(command, "pa\n"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(command, "sa\n"))
		sa(stack_a);
	else if (!ft_strcmp(command, "sb\n"))
		sb(stack_b);
	else if (!ft_strcmp(command, "ss\n"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(command, "ra\n"))
		ra(stack_a);
	else if (!ft_strcmp(command, "rb\n"))
		rb(stack_b);
	else if (!ft_strcmp(command, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(command, "rra\n"))
		rra(stack_a);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(stack_b);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

int	ft_execute(t_list **stack_a, t_list **stack_b, int fd)
{
	char	*command;

	command = get_next_line(fd);
	if (command)
	{
		while (command)
		{
			if (!ft_do_command(stack_a, stack_b, command))
			{
				write (2, "Error\n", 6);
				free(command);
				return (0);
			}
			free(command);
			command = get_next_line(fd);
		}
	}
	return (1);
}

int	ft_checksort(t_list	*stack_a)
{
	t_list	*temp;

	temp = stack_a;
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}
