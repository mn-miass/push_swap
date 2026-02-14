/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:48:08 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/14 20:53:47 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool    ps_is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

bool    ps_is_spaces(char c)
{
    return ((c >= 9 && c <= 13) || c == 32);
}

bool    ps_is_sign(char c)
{
    return (c == '-' || c == '+');
}

bool    ps_is_novalid(char c)
{
    return (!ps_is_sign(c) && !ps_is_digit(c) && !ps_is_spaces(c));
}
bool    is_empty(char *str)
{
    while (*str)
    {
        if (!ps_is_spaces(*str))
            return 0;
        str++;
    }
    return 1;
}
