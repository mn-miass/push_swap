#include "push_swap.h"

void    ra(t_list **a)
{
    t_list  *tmp;

    tmp = *a;
    while (tmp -> next)
        tmp = tmp -> next;
    tmp -> next = *a;
    *a = (*a) -> next;
    (tmp -> next) -> next = NULL;
}


void    ra(t_list **a)
{
    t_list  *tmp;

    tmp = *a;
    while (tmp -> next)
        tmp = tmp -> next;
    tmp -> next = *a;
    *a = (*a) -> next;
    (tmp -> next) -> next = NULL;
}


void    rr(t_list **a, t_list **b)
{
    ra(a);
    rb(b);
}
