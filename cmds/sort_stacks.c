/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeow <jow@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:32:47 by joeow             #+#    #+#             */
/*   Updated: 2024/08/29 00:46:18 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	move_b_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, true);
}

static void	min_on_top(t_stack_node **a)
{
	while ((*a)->data != find_min(*a)->data)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

static void	rev_rotate_both(t_stack_node **a,
					t_stack_node **b,
					t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rrr(a, b);
	current_position(*a);
	current_position(*b);
}

static void	rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rr(a, b);
	current_position(*a);
	current_position(*b);
}

static void	move_a_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a, true);
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
	current_position(*a);
	min_on_top(a);
}
