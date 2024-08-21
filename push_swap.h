/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeow <joeow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:20:32 by jow               #+#    #+#             */
/*   Updated: 2024/08/03 15:16:47 by joeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/inc/libft.h"
# include "libft/inc/ft_printf.h"
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack_node
{
	int					data;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target_node;
}	t_stack_node;

// ** STACK_INIT_C **
void			stack_init(t_stack_node **a, char **argv);

// ** ERRORS_C ** 
void			free_errors(t_stack_node **a);
void			free_stack(t_stack_node **stack);
int				error_repetition(t_stack_node *a, int n);
int				error_syntax(char *str);

// ** STACK_UTILS_C **
void			append_node(t_stack_node **a, int n);
t_stack_node	*find_last_node(t_stack_node *stack);
int				stack_length(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);

// ** SWAP_C **
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

// ** SORT_THREE_C **
void			sort_three(t_stack_node **a);

// ** ROTATE_C **
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

// ** REVERSE_ROTATE_C **
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

#endif
