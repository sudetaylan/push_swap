#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
int	find_max(t_stack *a)
{
	int		max;
	int		i;

	max = a->nbr;
	i = a->index;
	while (a)
	{
		if (a->nbr > max)
		{
			i = a->index;
			max = a->nbr;
		}
		a = a->next;
	}
	return (i);
}

int	find_min(t_stack *a)
{
	int		min;
	int		i;

	min = a->nbr;
	i = a->index;
	while (a)
	{
		if (a->nbr < min)
		{
			min = a->nbr;
			i = a->index;
		}
		a = a->next;
	}
	return (i);
}
void	sort_three(t_stack **stack_a)
{	
	put_index(stack_a);
	if (find_min(*stack_a) == 0)
	{
		rra(stack_a, 0);
		sa(stack_a, 0);

	}
	else if (find_max(*stack_a) == 0)
	{
		ra(stack_a, 0);
		if (!is_sorted(*stack_a))
			sa(stack_a, 0);
	}
	else
	{
		if (find_max(*stack_a) == 1)
			rra(stack_a, 0);	
		else
			sa(stack_a, 0);
	}
}


