/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sude <sude@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 23:46:16 by beeligul          #+#    #+#             */
/*   Updated: 2025/04/01 19:32:14 by sude             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = list_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	init_a(t_stack *stack_a, t_stack *stack_b)
{
	put_index(stack_a);
	put_index(stack_b);
	target_in_b(stack_a, stack_b);
	find_cost(stack_a, stack_b);
}
void	init_b(t_stack *stack_a, t_stack *stack_b)
{
	put_index(stack_a);
	put_index(stack_b);
	target_in_a(stack_a, stack_b);
}