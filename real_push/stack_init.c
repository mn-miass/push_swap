/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:16:47 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/12 17:08:15 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// functions needed
// ps_atoi free2d error ps_new_node

t_list  *ps_new_node(int value)
{
    t_list  *new;

    new = malloc(sizeof (t_list));
    if (new == NULL)
        return (NULL);
    new -> value = value;
    new -> next = NULL;
    new -> index = -1;
    new -> is_bigger = 0;
    new -> is_smaller = 0;
    return (new);
}

t_list  *ps_creat_stack(char **str)
{
    int             i;
    long long int   num;
    t_list          *a;

    i = 0;
    a = NULL;
    while (str[i])
    {
        num = ps_atoi(str[i]);
        if (num >= 2147483648) // still need to check the biggest num DONE
        {
            free_2d(str); // free the stack
            free_stack(&a);
            error();
        }
        ps_add_back(&a, ps_new_node(num));
        i++;
    }
    return (a);
}

void    ps_add_back(t_list **a, t_list *new)
{
    t_list  *tmp;

    tmp = *a;
    if (*a == NULL)
    {
        *a = new;
        return ;
    }
    while (tmp -> next)
        tmp = tmp -> next;
    tmp -> next = new;
}

