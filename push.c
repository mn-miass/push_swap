#include "../push_swap.h"

void    pa(t_list **a, t_list **b)
{
    t_list  *tmp;

    tmp = *b;
    *b = (*b) -> next;
    tmp -> next = *a;
    *a = tmp;
}


void    pb(t_list **a, t_list **b)
{
    t_list *tmp;

    tmp = *a;
    *a = (*a) -> next;
    tmp -> next = *b;
    *b = tmp;
}
