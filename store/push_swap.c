/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeow <joeow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:20:32 by jow               #+#    #+#             */
/*   Updated: 2024/09/02 13:59:21 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	possible_sort(t_stack_node **a, t_stack_node **b)
{
	if (stack_length(*a) == 2)
		sa(a);
	else if (stack_length(*a) == 3)
		sort_three(a);
	else
		sort_stacks(a, b);
}

static void	print_stack(t_stack_node *a)
{
	while (a)
	{
		printf("%d ", a->data);
		a = a->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		stack_init(&a, argv);
	}
	else
		stack_init(&a, argv + 1);
	print_stack(a);
	printf("stack_len: %d\n", stack_length(a));
	if (!stack_sorted(a))
		possible_sort(&a, &b);
	if(stack_sorted(a))
	{
		printf("stack sorted: ");
		print_stack(a);
	}
	else
	{
		printf("stack still not sorted: ");
		print_stack(a);
		printf("Stack B: ");
		print_stack(b);
		printf("\n");
	}
	free(argv);
	free_stack(&a);
	return (0);
}
