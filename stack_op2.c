/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sude <sude@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:03:24 by staylan           #+#    #+#             */
/*   Updated: 2025/03/26 13:48:08 by sude             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_stack **a, int k)
{
    t_stack *tmp;

    if (!*a || !(*a)->next)
        return ;
    tmp = last_node(a); // tmp ye son node un adresini verdik
    tmp->next = *a; // sonuncunun sonrasna a nın başı geleceğ,i için bu işlem yaptık
    *a = (*a)->next;// stackin başı artık 2. elemanı gösteriyor
    (*a)->next = NULL; //en sona a nın en baştakı nodeunu eklemiştik onun nextini 2. ye işaret ederken null a çevirdik
}
void    rb(t_stack **b, int k)
{
    t_stack *tmp;

    if (!*b || !(*b)->next)
        return ;
    tmp = last_node(b); // tmp ye son node un adresini verdik
    tmp->next = *b; // sonuncunun sonrasna b nın başı geleceğ,i için bu işlem yaptık
    *b = (*b)->next;// stackin başı artık 2. elemanı gösteriyor
    (*b)->next = NULL; //en sona b nın en baştakı nodeunu eklemiştik onun nextini 2. ye işaret ederken nulla çevirdik
}
void    r_rr(t_stack **a, t_stack **b, int k, int reverse)
{
    if(reverse == 0)
    {
        ra(a, 1);
        rb(b, 1);
        if (k == 0)
            write(1, "rr\n", 3);
    }
    else
    {
        rra(a, 1);
        rrb(b, 1);
        if (k == 0)
            write(1, "rrr\n", 3);
    }

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
