/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:07:39 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/02 18:14:26 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t  ps_list_count(t_list *lst)
{
    size_t  i;

    i = 0;
    if (lst == NULL)
        return 0;
    while (lst)
    {
        lst = lst -> next;
        i++;
    }
    return(i);
}
