
#include "push_swap.h"

t_stack	*find_highest(t_stack *stack)
{
	int			max;
	t_stack	*highest;

	if (!stack)
		return (NULL);
	max = INT_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			highest = stack;
		}
		stack = stack->next;
	}
	return (highest);
}

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*smallest;
	int		small;

	if (!stack)
		return (NULL);
	small = INT_MAX;
	while (stack)
	{
		if (stack->nbr < small)
		{
			smallest = stack;
			small = stack->nbr;
		}
		stack = stack->next;
	}
	return (smallest);
}
void	target_in_a(t_stack *stack_a, t_stack *stack_b)
{//b nin a daki hedefini bulacak
	t_stack	*tmp_a;
	int		small_target;

	while (stack_b)
	{
		small_target = INT_MAX;
		tmp_a = stack_a;
		while (tmp_a)
		{
			if (tmp_a->nbr > stack_b->nbr
				&& small_target > tmp_a->nbr)
			{
				small_target = tmp_a->nbr;
				stack_b->target = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (small_target == INT_MAX)
			stack_b->target = find_smallest(stack_a);
		stack_b = stack_b->next;
	}
}
void	target_in_b(t_stack *stack_a, t_stack *stack_b)
{//a nın b deki hedefi bulunacak
	t_stack	*tmp_b;
	int		big_target;

	while (stack_a)
	{
		big_target = INT_MIN;
		tmp_b = stack_b;
		while (tmp_b)
		{
			if (stack_a->nbr > tmp_b->nbr
				&& big_target < tmp_b->nbr)
			{
				big_target = tmp_b->nbr;
				stack_a->target = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (big_target == INT_MIN)
			stack_a->target = find_highest(stack_b);
		stack_a = stack_a->next;
	}
}
