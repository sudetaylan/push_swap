
#include "push_swap.h"

void	do_rr(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rr(a, b, 0);
	put_index(*a);
	put_index(*b);
}

void	do_rrr(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rrr(a, b, 0);
	put_index(*a);
	put_index(*b);
}

void	align_top(t_stack **stack, t_stack *top, char s)
{
	while (*stack != top)
	{
		if (s == 'a')
		{
			if (top->above_median)
				ra(stack, 0);
			else
				rra(stack, 0);
		}
		else if (s == 'b')
		{
			if (top->above_median)
				rb(stack, 0);
			else
				rrb(stack, 0);
		}
	}
}

