/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:16:59 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/14 22:12:41 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *a;
	*a = (*a)->next;
	(tmp->next)->next = NULL;
}

void	ra(t_list **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
