/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:46:33 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/16 15:48:25 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap_bonus(t_list **a, t_list **b) // working
{
	t_list	*tmp;

	if (struct_size(*a) < 2)
		free_structs_bonus(*a, *b);
	print_two_list(*a, *b);
	tmp = *a;
	*a = (*a)->next;
	tmp -> next = (*a)->next;
	(*a)->next = tmp;
		print_two_list(*a, *b);
}
void	rotate_bonus(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (struct_size(*a) < 2)
		free_structs_bonus(*a, *b);
	print_two_list(*a, *b);
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *a;
	*a = (*a)->next;
	tmp->next->next = NULL;
	print_two_list(*a, *b);
}

void	reverse_rotate_bonus(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (struct_size(*a) < 2) // the size must be smaller then 3 or 2 ?
		free_structs_bonus(*a, *b);
	tmp = *a;
	while (tmp->next->next) //segfault
		tmp = tmp->next;
	tmp->next->next = *a; //segfault
	*a = tmp->next;
	tmp->next = NULL;
}

void	push_bonus(t_list **a, t_list **b) // function is working
{
	printf("\nbefore push_bonus\n");
	print_two_list(*a, *b);
	t_list	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	(*b) = tmp;
	print_two_list(*a, *b);
		printf("after push_bonus\n\n");
}
