/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:17:23 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/15 08:41:25 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_list **a, t_list **b)
{
	int	median;
	int	size;

	size = ps_list_count(*a);
	median = size / 2;
	while (size > 3)
	{
		if ((*a)->is_bigger)
			ra(a);
		pb(a, b);
		if ((*b)->index < median)
			rb(b);
		size--;
	}
}

void	to_rotate(t_list **a, t_list *node, char stack)
{
	while ((*a) != node)
	{
		if (node -> direction == UP)
		{
			if (stack == 'a')
				ra(a);
			else
				rb(a);
		}
		if (node -> direction == DOWN)
		{
			if (stack == 'a')
				rra(a);
			else
				rrb(a);
		}
	}
}

void	execute_rotation(t_list **a, t_list **b)
{
	t_list	*to_rotate_a;
	t_list	*to_rotate_b;

	to_rotate_b = find_cheapest(*b);
	to_rotate_a = to_rotate_b->target;
	while (((*a) != to_rotate_a && (*b) != to_rotate_b)
		&& (to_rotate_a->direction == to_rotate_b->direction))
	{
		if (to_rotate_a->direction == 1)
			rr(a, b);
		else
			rrr(a, b);
	}
	to_rotate(a, to_rotate_a, 'a');
	to_rotate(b, to_rotate_b, 'b');
	pa(a, b);
}

void	final_rotation(t_list **a)
{
	t_list	*min_node;
	int		size;

	size = ps_list_count(*a);
	min_node = is_smaller(*a);
	while ((*a) != min_node)
	{
		if (min_node->position > size / 2)
			rra(a);
		else
			ra(a);
	}
}
