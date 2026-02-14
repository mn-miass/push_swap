/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:16:53 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/14 22:10:33 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_bigger(t_list *a)
{
	int		max_value;
	t_list	*biggest_node;

	max_value = INT_MIN;
	biggest_node = NULL;
	while (a)
	{
		if (a->value > max_value)
		{
			max_value = a->value;
			biggest_node = a;
		}
		a = a->next;
	}
	biggest_node->is_bigger = true;
}

t_list	*is_smaller(t_list *a)
{
	long long int	min;
	t_list			*min_node;

	min_node = NULL;
	min = INT_MAX; //?
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			min_node = a;
		}
		a = a->next;
	}
	min_node->is_smaller = 1;
	return (min_node);
}

t_list	*find_cheapest(t_list *a)
{
	t_list	*tmp;

	tmp = NULL;
	while (a)
	{
		if (!tmp || tmp->cost > a->cost)
			tmp = a;
		a = a->next;
	}
	return (tmp);
}

void	set_position(t_list *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a->position = i;
		i++;
		a = a->next;
	}
}
