/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bigger.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:06:45 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/06 15:10:50 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    is_bigger(t_list *a)
{
    int     max_value;
    t_list  *biggest_node;

    max_value = INT_MIN;
    biggest_node = NULL;
    while (a)
    {
        if (a -> value > max_value)
        {
            max_value = a -> value;
            biggest_node = a;
        }
        a = a -> next;
    }
    biggest_node -> is_bigger = true;
}
