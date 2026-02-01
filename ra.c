#include "push_swap.h"

void    ra(t_stack_node **a)
{
    t_stack_node *tmp;

    tmp = *a;
    while (tmp -> next)
        tmp = tmp -> next; //tmp point to last node
    tmp -> next = (*a); // make tmp point to first instead of NULL
    *a = (*a) -> next; // a point to the second (so it will be the first)
    (tmp -> next) -> next = NULL;  // the old first point to null
}