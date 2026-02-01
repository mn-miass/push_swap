#include "push_swap.h"

void    sort_3(t_stack_node *a)
{
    t_stack_node *big;
    t_stack_node *small;

    small = find_smallest(a, 3);
    big = find_biggest(a);
    if (a == big)
    {
        ra(&a);
        write(1, "ra ", 3);
    }
    else if (a -> next == big)
    {
        rra(&a);
        write(1, "rra ", 4);
    }
    if (a -> next == small)
    {
        sa(&a);
        write (1, "sa ", 3);
    }
}