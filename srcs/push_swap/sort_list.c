#include "push_swap.h"
#include <unistd.h>

t_stack	**sort_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *cheapest;

    while (*stack_b)
    {
		target_b(stack_a, stack_b);//her node un hedefi belirlendi
        cost(stack_b, stack_a);//her node üzerinde işlem için maliyet hesabı yapıldı
        cheapest = find_cheapest(stack_b);//bu işlemlerden en az maliyetlisi bulundu
        if (cheapest->index < (list_size(*stack_b)/ 2)
			&& cheapest->target->index < (list_size(*stack_a)/ 2))//ortanın üstündeyseler
        	    do_rarb(stack_a, stack_b,cheapest->nbr , 'b');
        else if ((cheapest->index >= (list_size(*stack_b) / 2))//ortanın altınsalar
			&& (cheapest->target->index >= (list_size(*stack_a) / 2)))
            do_rrarrb(stack_a, stack_b,cheapest->nbr ,'b');	
        else if (cheapest->index < (list_size(*stack_b)/ 2) 
			&& cheapest->target->index >= (list_size(*stack_a) / 2))// b ortanın üstünde a altında
            do_rrarb(stack_a, stack_b, cheapest->nbr, 'b');
        else if (cheapest->index >= (list_size(*stack_b) / 2)// a ortanın üstünde b altında
			&& cheapest->target->index < (list_size(*stack_a)/ 2))
            do_rarrb(stack_a, stack_b, cheapest->nbr, 'b');
	}
	return (stack_a);
}

void sort_till3_b(t_stack **stack_a, t_stack **stack_b)//a dan b ye
{
    t_stack *cheapest;


    while (list_size(*stack_a) > 3 && !is_sorted(*stack_a))
    {
		target_a(stack_a,stack_b);//her node un hedefi belirlendi	
        cost(stack_a, stack_b);//her node üzerinde işlem için maliyet hesabı yapıldı
        cheapest = find_cheapest(stack_a);//bu işlemlerden en az maliyetlisi bulundu,
        if (cheapest->cost == cheapest->index + cheapest->target->index)//ortanın üstündeyseler
            do_rarb(stack_a, stack_b, cheapest->nbr, 'a');
        else if (cheapest->cost == (list_size(*stack_a) - cheapest->index + (list_size(*stack_b) - cheapest->target->index)))//ortanın altınsalar
            do_rrarrb(stack_a, stack_b, cheapest->nbr, 'a');
        else if (cheapest->cost == cheapest->index + (list_size(*stack_b) - cheapest->target->index))// a ortanın üstünde b altında
            do_rarrb(stack_a, stack_b, cheapest->nbr, 'a');
        else if (cheapest->cost == (list_size(*stack_a) - cheapest->index + cheapest->target->index)) // b ortanın üstünde a altında
            do_rrarb(stack_a, stack_b, cheapest->nbr, 'a');
	}
}

t_stack	*sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (list_size(*stack_a) > 3 && !is_sorted(*stack_a))// 3 ten büyükse ve sıralı değilse 1tane gönder
		pb(stack_a, &stack_b, 0);
	if (list_size(*stack_a) > 3 && !is_sorted(*stack_a))//3ten büyük ve sıralı değilse 2. yi gönder
		pb(stack_a, &stack_b, 0);
	if (list_size(*stack_a) > 3 && !is_sorted(*stack_a))// a 3 olana kadar hedef belirleyip atma işlemi
		sort_till3_b(stack_a, &stack_b);//a da 3 tane kalan akadar uygun yerlere değerleri at
	if (!is_sorted(*stack_a))
		sort_three(stack_a);// üç tane kaldığında sıralı değilse
	return (stack_b);
}

void	sort_list(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (list_size(*stack_a) == 2)
		sa(stack_a, 0);// sadece iki eleman varsa değiştirerek direkt sırrala
	else
	{
		stack_b = sort_b(stack_a);//a dakileri b ye atma işlemi
		write(1, "\nbitti kardes a dan b ye\n", 26);
		stack_a = sort_a(stack_a, &stack_b);
		write(1, "\nb den a ya\n" , 13);
		put_index(stack_a);
		i = find_min(*stack_a);
		if (i < list_size(*stack_a) / 2)
		{
			while (i-- != 0)
				ra(stack_a, 0);		
		}
		else
		{
			while (i++ < list_size(*stack_a))
				rra(stack_a, 0);
		}
	}
}
