/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:55:06 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/19 11:22:25 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_list;

int					struct_size(t_list *a);
bool				is_sign_bonus(char c);
bool				is_space_bonus(char c);
bool				is_digit_bonus(char c);
bool				is_invalid_bonus(char c);
char				*ps_strjoin_bonus(char *str1, char *str2);
char				**ps_split_bonus(char *c);
int					ps_strlen_bonus(char *c);
void				error_bonus(void);
char				*ps_get_next_line_bonus(void);
long long int		ps_atoi_bonus(char *c);
void				free_2d_bonus(char **str);
void				free_struct_bonus(t_list *a);
void				apply_operations_bonus(t_list **a, t_list **b, char *str);
void				checker_bonus(t_list **a, t_list **b);
void				error_bonus(void);
void				free_2d_bonus(char **str);
void				free_struct_bonus(t_list *a);
bool				cmp_bonus(char *str1, char *str2);
void				swap_bonus(t_list **a);
void				rotate_bonus(t_list **a);
void				reverse_rotate_bonus(t_list **a);
void				push_bonus(t_list **a, t_list **b);
t_list				*parsing_bonus(int argc, char **argv);
long long int		ps_atoi_bonus(char *c);
bool				is_sorted_bonus(t_list *a);
t_list				*creat_stract_bonus(char **splited);
bool				is_duplicated_bonus(t_list *a);
t_list				*creat_node_bonus(int val);
void				add_back_bonus(t_list **a, t_list *new);
void				free_structs_bonus(t_list *a, t_list *b);

#endif