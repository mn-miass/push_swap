#include <../push_swap.h>

void    calculate_cost(t_list *a, t_list *b)
{
    int size_a ;
    int size_b ;

    size_a = ps_list_count(a);
    size_b = ps_list_count(b);
    while (b)
    {
        if (b -> position < size_b / 2)
        {
            b -> direction = 1;
            b -> cost = b -> position;
        }
        else
        {
            b -> direction = -1;
            b -> cost = size_b - b -> position;
        }
        if ((b -> target) -> position < size_a / 2)
        {
            (b -> target) -> direction = 1 ;
            b -> cost += (b -> target) -> position;
        }
        else
        {
            (b -> target) -> direction = -1;
            b -> cost += size_a - (b -> target) -> position;
        }
        b = b -> next ;
    }
}
