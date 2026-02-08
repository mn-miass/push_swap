/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:16:56 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/08 09:17:19 by mn-miass         ###   ########.fr       */
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
