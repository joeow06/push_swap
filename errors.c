/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeow <joeow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:27:22 by joeow             #+#    #+#             */
/*   Updated: 2024/08/04 20:41:33 by joeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_errors(t_stack_node **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->data = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

int	error_repetition(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->data == n)
			return (1);
		a = a->next;
	}
	return (0);
}

int	error_syntax(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}
