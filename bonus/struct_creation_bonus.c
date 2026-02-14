#include "checker_bonus.h"

void  add_back(t_list **a, t_list *new)
{
    t_list  *tmp;

    tmp = *a;
    if ((*a) == NULL)
    {
        (*a) = new;
        return ;
    }
    while (tmp -> next)
        tmp = tmp -> next;
    tmp -> next = new;
}

t_list  *creat_node(int val)
{
    t_list  *new;

    new = malloc(sizeof(t_list));
    if (new == NULL)
        return (NULL);
    new -> value = val;
    new -> next = NULL;
    return (new);
}

bool    is_duplicated_bonus(t_list *a)
{
    t_list  *tmp;

    tmp = a -> next;
    while (a)
    {
        while (tmp)
        {
            if (tmp -> value == a -> value)
                return (1);
            tmp = tmp -> next ;
        }
        a = a -> next;
        tmp = a -> next ;
    }
    return 0;
}

t_list      *creat_stract(char  **splited)
{
    t_list  *a;
    int     i;
    int value;

    i = 0;
    while (splited[i])
    {
        value = ps_atoi(splited[i]);
        if (value > INT_MAX)
            return (NULL);
        add_back(&a, creat_node(value));
        i++;
    }
    return (a);
}
bool    is_sorted(t_list *a)
{
    while (a -> next)
    {
        if (a -> value > a -> next -> value)
            return 0;
        a = a -> next;
    }
    return 1;
}

