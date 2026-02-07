#include "../push_swap.h"

t_list  *find_cheapest(t_list *a)
{
    t_list  *tmp;

    tmp = NULL;
    while (a)
    {
        if (!tmp || tmp -> cost > a -> cost)
            tmp = a;
        a = a -> next;
    }
    return (tmp);
}
