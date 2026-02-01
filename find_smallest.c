#include "push_swap.h"

t_stack_node    *find_smallest(t_stack_node *a)
{
    int             index;
    t_stack_node    *smallest;
 
    index = INT_MAX;
    while (a)
    {
        if (a -> index < index)
        {
            smallest = a;
            index = a -> value;
        }
        a = a -> next;
    }
    return smallest;
}
