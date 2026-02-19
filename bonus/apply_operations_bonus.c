/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_operations_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:37:57 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/19 10:37:09 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap_op_bonus(char *str, t_list **a, t_list **b)
{
	if (cmp_bonus(str, "sa"))
		swap_bonus(a);
	else if (cmp_bonus(str, "sb"))
		swap_bonus(b);
	else if (cmp_bonus(str, "ss"))
	{
		swap_bonus(a);
		swap_bonus(b);
	}
	else
		free_structs_bonus(*a, *b);
}

void	rotate_op_bonus(char *str, t_list **a, t_list **b)
{
	if (cmp_bonus(str, "ra"))
		rotate_bonus(a);
	else if (cmp_bonus(str, "rb"))
		rotate_bonus(b);
	else if (cmp_bonus(str, "rr"))
	{
		rotate_bonus(a);
		rotate_bonus(b);
	}
	else
		free_structs_bonus(*a, *b);
}

void	reverse_rotate_op_bonus(char *str, t_list **a, t_list **b)
{
	if (cmp_bonus(str, "rra"))
		reverse_rotate_bonus(a);
	else if (cmp_bonus(str, "rrb"))
		reverse_rotate_bonus(b);
	else if (cmp_bonus(str, "rrr"))
	{
		reverse_rotate_bonus(a);
		reverse_rotate_bonus(b);
	}
	else
		free_structs_bonus(*a, *b);
}

void	push_op_bonus(char *str, t_list **a, t_list **b)
{
	if (cmp_bonus(str, "pa"))
		push_bonus(b, a);
	else if (cmp_bonus(str, "pb"))
		push_bonus(a, b);
	else
		free_structs_bonus(*a, *b);
}

void	apply_operations_bonus(t_list **a, t_list **b, char *str)
{
	if (str[0] == 'p')
		push_op_bonus(str, a, b);
	else if (str[0] == 's')
		swap_op_bonus(str, a, b);
	else if (str[0] == 'r' && str[1] == 'r' && str[2])
		reverse_rotate_op_bonus(str, a, b);
	else if (str[0] == 'r')
		rotate_op_bonus(str, a, b);
	else
		free_structs_bonus(*a, *b);
}
