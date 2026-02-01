#include "push_swap.h"

void    sb(t_stack_node **b)
{
    t_stack_node *tmp;

    tmp = ((*b) -> next) -> next;
    ((*b) -> next) -> next = *b;
    *b = ((*b) -> next);
    ((*b) -> next) -> next = tmp;
}
