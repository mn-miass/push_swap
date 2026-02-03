/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 09:52:00 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/03 12:21:31 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// the strjoin must join 2 sperated string adding between them space
// i should hundle the case for empty string;

char    *ps_strjoin(char *s1, char *s2)
{
    char    *join;
    size_t  i;

    i = 0;
    if (s2[0] == '\0' || is_empty(s2))
        return (NULL);
    if (s1 == NULL)
        return (ps_strdup(s2));
    join = malloc(ps_strlen(s1) + ps_strlen(s2) + 2);
    if (join == NULL)
        return (NULL);
    while (s1[i])
    {
        join[i] = s1[i];
        i++;
    }
    join[i++] = ' ';
    while (*s2)
    {
        join[i++] = *s2;
        s2++;
    }
    join[i] = '\0';
    free (s1);
    return (join);
}
