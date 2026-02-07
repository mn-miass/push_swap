/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:44:06 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/07 09:23:54 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

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

int main(int argc, char **argv)
{
    t_list *a = ps_parsing(argc, argv);

    t_list *b = NULL;
    sorting(&a, &b);
    // printf("%p\n", a);
    // while (a)
    // {
    //     printf("value = %d   index = %d   is_bigger = %d\n", a->value, a->index, a->is_bigger);
    //     a = a -> next;
    // }
    // printf("bbbbb\n");
    // while (b)
    // {
    //     printf("value = %d   index = %d   is_bigger = %d\n", b->value, b->index, b->is_bigger);
    //     b = b -> next;
    // }
}