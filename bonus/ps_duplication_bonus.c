/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_duplication_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:21:59 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/19 11:20:08 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

bool	is_dupliated_bonus(t_list *a)
{
	int		val;
	t_list	*tmp;

	if (!a)
		return (0);
	while (a)
	{
		val = a->value;
		tmp = a->next;
		while (tmp)
		{
			if (tmp->value == val)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}
