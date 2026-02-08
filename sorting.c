/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:08:43 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/08 10:03:10 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sorting(t_list **a, t_list **b)
{
    int size;

    size = ps_list_count(*a);
    is_bigger(*a);
    if (size == 2)
    {
        sort_2(a);
        free_stack(a);
        exit(0);
    }
    else if (size == 3)
    {
        sort_3(a);
        free_stack(a);
        exit(0);
    }
    else if (size > 3)
    {
        push_to_b(a, b);
        sort_3(a);
        sort_complex(a, b);
        free_stack(a);
        exit(0);
    }
}
void    sort_complex(t_list **a, t_list **b)
{
    while (*b)
    {
        set_position(*a);
        set_position(*b);
        set_target(*a, *b);
        calculate_cost(*a, *b);
        execute_rotation(a, b);
    }
    final_rotation(a);
}