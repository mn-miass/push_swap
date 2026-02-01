#include "push_swap.h"

// store the first node the second will be the head the first will put to the first of the other stack and then the head will be the first
void    pa(t_stack_node **a)
{
    t_stack_node *tmp;

    tmp = *b;
    *b = (*b) -> next;
    tmp -> next = *a;
    *a = tmp;
}
