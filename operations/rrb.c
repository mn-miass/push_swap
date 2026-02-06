/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:54:50 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/06 11:01:05 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    rrb(t_list **b)
{
    t_list  *tmp;

    tmp = *b;
    while ((tmp -> next) -> next)
        tmp = tmp -> next;
    (tmp -> next) -> next = *b;
    *b = tmp -> next;
    tmp -> next = NULL;
}
