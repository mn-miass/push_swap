/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 09:40:45 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/07 10:38:28 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list  *biggest_smallest(t_list *a, int i)
{
    t_list  *target;

    target = NULL;
    while (a)
    {
        if (a -> index > i)
            if (!target || target -> index > a -> index)
                target = a;
        a = a -> next;
    }
    return (target);
}

void    set_target(t_list *a, t_list *b)
{
    is_bigger(b);
    while (b)
    {
        b -> target = biggest_smallest(a, b -> index);
        b = b -> next;
    }
}
