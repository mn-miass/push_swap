#include "push_swap.h"

void    rra(t_stack_node **a)
{
    t_stack_node    *tmp;

    tmp = *a;
    while ((tmp -> next) -> next)
        tmp = tmp -> next;
    (tmp -> next) -> next = *a;
    *a = tmp -> next;
    tmp -> next = NULL;
}

