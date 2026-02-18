/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:15:08 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/18 19:42:09 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdio.h>

//checker with no input ? no op ? what should do

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = parsing_bonus(argc, argv);
	b = NULL;
	checker_bonus(&a, &b);
	free_structs_bonus(a, b);
	return (0);
}
