#include "push_swap.h"

void    rb(t_stack_node **b)
{
    t_stack_node    *tmp;

    tmp = *b;
    while (tmp -> next)
        tmp = tmp -> next;
    tmp -> next = *b;
    *b = ((*b) -> next);
    (tmp -> next) -> next = NULL;
}
