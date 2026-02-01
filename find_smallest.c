#include "push_swap.h"

t_stack_node    *find_smallest(t_stack_node *a)
{
    int             index;
    t_stack_node    *smallest;
 
    index = INT_MAX;
    while (a -> next)
    {
        if (a -> value < index)
        {
            smallest = a;
            index = a -> value;
        }
        a = a -> next;
    }
    return smallest;
}
