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
        while (head) // changed from head -> next to head i need to check the last node as well else it will be skipped
        {
            if ((min > (head->value)) && (head -> index == 0))
                min = head->value;
            head = head -> next;
        }
        head = tmp;
        while (head)
        {
            if (head -> value == min)
            {
                head -> index = i;
                break;
            }
            head = head -> next;
        }
        i++;
    }
}
