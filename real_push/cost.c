/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:17:33 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/18 14:55:37 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_direction(t_list *a, int size_a, int size_b)
{
	if (a->position < size_b / 2)
		a->direction = UP;
	else
		a->direction = DOWN;
	if (a->target->position < size_a / 2)
		a->target->direction = UP;
	else
		a->target->direction = DOWN;
}

t_list	*biggest_smallest(t_list *a, int i)
{
	t_list	*target;

	target = NULL;
	while (a)
	{
		if (a->index > i)
			if (!target || target->index > a->index)
				target = a;
		a = a->next;
	}
	return (target);
}

void	set_target(t_list *a, t_list *b)
{
	is_bigger(b);
	while (b)
	{
		b->target = biggest_smallest(a, b->index);
		b = b->next;
	}
}

int	max(int cost_a, int cost_b)
{
	if (cost_a > cost_b)
		return (cost_a);
	return (cost_b);
}

void	calculate_cost(t_list *a, t_list *b)
{
	int	size_a;
	int	size_b;
	int	cost_a;
	int	cost_b;

	size_a = ps_list_count(a);
	size_b = ps_list_count(b);
	while (b)
	{
		set_direction(b, size_a, size_b);
		if (b->direction == UP)
			cost_b = b->position;
		else
			cost_b = size_b - b->position;
		if (b->target->direction == UP)
			cost_a = b->target->position;
		else
			cost_a = size_a - b->target->position;
		if (b->direction == b->target->direction)
			b->cost = max(cost_a, cost_b);
		else
			b->cost = cost_a + cost_b;
		b = b->next;
	}
}
