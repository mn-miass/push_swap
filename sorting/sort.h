/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:52:17 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/06 15:54:22 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT
# define SORT

# include "../headers.h"

void    sort_3(t_list **a);
void    is_bigger(t_list *a);
void    sort_2(t_list **a);
void    is_sorted(t_list *a);
void    push_to_b(t_list **a, t_list **b);

#endif