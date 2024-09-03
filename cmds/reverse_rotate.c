/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeow <jow@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:11:24 by joeow             #+#    #+#             */
/*   Updated: 2024/08/29 00:45:56 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*top;
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	top = *stack;
	last = top;
	while (last->next)
		last = last->next;
	if (last->prev)
		last->prev->next = NULL;
	last->prev = NULL;
	last->next = top;
	top->prev = last;
	*stack = last;
}

void	rra(t_stack_node **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
