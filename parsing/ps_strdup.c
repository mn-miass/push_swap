/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:32:05 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/02 15:56:41 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//no need to check for null it will bechecked befor calling it
char    *ps_strdup(char *str)
{
    char    *dup;
    size_t  i;

    i = 0;
    dup = malloc(ps_strlen(str) + 1);
    if (dup == NULL)
        return (NULL);
    while (str[i])
    {
        dup[i] = str[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}
