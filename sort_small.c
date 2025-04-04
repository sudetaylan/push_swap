
#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	t_stack	*biggest_node;

	biggest_node = find_highest(*stack_a);
	if (biggest_node == *stack_a)
		ra(stack_a, 0);
	else if ((*stack_a)->next == biggest_node)
		rra(stack_a, 0);
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		sa(stack_a, 0);
}

void	tiny_sort(t_stack **stack_a, int len)
{
	if (len == 2)
		sa(stack_a, 0);
	else if (len == 3)
		sort_three(stack_a);
}

void	handle_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = list_size(*stack_a);
	if (len <= 3)
		tiny_sort(stack_a, len);
	else
		big_sort(stack_a, stack_b);
}
