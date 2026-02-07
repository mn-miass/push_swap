#include "../push_swap.h"

t_list    *is_smaller(t_list *a)
{
    long long int       min;
    t_list              *min_node;

    min_node = NULL;
    min = INT_MAX + 1;
    while (a)
    {
        if (a -> value < min)
        {
            min = a -> value;
            min_node = a;
        }
        a = a -> next ;
    }
    min_node -> is_smaller = 1;
    return (min_node);
}
