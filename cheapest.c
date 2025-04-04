#include "push_swap.h"

void	find_cost(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *tmp;
    int cost = 0;

    tmp = stack_a;
    while (tmp && tmp->target)
    {
        if (tmp->above_median)
            tmp->cost = tmp->index;
        else
            tmp->cost = list_size(stack_a) - tmp->index;
        if (tmp->target->above_median)
                cost = tmp->target->index;
        else
                cost = list_size(stack_b) - tmp->target->index;
        if(cost > tmp->cost)
            tmp->cost = cost;
        tmp = tmp->next;
    }
}

t_stack *get_cheapest(t_stack *stack)
{
    t_stack *tmp;
    t_stack *cheapest;

    cheapest = stack;
    tmp = stack->next;
    while (tmp)
    {
        if (cheapest->cost == 0){
            return (cheapest);            
        }
        else
        {
            if (cheapest->cost > tmp->cost)
                cheapest = tmp;
            tmp = tmp->next;
        }
    }
    return (cheapest);
}
