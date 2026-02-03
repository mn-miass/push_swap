/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:50:27 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/03 12:21:37 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING
# define PARSING

# include "../headers.h"

size_t          ps_strlen(char *s);
char            *ps_strjoin(char *s1, char *s2);
char            *ps_strdup(char *str);
bool            ps_is_digit(char c);
bool            ps_is_spaces(char c);
bool            ps_is_sign(char c);
bool            ps_is_novalid(char c);
char            **ps_split(char *str);
long long int   ps_atoi(char *c);
t_list          *ps_parsing(int argc, char **argv);
bool            is_empty(char *str);

#endif