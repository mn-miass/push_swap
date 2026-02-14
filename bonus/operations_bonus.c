#include "checker_bonus.h"

void    swap(t_list **a)
{
    t_list  *tmp;

    tmp = *a;
    *a = (*a) -> next;
    tmp = (*a) -> next -> next;
    (*a) -> next = tmp;
}

void    rotate(t_list **a)
{
    t_list *tmp;

    tmp = *a;
    while (tmp -> next)
        tmp = tmp -> next;
    tmp -> next = *a;
    *a = tmp;
    tmp -> next -> next = NULL;
}

