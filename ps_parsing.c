/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:44:06 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/07 17:16:25 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list    *ps_parsing(int argc, char **argv)
{
    int     i;
    char    *join;
    char    **splitted;
    t_list  *a;

    i = 1;
    join = NULL;
    if (argc == 1)
        error();
    while (argv[i])
    {
        join = ps_strjoin(join, argv[i]);
        if (join == NULL)
            error();
        i++;
    }
    splitted = ps_split(join);
    free_1d(join);
    if (splitted == NULL)
        error();
    i = 0;
    a = ps_creat_stack(splitted);
    free_2d(splitted);
    if (ps_is_duplicate(a))
        error();
    is_sorted(&a);
    ps_index_list(a);
    return (a);
}
