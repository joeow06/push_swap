/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeow <jow@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:32:47 by joeow             #+#    #+#             */
/*   Updated: 2024/08/24 23:32:10 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	move_a_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
}

//The two if statements specifically handle cases where the stack a has 4 or 5 
//elements, ensuring that the stack is reduced to exactly 3 elements before the
//final sorting and reintegration of the other elements from stack b.
void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	length_a;

	length_a = stack_length(*a);
	if (length_a-- > 3 && !stack_sorted(*a))
		pb(b, a, true);
	if (length_a-- > 3 && !stack_sorted(*a))
		pb(b, a, true);
	while (length_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
