/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 12:24:21 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/19 11:23:32 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	check(t_list *a)
{
	if (is_duplicated_bonus(a))
	{
		free_struct_bonus(a);
		error_bonus();
	}
}

t_list	*parsing_bonus(int argc, char **argv)
{
	char	*join;
	char	**splited;
	t_list	*a;
	int		i;

	i = 1;
	join = NULL;
	a = NULL;
	if (argc == 1)
		exit(0);
	while (argv[i])
	{
		join = ps_strjoin_bonus(join, argv[i]);
		if (join == NULL)
			error_bonus();
		i++;
	}
	splited = ps_split_bonus(join);
	free(join);
	if (splited == NULL)
		error_bonus();
	a = creat_stract_bonus(splited);
	free_2d_bonus(splited);
	check(a);
	return (a);
}
