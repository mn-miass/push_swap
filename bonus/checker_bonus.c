/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:47:02 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/16 15:51:20 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdio.h>

void	ps(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
// infinite loop in testing
// segfaultt when we talk about non didgit even sign ?
// error in non digit
// parsing still have problems
// error with list not sorted really the list in a is sorted but does not contain them all 
// delete ps
// free the get next line
// free the structs
void	checker_bonus(t_list **a, t_list **b)
{
	char	*str;
	int		count;

	count = 0;
	str = ps_get_next_line_bonus();
	while (str)
	{
		apply_operations_bonus(*a, *b, str);
		printf("%d\n", count);
			// print_two_list(*a, *b);
		str = ps_get_next_line_bonus();
	}
	print_two_list(*a, *b); // all values are lost ???
	if (is_sorted_bonus(*a) && struct_size(*b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int		struct_size(t_list *a)
{
	int i;

	i = 0;
	if (!a)
		return(i);
	while (a)
	{
		i++;
		a = a -> next;
	}
	return (i);
}
