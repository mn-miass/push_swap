#include "push_swap.h"

// i needed to pass the first parameter as double poiter to modify the head pointer in case its null
// tmp was a heleped variable so i can loop in the list without modifying the head value

void ps_add_back(t_stack_node **head, t_stack_node *new)
{
    t_stack_node *tmp;

    tmp = *head;
    if (*head == NULL)
    {
        *head = new;
        return ;
    }
    while (tmp -> next)
        tmp = tmp -> next;
    tmp -> next = new;
}
