#include "push_swap.h"

t_stack_node    *find_biggest(t_stack_node *a)
{
    int             index;
    t_stack_node    *biggest;
 
    index = 0;
    while (a)
    {
        if (a -> index > index)
        {
            biggest = a;
            index = a -> value;
        }
        a = a -> next;
    }
    return biggest;
}
