/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeow <jow@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:32:51 by joeow             #+#    #+#             */
/*   Updated: 2024/09/03 21:59:08 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	min_on_top(t_stack_node **a)
{
	while ((*a)->data != find_min(*a)->data)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

t_stack_node	*find_max(t_stack_node *stack)
{
	int				largest;
	t_stack_node	*largest_node;

	if (stack == NULL)
		return (NULL);
	largest = INT_MIN;
	while (stack)
	{
		if (stack->data > largest)
		{
			largest = stack->data;
			largest_node = stack;
		}
		stack = stack->next;
	}
	return (largest_node);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*largest_node;

	largest_node = find_max(*a);
	if (*a == largest_node)
		ra(a);
	else if ((*a)->next == largest_node)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}
