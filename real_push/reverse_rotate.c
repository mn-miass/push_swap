/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:17:02 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/08 09:27:26 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    reverse_rotate(t_list **a)
{
    t_list  *tmp;

    tmp = *a;
    while ((tmp -> next) -> next)
        tmp = tmp -> next;
    tmp -> next -> next = *a;
    *a = tmp -> next;
    tmp -> next = NULL;
}

void    rra(t_list **a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
}

void    rrb(t_list **b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}

void    rrr(t_list **a, t_list **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}
