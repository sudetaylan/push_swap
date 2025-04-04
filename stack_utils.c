
#include "push_swap.h"

t_stack	*new_stack(int content)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (!new)
		ft_error();
	new->nbr = content;
	new->next = NULL;
	return (new);
}

void	add_back(t_stack **stack, t_stack *new_node)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = new_node;
	else
		(last_node(*stack))->next = new_node;
}

int	is_sorted(t_stack **stack_a)
{
	t_stack	*t;

	t = *stack_a;
	while (t->next)
	{
		if (t->nbr < t->next->nbr)
			t = t->next;
		else
			return (0);
	}
	return (1);
}
t_stack	*last_node(t_stack *list)
{
	if (list == NULL)
		return (0);
	while (list)
	{
		if (list->next == NULL)
			return (list);
		list = list->next;
	}
	return (list);
}

int	list_size(t_stack *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
