/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:53:15 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/03 12:02:59 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    ps_add_back(t_list **a, t_list *new)
{
    t_list  *tmp;

    tmp = *a;
    if (*a == NULL)
    {
        *a = new;
        return ;
    }
    while (tmp -> next)
        tmp = tmp -> next;
    tmp -> next = new;
}
