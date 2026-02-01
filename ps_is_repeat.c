#include "push_swap.h"

// 1 number exist 0 number ont exist
bool    node_exist(t_stack_node *head, int i)
{
    if (head == NULL)
        return 0;
    while (head)
    {
        if (head -> value == i)
            return 1;
        head = head -> next;
    }
    return 0;
}
