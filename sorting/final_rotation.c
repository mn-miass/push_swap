#include "../push_swap.h"

void    final_rotation(t_list **a)
{
    t_list  *min_node;
    int     size;

    size = ps_list_count(*a);
    min_node = is_smaller(*a);

    while ((*a) != min_node)
    {
        if (min_node -> position > size / 2)
        {
            rra(a);
            write (1, "rra\n",4);
        }
        else
        {
            ra(a);
            write(1, "ra\n", 3);
        }
    }
}
