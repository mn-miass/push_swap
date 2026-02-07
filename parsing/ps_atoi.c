/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:36:23 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/06 14:20:48 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long long int ps_atoi(char *c)
{
    int             flag;
    long long int   num;

    flag = 1;
    num = 0; 
    if (ps_is_sign(*c))
    {
        if (*c == '-')
            flag = -1;
        c++;
    }
    while (*c)
    {
        num = num * 10 + (*c - '0');
        if (num > (INT_MAX))
             return (num);
        c++;
    }
    return (num * flag);
}

