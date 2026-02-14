/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:59:48 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/12 15:10:30 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    error()
{
    write (2, "Error\n", 7);
    exit(1);
}

void    free_1d(char *str)
{
    free(str);
}

void    free_2d(char **str)
{
    int i;

    i = 0;
    while(str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}
void    free_stack(t_list   **a) //does it free evrything ?
{
    t_list  *tmp;

    while (*a)
    {
        tmp = *a;
        *a = (*a) -> next;
        free (tmp);
    }
}
