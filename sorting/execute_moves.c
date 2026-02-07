#include "../push_swap.h"

void    execute_rotation(t_list **a, t_list **b)
{
    t_list  *to_rotate_a;
    t_list  *to_rotate_b;

    to_rotate_b = find_cheapest(*b);
    to_rotate_a = to_rotate_b -> target;
    while ((*a) != to_rotate_a)
    {
        if (to_rotate_a -> direction == 1)
        {
            ra(a);
            write(1, "ra\n", 3);
        }
        else
        {
            rra(a);
            write(1, "rra\n", 4);
        }
    }
    while ((*b) != to_rotate_b)
    {
        if (to_rotate_b -> direction == 1)
        {
            rb(b);
            write(1, "rb\n", 3);
        }
        else
        {
            rrb(b);
            write(1, "rrb\n", 4);
        }
    }
    pa(a, b);
    write (1, "pa\n", 3);
}
