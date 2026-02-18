/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:46:33 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/18 19:38:22 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap_bonus(t_list **a)
{
	t_list	*tmp;

	if (struct_size(*a) < 2)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
}

void	rotate_bonus(t_list **a)
{
	t_list	*tmp;

	if (struct_size(*a) < 2)
		return ;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *a;
	*a = (*a)->next;
	tmp->next->next = NULL;
}

void	reverse_rotate_bonus(t_list **a)
{
	t_list	*tmp;

	if (struct_size(*a) < 2)
		return ;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *a;
	*a = tmp->next;
	tmp->next = NULL;
}

void	push_bonus(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (struct_size(*a) == 0)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	(*b) = tmp;
}
