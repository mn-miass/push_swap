/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:45:49 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/06 15:53:34 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    push_to_b(t_list **a, t_list **b)
{
    t_list  *tmp;

    tmp = *a;
    while (((tmp -> next) -> next) -> next)
    {
        if (tmp -> is_bigger)
            ra(a);
        pb(a, b);
        tmp = tmp -> next;
    }
}
