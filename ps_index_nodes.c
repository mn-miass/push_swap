#include "push_swap.h"

// i need function that count the number of nodes (done)
// need to iprove it later checking 

void    ps_index_nodes(t_stack_node *head, int len)
{
    int i = 1;
    int min = INT_MAX;
    t_stack_node *tmp = head;

    while (i <= len)
    {
        min = INT_MAX;
        head = tmp;
        while (head -> next)
        {
            if (min < head->value && (head -> index = 0))
                min = head->value;
            head = head -> next;
        }
        min = INT_MAX;
        head = tmp;
        while (head -> next)
        {
            if (head -> value == min)
                head -> index = i;
            head = head -> next;
            break;
        }
        i++;
    }
}
