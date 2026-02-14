/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:16:44 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/14 22:10:50 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_function(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
}

void	ss(t_list **a, t_list **b)
{
	swap_function(a);
	swap_function(b);
	write(1, "ss\n", 3);
}

void	sb(t_list **b)
{
	swap_function(b);
	write(1, "sb\n", 3);
}

void	sa(t_list **a)
{
	swap_function(a);
	write(1, "sa\n", 3);
}
