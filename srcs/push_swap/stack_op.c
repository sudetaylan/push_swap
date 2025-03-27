/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sude <sude@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:03:46 by staylan           #+#    #+#             */
/*   Updated: 2025/03/27 04:07:24 by sude             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_stack **a, int k)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next))
		return ;
	tmp = *a;// tmp head node u işaret edicek
	*a = (*a)->next;// head node artık head node dan sonraki oldu
	tmp->next = (*a)->next;//önceki head node un nexti artık eskiden 2. olanın nexti olmalı
	(*a)->next = tmp;  //yeni head node un sonraki elemanı ilk head node olmalı, onu da tmp de tutuyoruz
	if (k == 0)
		write(1, "sa\n", 3);
}
void	sb(t_stack **b, int k)
{
	t_stack *tmp;

	if (!*b)
		return ;
	if((*b)->next)
	{
		tmp = *b; // tmp head node u işaret edicek
		*b = (*b)->next; // head node artık head node dan sonraki oldu
		tmp->next = (*b)->next; //önceki head node un nexti artık eskiden 2. olanın nexti olmalı
		(*b)->next = tmp; //yeni head node un sonraki elemanı ilk head node olmalı, onu da tmp de tutuyoruz
	}
	else
		return ;
	if (k == 0)
		write(1, "sb\n", 3);
}
void	ss(t_stack **a, t_stack **b, int k)
{
	sa(a, 1);
	sb(b, 1);
	if(k == 0)
		write(1, "ss\n", 3);
}

void	pa(t_stack **a, t_stack **b, int k)
{
	t_stack *tmp;

	if(!*b)
		return ;
	tmp = *a; //tmp değişkeni a nın adresini tutuyor
	*a = *b; //a nın başlagıncındaki nod b oldu artık içerisindeki değerlerle beraber
	*b = (*b)->next; // b stackinin head node u artık başta 2. sırada olan oldu
	(*a)->next =tmp; // artık baştakı a stackindeki head olan node 2. sıraya geçti
	if(k == 0)
		write(1, "pa\n", 3);
}
void	pb(t_stack **a, t_stack **b, int k)
{
	t_stack *tmp;

	if(!*a)
		return ;
	tmp = *b; //tmp değişkeni b nın adresini tutuyor
	*b = *a; //b nın başlagıncındaki node a oldu artık içerisindeki değerlerle beraber
	*a = (*a)->next; // a stackinin head node u artık başta 2. sırada olan oldu
	(*b)->next =tmp; // artık baştakı b stackindeki head olan node 2. sıraya geçti
	if(k == 0)
		write(1, "pb\n", 3);
}
