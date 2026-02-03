/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:05:17 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/02 16:22:42 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// the check for null well be done outside the function
// the function is working need to hundle memory leaks

static int  num_digits(char *str)
{
    int     num;
    bool    is_digit;

    num = 0;
    is_digit = 0;
    while (*str)
    {
        if ((is_digit && ps_is_sign(*str)) || (ps_is_sign(*str) && !ps_is_digit(str[1])))
            return -1;
        if ((ps_is_sign(*str) || ps_is_digit(*str)) && is_digit == 0)
        {
            num++;
            is_digit = 1;
        }
        if (ps_is_spaces(*str) && is_digit)
            is_digit = 0;
        if (ps_is_novalid(*str))
            return -1;
        str++;
    }
    return (num);
}

static int digit_size(char *str)
{
    int i;

    i = 0;
    while (str[i] && (ps_is_digit(str[i]) || ps_is_sign(str[i])))
        i++;
    return i;
}

char    **ps_split(char *str)
{
    char    **splited;
    int     size;
    int     i;

    size = num_digits(str);
    if (size == -1)
        return (NULL);                   // error free the join
    splited = malloc((size + 1) * sizeof(char *));
    if (splited == NULL)
        return (NULL);                // error free the join
    size = 0;
    while (*str)
    {
        i = 0;
        while (ps_is_spaces(*str))
            str++;
        if (*str == '\0')
            break;
        splited[size] = malloc(digit_size(str) + 1);
        if (splited[size] == NULL)
            return (free_2d(splited), NULL);          //error message fre join + splited
        while (*str && !ps_is_spaces(*str))
        {
            splited[size][i++] = *str;
            str++;
        }
        splited[size][i] = '\0';
        size++;   
    }
    splited[size] = NULL;
    return (splited);
}
