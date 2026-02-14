/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:16:41 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/14 22:10:46 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ps_list_count(t_list *lst)
{
	size_t	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

bool	ps_is_duplicate(t_list *a)
{
	int		value;
	t_list	*tmp;

	while (a)
	{
		value = a->value;
		tmp = a->next;
		while (tmp)
		{
			if (tmp->value == value)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

void	ps_index_list(t_list *a)
{
	int		i;
	int		min;
	t_list	*tmp;
	t_list	*min_node;

	min = INT_MAX;
	min_node = NULL;
	i = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->value < min && tmp->index == -1)
		{
			min = tmp->value;
			min_node = tmp;
		}
		tmp = tmp->next;
		if (tmp == NULL)
		{
			if (min_node == NULL)
				break ;
			min_node->index = i++;
			min = INT_MAX;
			min_node = NULL;
			tmp = a;
		}
	}
}
