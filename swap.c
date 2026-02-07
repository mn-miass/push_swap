#include "push_swap.h"

void    ss(t_list **a, t_list **b)
{
    sa(a);
    sb(b);
}

void    sb(t_list **b)
{
    t_list  *tmp;

    tmp = *b;
    *b = (*b) -> next;
    tmp -> next = (*b) -> next;
    (*b) -> next = tmp;
}

void    sa(t_list   **a)
{
    t_list  *tmp;

    tmp = *a;
    (*a) = (*a) -> next;
    tmp -> next = (*a) -> next;
    (*a) -> next = tmp;
}
