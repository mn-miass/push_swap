/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_set_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 10:40:19 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/07 10:47:59 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int     set_position(t_list *a, int index)
{
    int i;

    i = 0;
    while (a)
    {
        if (a -> index == index)
            return (i);
        i++;
        a = a -> index;
    }
    return (i);
}

