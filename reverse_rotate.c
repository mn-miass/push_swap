#include "push_swap.h"

void    rra(t_list **a)
{
    t_list  *tmp;

    tmp = *a;
    while ((tmp -> next) -> next)
        tmp = tmp -> next;
    (tmp -> next) -> next = *a;
    *a = tmp -> next;
    tmp -> next = NULL;
}

void    rrb(t_list **b)
{
    t_list  *tmp;

    tmp = *b;
    while ((tmp -> next) -> next)
        tmp = tmp -> next;
    (tmp -> next) -> next = *b;
    *b = tmp -> next;
    tmp -> next = NULL;
}

void    rrr(t_list **a, t_list **b)
{
    rra(a);
    rrb(b);
}
