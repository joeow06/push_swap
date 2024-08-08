/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeow <joeow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:20:32 by jow               #+#    #+#             */
/*   Updated: 2024/08/03 15:14:33 by joeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack_node **a, char **argv)
{
	long	nbr;
	int		i;

	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_errors(a);
		if (error_repetition(*a, (int)nbr))
			free_errors(a);
		append_node(a, (int)nbr);
		i++;
	}
}

void	append_node(t_stack_node **a, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->data = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}_
