/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:45:49 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/07 09:18:18 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// need to push
void    push_to_b(t_list **a, t_list **b)
{
    int     median;
    int     size;

    size = ps_list_count(*a);
    median = size / 2;
    while (size > 3)
    {
        if ((*a) -> is_bigger)
        {
            ra(a);
            write (1, "ra\n", 3);
        }
        pb(a, b);
        write (1, "pb\n", 3);
        if ((*b) -> index > median)
        {
            rb(b);
            write (1, "rb\n", 3);
        }
        size--;
    }
}
