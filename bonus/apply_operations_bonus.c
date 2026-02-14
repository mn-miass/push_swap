/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_operations_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:37:57 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/14 21:45:41 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	apply_operations_bonus(t_list *a, t_list *b, char *str)
{
	if (str[0] == 'p')
		push_op_bonus(str, &a, &b);
	else if (str[0] == 's')
		swap_op_bonus(str, &a, &b);
	else if (str[0] == 'r' && str[1] == 'rr')
		reverse_rotate_op_bonus(str, &a, &b);
	else if (str[0] == 'r')
		rotate_op_bonus(str, &a, &b);
	else
	{
		free_struct_bonus(a);
		free_struct_bonus(b);
		error_bonus();
	}
}

void	push_op_bonus(char *str, t_list **a, t_list **b)
{
	if (cmp(str, "pa"))
		push_bonus(a, b);
	else if (cmp(str, "pb"))
		push_bonus(b, a);
	else
	{
		free_struct_bonus(a);
		free_struct_bonus(b);
		error_bonus();
	}
}

void	swap_op_bonus(char *str, t_list **a, t_list **b)
{
	if (cmp(str, "sa"))
		swap_bonus(a);
	else if (cmp(str, "sb"))
		swap_bonus(b);
	else if (cmp(str, "ss"))
	{
		swap_bonus(a);
		swap_bonus(b);
	}
	else
	{
		free_struct_bonus(a);
		free_struct_bonus(b);
		error_bonus();
	}
}

void	rotate_op_bonus(char *str, t_list **a, t_list **b)
{
	if (cmp(str, "ra"))
		rotate_bonus(a);
	else if (cmp(str, "rb"))
		rotate_bonus(b);
	else if (cmp(str, "rr"))
	{
		rotate_bonus(a);
		rotate_bonus(b);
	}
	else
	{
		free_struct_bonus(a);
		free_struct_bonus(b);
		error_bonus();
	}
}

void	reverse_rotate_op_bonus(char *str, t_list **a, t_list **b)
{
	if (cmp(str, "rra"))
		reverse_rotate_bonus(a);
	else if (cmp(str, "rrb"))
		reverse_rotate_bonus(b);
	else if (cmp(str, "rrr"))
	{
		reverse_rotate_bonus(a);
		reverse_rotate_bonus(b);
	}
	else
	{
		free_struct_bonus(a);
		free_struct_bonus(b);
		error_bonus();
	}
}
