/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:15:08 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/16 17:20:34 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = parsing_bonus(argc, argv); // the parsing bugs are fixed as i know need to check them later 
	b = NULL;
	checker_bonus(&a, &b); 
	// infinit loop i guess segfaults need to check it later
	return (0);
}
