/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:41:00 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/18 15:17:04 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
// split modification + check the prototype what are the 
//function are really used
# define UP 1
# define DOWN -1

typedef struct s_list
{
	int				value;
	int				index;
	int				cost;
	int				position;
	int				direction;
	bool			is_bigger;
	bool			is_smaller;
	struct s_list	*next;
	struct s_list	*target;
}					t_list;

t_list				*biggest_smallest(t_list *a, int i);
void				set_target(t_list *a, t_list *b);
void				calculate_cost(t_list *a, t_list *b);
void				error(void);
void				free_1d(char *str);
void				free_2d(char **str);
void				free_stack(t_list **a);
bool				ps_is_digit(char c);
bool				ps_is_spaces(char c);
bool				ps_is_sign(char c);
bool				ps_is_novalid(char c);
bool				is_empty(char *str);
void				push_to_b(t_list **a, t_list **b);
void				execute_rotation(t_list **a, t_list **b);
void				final_rotation(t_list **a);
long long int		ps_atoi(char *c);
char				*ps_strdup(char *str);
char				*ps_strjoin(char *s1, char *s2);
size_t				ps_strlen(char *s);
t_list				*ps_parsing(int argc, char **argv);
char				**ps_split(char *str);
void				pb(t_list **a, t_list **b);
void				pa(t_list **a, t_list **b);
void				rra(t_list **a);
void				rrb(t_list **b);
void				rrr(t_list **a, t_list **b);
void				rr(t_list **a, t_list **b);
void				ra(t_list **a);
void				rb(t_list **b);
void				ss(t_list **a, t_list **b);
void				sb(t_list **b);
void				sa(t_list **a);
void				sort_3(t_list **a);
void				sort_2(t_list **a);
void				is_sorted(t_list **a);
void				is_bigger(t_list *a);
t_list				*is_smaller(t_list *a);
t_list				*find_cheapest(t_list *a);
void				set_position(t_list *a);
void				sorting(t_list **a, t_list **b);
t_list				*ps_new_node(int value);
t_list				*ps_creat_stack(char **str);
void				ps_add_back(t_list **a, t_list *new);
size_t				ps_list_count(t_list *lst);
bool				ps_is_duplicate(t_list *a);
void				ps_index_list(t_list *a);
void				sort_complex(t_list **a, t_list **b);
void				sort_5(t_list **a, t_list **b);

#endif
