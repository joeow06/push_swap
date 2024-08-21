/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeow <jow@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:11:28 by joeow             #+#    #+#             */
/*   Updated: 2024/08/19 14:11:29 by joeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*top;
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	top = *stack;
	last = top;
	while (last->next)
		last = last->next;
	*stack = top->next;
	(*stack)->prev = NULL;
	last->next = top;
	top->prev = last;
	top->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
