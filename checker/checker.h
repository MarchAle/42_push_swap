/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:05:01 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/17 17:18:13 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>
# include "../INCLUDES/push_swap.h"
# include "../libft/libft.h"

size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
int		ft_end_of_line(char *buff);
char	*ft_strjoin(char *s1, char *s2);
void	ft_strcpy(char *dest, char *src);
char	*ft_fill_str(char *str, char *s1, char*s2);
int		ft_check_av(char **av);
t_list	*ft_fill_stack_a(t_list *stack_a, char **av);
int		ft_do_command(t_list **stack_a, t_list **stack_b, char *command);
int		ft_execute(t_list **stack_a, t_list **stack_b, int fd);
int		ft_checksort(t_list	*stack_a);
void	rr(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

#endif