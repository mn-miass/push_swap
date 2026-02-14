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

void    apply_operations(t_list *a, t_list *b, char *str)
{
    if (ps_cmp(str, "pa"))
        push(a);
    else if (ps_cmp(str, "pb"))
        push(b);
    else if (ps_cmp(str, "sa"))
        swap(a);
    else if (ps_cmp(str, "sb"))
        swap(b);
    else if (ps_cmp(str, "ss"))
    {
        swap(a);
        swap(b);
    }
    else if (ps_cmp(str, "ra"))
        rotate(a);
    else if (ps_cmp(str, "rb"))
        rotate(b);
    else if (ps_cmp(str, "rr"))
    {
        rotate(a);
        rotate(b);
    }
    else if (ps_cmp(str, "rra"))
        reverse_rotate(a);
    else if (ps_cmp(str, "rrb"))
        reverse_rotate(b);
    else if (ps_cmp(str, "rrr"))
    {
        reverse_rotate(a);
        reverse_rotate(b);
    }
    else
        error();
}
