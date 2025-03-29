/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sude <sude@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 22:44:06 by staylan           #+#    #+#             */
/*   Updated: 2025/03/29 04:11:07 by sude             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_in_a(t_stack **stack_a, t_stack **stack_b)
{//b nin a daki hedefini bulacak
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		small_target;

	if (!*stack_a || !*stack_b)
		return ;
	tmp_b = *stack_b;
	while (tmp_b)
	{
		small_target = INT_MAX;
		tmp_a = *stack_a;
		while (tmp_a)
		{
			if (tmp_a->nbr > tmp_b->nbr
				&& small_target > tmp_a->nbr)
			{
				small_target = tmp_a->nbr;
				tmp_b->target = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (small_target == INT_MAX)
			tmp_b->target = find_smallest(stack_a);
		tmp_b = tmp_b->next;
	}
}

void	target_in_b(t_stack **stack_a, t_stack **stack_b)
{//a nın b deki hedefi bulunacak
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		big_target;

	if (!*stack_a || !*stack_b)
		return ;
	tmp_a = *stack_a;
	while (tmp_a)
	{
		big_target = INT_MIN;
		tmp_b = *stack_b;
		while (tmp_b)
		{
			if (tmp_a->nbr > tmp_b->nbr
				&& big_target < tmp_b->nbr)
			{
				big_target = tmp_b->nbr;
				tmp_a->target = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (big_target == INT_MIN)
			tmp_a->target = find_highest(stack_b);
		tmp_a = tmp_a->next;
	}
}
