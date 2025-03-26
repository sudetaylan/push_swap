#include "push_swap.h"

void	free_str(char **str)
{
	char	*n1;

	if (!str)
		return ;
	while (*str)
	{
		n1 = *str;
		str++;
		free(n1);
	}
	*str = NULL;
}
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		(*stack)->nbr = 0;
		free(*stack);
		*stack = tmp;
	}
}
