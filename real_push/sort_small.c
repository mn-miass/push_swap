/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:16:56 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/08 19:34:32 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_3(t_list **a)
{
    if ((*a) -> is_bigger)
        ra(a);
    if (((*a) -> next) -> is_bigger)
        rra(a);
    if ((*a) -> index > ((*a) -> next) -> index)
        sa(a);
}

void    sort_2(t_list **a)
{
    if ((*a) -> is_bigger)
        sa(a);
}

void is_sorted(t_list **a)
{
    t_list  *tmp;

    tmp = *a;
    while (tmp -> next)
    {
        if (tmp -> value > (tmp -> next) -> value)
            return ;
        tmp = tmp -> next;
    }
    free_stack(a);
    exit(0);
}

void    sort_5(t_list **a, t_list **b)
{
    t_list  *small;

    while (ps_list_count(*a) > 3)
    {
        set_position(*a);
        small = is_smaller(*a);
        while ((*a) != small)
        {
            if (small -> position < 2)
                ra(a);
            else
                rra(a);
        }
        pb(a, b);
    }
    sort_3(a);
    pa(a, b);
    pa(a, b);
}
