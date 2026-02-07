/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:40:36 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/06 17:54:52 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
