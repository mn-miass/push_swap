#include "checker_bonus.h"

void    swap_bonus(t_list **a)
{
    t_list  *tmp;

    tmp = *a;
    *a = (*a) -> next;
    tmp = (*a) -> next -> next;
    (*a) -> next = tmp;
}
void    rotate_bonus(t_list **a)
{
    t_list  *tmp;

    tmp = *a;
    while (tmp -> next)
        tmp = tmp -> next;
    tmp -> next = *a;
    *a = (*a) -> next;
    tmp -> next -> next = NULL;
}

void    reverse_rotate_bonus(t_list **a)
{
    t_list *tmp;

    tmp = *a;
    while (tmp -> next -> next)
        tmp = tmp -> next;
    tmp -> next -> next = *a;
    *a = tmp -> next ;
    tmp -> next = NULL;
}

void    push_bonus(t_list **a, t_list **b)
{
    t_list  *tmp;

    tmp = *a;
    *a = (*a) -> next ;
    tmp -> next = *b;
    (*b) = tmp;
}
