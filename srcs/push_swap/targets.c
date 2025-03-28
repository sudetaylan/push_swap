/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staylan <staylan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 22:44:06 by staylan           #+#    #+#             */
/*   Updated: 2025/03/28 05:56:05 by staylan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		small_target;

	if (!*stack_a || !*stack_b)
		return ;
	tmp_a = *stack_a;
	while (tmp_a)
	{
		small_target = INT_MAX;
		tmp_b = *stack_b;
		while (tmp_b)
		{
			if (tmp_a->nbr < tmp_b->nbr
				&& small_target > tmp_b->nbr)
			{
				small_target = tmp_b->nbr;
				tmp_a->target = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (small_target == INT_MAX)
			tmp_a->target = find_highest(stack_b);
		tmp_a = tmp_a->next;
	}
}


void	target_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		big_target;

	if (!*stack_a || !*stack_b)
		return ;
	tmp_b = *stack_b;
	while (tmp_b)
	{
		big_target = INT_MIN;
		tmp_a = *stack_a;
		while (tmp_a)
		{
			if (tmp_b->nbr > tmp_a->nbr
				&& big_target < tmp_a->nbr)
			{
				big_target = tmp_a->nbr;
				tmp_b->target = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (big_target == INT_MIN)
			tmp_b->target = find_smallest(stack_a);
		tmp_b = tmp_b->next;
	}
}
