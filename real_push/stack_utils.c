/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:16:41 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/18 18:45:04 by mn-miass         ###   ########.fr       */
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

t_list	*small_index(t_list *a)
{
	int		min;
	t_list	*node;

	min = INT_MAX;
	node = NULL;
	while (a)
	{
		if (a -> index == -1 && a -> value < min)
		{
			min = a -> value;
			node = a;
		}
		a = a -> next;
	}
	return (node);
}

void	ps_index_list(t_list *a)
{
	int		i;
	t_list	*tmp;
	t_list	*min_node;

	min_node = NULL;
	i = 0;
	tmp = a;
	while (tmp)
	{
		min_node = small_index(a);
		tmp = tmp->next;
		if (tmp == NULL)
		{
			if (min_node == NULL)
				break ;
			min_node->index = i++;
			min_node = NULL;
			tmp = a;
		}
	}
}
