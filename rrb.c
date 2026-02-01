#include "push_swap.h"

void    rrb(t_stack_node **b)
{
    t_stack_node    *tmp;

    tmp = *b;
    while ((tmp -> next) -> next) // go to the right befor the last one
        tmp = tmp -> next;
    (tmp -> next) -> next = *b; //the last one point to first one
    *b = tmp -> next; // the head is assigned to the first one(the old last one)
    tmp -> next = NULL;
}
