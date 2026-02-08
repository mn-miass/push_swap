/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:17:06 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/08 09:27:16 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void    push(t_list **a, t_list **b)
{
    t_list  *tmp;

    tmp = *a;
    *a = (*a) -> next;
    tmp -> next = *b;
    *b = tmp;
}

void    pa(t_list **a, t_list **b)
{
    push(b, a);
    write(1, "pa\n", 3);
}

void    pb(t_list **a, t_list **b)
{
    push(a, b);
    write(1, "pb\n", 3);       
}