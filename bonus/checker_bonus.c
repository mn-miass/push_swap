/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:47:02 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/14 22:08:26 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	checker_bonus(t_list **a, t_list **b)
{
	char	*str;

	str = ps_get_next_line_bonus(0);
	while (str)
	{
		apply_operations_bonus(str, a, b);
		str = ps_get_next_line_bonus(0);
	}
	if (is_sorted_bonus(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
