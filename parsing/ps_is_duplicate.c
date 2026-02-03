/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_is_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:15:14 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/03 12:37:11 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool    ps_is_duplicate(t_list *a)
{
    int     value;
    t_list  *tmp;

    while (a)
    {
        value = a -> value;
        tmp = a -> next;
        while(tmp)
        {
            if (tmp -> value == value)
                return 1;
            tmp = tmp -> next;
        }
        a = a -> next;
    }
    return 0;
}
