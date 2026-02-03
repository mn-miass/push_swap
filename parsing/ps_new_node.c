/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_creat_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:10:16 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/03 10:50:25 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list  *ps_new_node(int value)
{
    t_list  *new;

    new = malloc(sizeof (t_list));
    if (new == NULL)
        return (NULL);
    new -> value = value;
    new -> next = NULL;
    return (new);
}
