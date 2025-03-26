#include "push_swap.h"

t_stack	*find_smallest(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*smallest;
	int		small;

	smallest = *stack;
	small = (*stack)->nbr;
	if (!*stack)
		return (NULL);
	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr
			&& small > tmp->next->nbr)
		{
			smallest = tmp->next;
			small = tmp->next->nbr;
		}
		tmp = tmp->next;
	}
	return (smallest);
}

t_stack	*find_highest(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*highest;
	int	     big;

	highest = *stack;
	big = (*stack)->nbr;
	if (!*stack)
		return (NULL);
	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->nbr < tmp->next->nbr
			&& big < tmp->next->nbr)
		{
			highest = tmp->next;
			big = tmp->next->nbr;
		}
		tmp = tmp->next;
	}
	return (highest);
}