#include "push_swap.h"

void    sort_3(t_list **a)
{
    if ((*a) -> is_bigger)
    {
        ra(a);
        write (1, "ra\n", 3);
    }
    if (((*a) -> next) -> is_bigger)
    {
        rra(a);
        write (1, "rra\n", 4);
    }
    if ((*a) -> index > ((*a) -> next) -> index)
    {
        sa(a);
        write (1, "sa\n", 3);
    }
}

void    sort_3(t_list **a)
{
    if ((*a) -> is_bigger)
    {
        ra(a);
        write (1, "ra\n", 3);
    }
    if (((*a) -> next) -> is_bigger)
    {
        rra(a);
        write (1, "rra\n", 4);
    }
    if ((*a) -> index > ((*a) -> next) -> index)
    {
        sa(a);
        write (1, "sa\n", 3);
    }
}

void is_sorted(t_list **a)
{
    t_list  *tmp;

    tmp = *a;
    while (tmp -> next)
    {
        if (tmp -> value > (tmp -> next) -> value)
            return ;
        tmp = tmp -> next;
    }
    free_stack(a);
    exit(0);
}
