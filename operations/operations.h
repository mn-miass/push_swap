/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:54:40 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/06 11:33:45 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS
# define OPERATIONS

# include "../headers.h"

void    pa(t_list **a, t_list **b);
void    pb(t_list **a, t_list **b);
void    rra(t_list **a);
void    rrb(t_list **b);
void    rrr(t_list **a, t_list **b);
void    sa(t_list   **a);
void    sb(t_list **b);
void    ss(t_list **a, t_list **b);
void    ra(t_list **a);
void    rb(t_list **b);
void    rr(t_list **a, t_list **b);

#endif