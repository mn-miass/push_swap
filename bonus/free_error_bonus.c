/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:59:41 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/14 22:01:32 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	error_bonus(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_2d_bonus(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_struct_bonus(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	while (a)
	{
		a = a ->next;
		free (tmp);
		tmp = a;
	}
}
