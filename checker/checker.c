/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:04:46 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/18 10:39:23 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
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

int	ft_checker(char **av, int fd)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_fill_stack_a(stack_a, av);
	if (!ft_execute(&stack_a, &stack_b, fd))
	{
		ft_lstclear(&stack_a);
		ft_lstclear(&stack_b);
		return (0);
	}
	if (!ft_checksort(stack_a) || ft_lstsize(stack_b))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	if (stack_b)
		ft_lstclear(&stack_b);
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
			ft_checker(av, 0);
	}
	if (ac == 2)
		ft_split_clear(av);
	return (0);
}
