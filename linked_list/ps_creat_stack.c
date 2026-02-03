/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_creat_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:09:13 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/03 12:03:53 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

t_list  *ps_creat_stack(char **str)
{
    int             i;
    long long int   num;
    t_list          *a;

    i = 0;
    a = NULL;
    while (str[i])
    {
        num = ps_atoi(str[i]);
        if (num > INT_MAX || num < INT_MIN)
        {
            free_2d(str);
            error();
        }
        ps_add_back(&a, ps_new_node(num));
        i++;
    }
    return (a);
}
