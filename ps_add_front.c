#include "push_swap.h"

void ps_add_front(t_stack_node **head, t_stack_node *new)
{
    if (*head == NULL)
        *head = new;
    new -> next = *head;
    *head = new;
}
