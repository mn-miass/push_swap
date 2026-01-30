#include "push_swap.h"

t_stack_node    *ps_creat_node(int value)
{
    t_stack_node *new;

    new = malloc(sizeof(t_stack_node));
    if (new == NULL)
        return (NULL);
    new -> value = value;
    new -> next = NULL;
    new -> is_max = 0;
    new -> is_min = 0;
    new -> index = 0;
    return (new);
}
