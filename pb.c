#include "push_swap.h"

void    pb(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *tmp;

    tmp = *a;
    *a = (*a) -> next;
    tmp -> next = *b;
    *b = tmp;
}
