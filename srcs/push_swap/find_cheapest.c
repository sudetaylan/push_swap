#include "push_swap.h"

void put_index(t_stack **stack)
{
    t_stack *tmp;
    int i;

    if (!*stack)
        return;
    tmp = *stack;
    i = 0;
    while (tmp)
    {
        tmp->index = i;
        tmp = tmp->next;
        i++;
    }
}

void cost(t_stack **stack1, t_stack **stack2)
{
    t_stack *tmp;

    put_index(stack1);
    put_index(stack2);
    tmp = *stack1;
    while (tmp)
    {
        if (tmp->index <= (list_size(*stack1) / 2))
            tmp->cost = tmp->index;
        else
            tmp->cost = (list_size(*stack1) - tmp->index);
        if (tmp->target->index <= (list_size(*stack2) / 2))
                tmp->cost += tmp->target->index;            
        else
            tmp->cost += (list_size(*stack2) - tmp->target->index);
        tmp = tmp->next;
    }
}
t_stack *find_cheapest(t_stack **stack)
{
    t_stack *tmp;
    t_stack *cheapest;

    cheapest = *stack;
    tmp = (*stack)->next;
    while (tmp)
    {
        if (cheapest->cost == 0)
            return (cheapest);
        else
        {
            if (cheapest->cost > tmp->cost)
                cheapest = tmp;
            tmp = tmp->next;
        }
    }
    return (cheapest);
}