#include "push_swap.h"

void    sa(t_stack_node **a)
{
    t_stack_node *tmp ;

    tmp = ((*a) -> next) -> next; // save the third
    ((*a) -> next) -> next = *a; // the second point to first the third not lost
    *a = (*a) -> next ; // the head point to second so the second is first the oint to old first
    ((*a) -> next) -> next = tmp; // the old first now point to the third 
}
