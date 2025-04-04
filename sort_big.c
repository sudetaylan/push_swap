#include "push_swap.h"

static void	sort_till3(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*stack_a);
	if (cheapest->above_median && cheapest->target->above_median)
		do_rr(stack_a, stack_b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		do_rrr(stack_a, stack_b, cheapest);
	align_top(stack_a, cheapest, 'a');
	align_top(stack_b, cheapest->target, 'b');
	pb(stack_a, stack_b, 0);
}
static void push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	a_len;

	a_len = list_size(*stack_a);
	if (a_len-- > 3 && !is_sorted(stack_a))
		pb(stack_a, stack_b, 0);
	if (a_len-- > 3 && !is_sorted(stack_a))
		pb(stack_a, stack_b, 0);
	while(a_len--> 3 && !is_sorted(stack_a))
	{
		init_a(*stack_a, *stack_b);
		sort_till3(stack_a, stack_b);		
	}
}

static void	push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
	{
		init_b(*stack_a, *stack_b);
		align_top(stack_a, (*stack_b)->target, 'a');
		pa(stack_a, stack_b, 0);
	}
}

static void	bring_min_top(t_stack **stack_a)
{
	t_stack *min;

	min = find_smallest(*stack_a);
	while (*stack_a != min)
	{
		if (min->above_median)
			ra(stack_a, 0);
		else
			rra(stack_a, 0);
	}
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	push_to_b(stack_a, stack_b);
	if(!is_sorted(stack_a))
		sort_three(stack_a);
	push_to_a(stack_a, stack_b);
	put_index(*stack_a);
	bring_min_top(stack_a);
}
