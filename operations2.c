#include "push_swap.h"

void	ra(t_stack **a, int k)
{
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = last_node(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	if (k == 0)
		write(1, "ra\n", 3);
}

void    rb(t_stack **b, int k)
{
	t_stack	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = last_node(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (k == 0)
		write(1, "rb\n", 3);
}

void    rra(t_stack **a, int k)
{
	t_stack	*tmp;
	int		i;

	if (!*a || !(*a)->next)
		return ;
	i = 0;
	tmp = *a; // tmp değişkenine başlangıç nodeunun adresi
	while ((*a)->next)
	{
		*a = (*a)->next;//son nnode a gelene kadar ilerler ve kaç tane ilerlediğini i ile sayar
		i++;// i bu durumda stack uzunluğunun bir eksiğine eşit olur
	}
	(*a)->next = tmp;// son nodun next ine  baştaki başlangıcın adresine atar
	while (i > 1)
	{
		tmp = tmp->next; // ilk başta sonuncunun bir önünde olana gider
		i--;// stack uzunluğunun 2 eksiği kadar ilerledik baştaki elemandan o kadar ilerlediğimizde sondan öncekine ulaşıyoruz.
	}
	tmp->next = NULL;// baştaki durumda sondan bir öncekinin sonrasına (hala ilk baştaki halin sonuncusunu işaret ediyordu) null işerat ediyor artık
	if (k == 0)
		write(1, "rra\n", 4);
}

void    rrb(t_stack **b, int k) 
{// sadece b stackinde aynı işlmei yap
	t_stack	*tmp;
	int		i;

	if (!*b || !(*b)->next)
		return ;
	i = 0;
	tmp = *b;
	while ((*b)->next)
	{
		*b = (*b)->next;
		i++;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (k == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int k)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	if (k == 0)
		write(1, "rrr\n", 4);
}
