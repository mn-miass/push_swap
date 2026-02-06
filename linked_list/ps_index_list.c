/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_index_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:49:09 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/06 12:13:38 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// loop with tmp break if only min_node is NULL else set the index tio its posiion indexes start from 1 to n - 1
// i can improve it later
void    ps_index_list(t_list *a)
{
    int     i;
    int     min;
    t_list  *tmp;
    t_list  *min_node;

    min = INT_MAX;
    min_node = NULL;
    i = 0;
    tmp = a;
    while (tmp)
    {
        if (tmp -> value < min && tmp -> index == -1)
        {
            min = tmp -> value;
            min_node = tmp;
        }
        tmp = tmp -> next;
        if (tmp == NULL)
        {
            if (min_node == NULL)
                break;
            min_node -> index = i++;
            min = INT_MAX;
            min_node = NULL;
            tmp = a;
        }
    }
}
