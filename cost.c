/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:17:33 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/07 17:17:34 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void    calculate_cost(t_list *a, t_list *b)
{
    int size_a ;
    int size_b ;

    size_a = ps_list_count(a);
    size_b = ps_list_count(b);
    while (b)
    {
        if (b -> position < size_b / 2)
        {
            b -> direction = 1;
            b -> cost = b -> position;
        }
        else
        {
            b -> direction = -1;
            b -> cost = size_b - b -> position;
        }
        if ((b -> target) -> position < size_a / 2)
        {
            (b -> target) -> direction = 1 ;
            b -> cost += (b -> target) -> position;
        }
        else
        {
            (b -> target) -> direction = -1;
            b -> cost += size_a - (b -> target) -> position;
        }
        b = b -> next ;
    }
}
