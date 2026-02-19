/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_creation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:24:27 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/19 11:24:39 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	add_back_bonus(t_list **a, t_list *new)
{
	t_list	*tmp;

	tmp = *a;
	if ((*a) == NULL)
	{
		(*a) = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_list	*creat_node_bonus(int val)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->value = val;
	new->next = NULL;
	return (new);
}

bool	is_duplicated_bonus(t_list *a)
{
	t_list	*tmp;

	tmp = a->next;
	while (a)
	{
		while (tmp)
		{
			if (tmp->value == a->value)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
		tmp = a->next;
	}
	return (0);
}

t_list	*creat_stract_bonus(char **splited)
{
	t_list		*a;
	int			i;
	long long	value;

	i = 0;
	a = NULL;
	while (splited[i])
	{
		value = ps_atoi_bonus(splited[i]);
		if (value > INT_MAX || value < INT_MIN)
		{
			free_struct_bonus(a);
			error_bonus();
		}
		add_back_bonus(&a, creat_node_bonus(value));
		i++;
	}
	return (a);
}

bool	is_sorted_bonus(t_list *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}
