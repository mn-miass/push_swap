#include    "push_swap.h"

int     ps_count_nodes(t_stack_node* head)
{
    int i;

    i = 0;
    while (head)
    {
        i++;
        head = head -> next;
    }
    return i;
}
