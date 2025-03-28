/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staylan <staylan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 22:41:19 by staylan           #+#    #+#             */
/*   Updated: 2025/03/28 04:18:32 by staylan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**sort_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	while (*stack_b)
	{
		target_b(stack_a, stack_b);
		cheapest = find_cheapest(stack_b, stack_a);
		if (cheapest->index <= (list_size(*stack_b) / 2)
			&& cheapest->target->index <= (list_size(*stack_a) / 2))
			do_rarb(stack_a, stack_b, cheapest->nbr, 'b');
		else if ((cheapest->index > (list_size(*stack_b) / 2))
			&& (cheapest->target->index > (list_size(*stack_a) / 2)))
			do_rrarrb(stack_a, stack_b, cheapest->nbr, 'b');
		else if (cheapest->index <= (list_size(*stack_b) / 2)
			&& cheapest->target->index > (list_size(*stack_a) / 2))
			do_rrarb(stack_a, stack_b, cheapest->nbr, 'b');
		else if (cheapest->index > (list_size(*stack_b) / 2)
			&& cheapest->target->index <= (list_size(*stack_a) / 2))
			do_rarrb(stack_a, stack_b, cheapest->nbr, 'b');
	}
	return (stack_a);
}

void	sort_till3_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	while (list_size(*stack_a) > 3 && !is_sorted(*stack_a))
	{
		target_a(stack_a, stack_b);
		cheapest = find_cheapest(stack_a, stack_b);
		if (cheapest->index <= (list_size(*stack_a) / 2)
			&& cheapest->target->index <= (list_size(*stack_b) / 2))
			do_rarb(stack_a, stack_b, cheapest->nbr, 'a');
		else if ((cheapest->index > (list_size(*stack_a) / 2))
			&& (cheapest->target->index > (list_size(*stack_b) / 2)))
			do_rrarrb(stack_a, stack_b, cheapest->nbr, 'a');
		else if (cheapest->index <= (list_size(*stack_a) / 2)
			&& cheapest->target->index > (list_size(*stack_b) / 2))
			do_rarrb(stack_a, stack_b, cheapest->nbr, 'a');
		else if (cheapest->index > (list_size(*stack_a) / 2)
			&& cheapest->target->index <= (list_size(*stack_b) / 2))
			do_rrarb(stack_a, stack_b, cheapest->nbr, 'a');
	}
}

t_stack	*sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (list_size(*stack_a) > 3 && !is_sorted(*stack_a))
		pb(stack_a, &stack_b, 0);
	if (list_size(*stack_a) > 3 && !is_sorted(*stack_a))
		pb(stack_a, &stack_b, 0);
	if (list_size(*stack_a) > 3 && !is_sorted(*stack_a))
		sort_till3_b(stack_a, &stack_b);
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	return (stack_b);
}

void	sort_list(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (list_size(*stack_a) == 2)
		sa(stack_a, 0);
	else
	{
		stack_b = sort_b(stack_a);
		stack_a = sort_a(stack_a, &stack_b);
		put_index(stack_a);
		i = find_min(*stack_a);
		if (i < list_size(*stack_a) / 2)
		{
			while (i-- != 0)
				ra(stack_a, 0);
		}
		else
		{
			while (i++ < list_size(*stack_a))
				rra(stack_a, 0);
		}		
	}
}
