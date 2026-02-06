/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:59:31 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/06 11:25:40 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    rra(t_list **a)
{
    t_list  *tmp;

    tmp = *a;
    while ((tmp -> next) -> next)
        tmp = tmp -> next;
    (tmp -> next) -> next = *a;
    *a = tmp -> next;
    tmp -> next = NULL;
}
