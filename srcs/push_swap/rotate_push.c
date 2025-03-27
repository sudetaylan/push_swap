#include "push_swap.h"

int	do_rarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c && (*b)->nbr != (*a)->target->nbr)
			r_rr(a, b, 0, 0);
		while ((*a)->nbr != c)
			ra(a, 0);
		while ((*b)->nbr != (*a)->target->nbr)
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while ((*b)->nbr != c && (*a)->nbr != (*b)->target->nbr)
			r_rr(a, b, 0, 0);
		while ((*b)->nbr != c)
			rb(b, 0);
		while ((*a)->nbr != (*b)->target->nbr)
			ra(a, 0);
		pa(a, b, 0);
	}
    put_index(a);
    put_index(b);
	return (-1);
}

int	do_rrarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c && (*b)->nbr != (*a)->target->nbr)
			r_rr(a, b, 0, 1);
		while ((*a)->nbr != c)
			rra(a, 0);
		while ((*b)->nbr != (*a)->target->nbr)
			rrb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while ((*b)->nbr != c && (*a)->nbr != (*b)->target->nbr)
			r_rr(a, b, 0, 1);
		while ((*b)->nbr != c)
			rrb(b, 0);
		while ((*a)->nbr != (*b)->target->nbr)
			rra(a, 0);
		pa(a, b, 0);
	}
    put_index(a);
    put_index(b);
	return (-1);
}
int do_rrarb(t_stack **a, t_stack **b, int c, char s)
{
    if (s == 'a')
    {
        while ((*a)->nbr != c)//a nın başındaki cheapest değilse sürekl, aşağı kaydır
            rra(a, 0);
        while ((*b)->nbr != (*a)->target->nbr)// b nin başındaki a nın hedefi değilse yukarı kaydır
            rb(b, 0);
        pb(a, b, 0);// b ye yolla
    }
    else
    {
        while ((*a)->nbr != (*b)->target->nbr)//a nın başındaki b nin hedefi değilse aşağı kaydır
            rra(a, 0);
        while ((*b)->nbr != c)
            rb(b, 0);//b nin başındaki cheapest değilsse yukarı kaydır
        pa(a, b, 0);//a ya yolla
    }
    put_index(a);
    put_index(b);
    return (-1);
}

int	do_rarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')//b ye yollarken
	{
		while ((*a)->nbr != c)
			ra(a, 0);//a stackinin başındaki cheapest olmadığı sürece nodeları bir yukarı kaydor
		while ((*b)->nbr != (*a)->target->nbr)
			rrb(b, 0);//b stack başında hedef olmadığı surece nodeları bir aşağı kaydır
		pb(a, b, 0);//b ye yolla
	}
	else// a ya yollarken
	{
		while ((*a)->nbr != (*b)->target->nbr)//a nın başındaki b nin hedefi değilse a stackini yuları kaydı
			ra(a, 0);
		while ((*b)->nbr != c)
			rrb(b, 0);//b stackinin en üstündeki cheapest değilse aşağı kaydır
		pa(a, b, 0);//a ya yolla
	}
    put_index(a);
    put_index(b);
	return (-1);
}