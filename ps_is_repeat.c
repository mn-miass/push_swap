#include "push_swap.h"

// 1 number exist 0 number ont exist
bool    node_exist(t_stack_node *head, int value)
{
    if (head == NULL)
        return 1;
    while (head -> next)
    {
        if (head -> value == value)
            return 1;
    }
    return 0;
}
