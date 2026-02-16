/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 12:51:02 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/15 12:54:18 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ps_strlen_bonus(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

bool	is_empty_bonus(char *s)
{
	while (*s)
	{
		if (!is_space_bonus(*s))
			return (0);
		s++;
	}
	return (1);
}

char	*ps_strdup_bonus(char *str)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(ps_strlen_bonus(str) + 1);
	if (dup == NULL)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ps_strjoin_bonus(char *str1, char *str2)
{
	char	*join;
	int		i;

	i = 0;
	if (str2[0] == '\0' || is_empty_bonus(str2))
		return (free(str1), NULL);
	if (str1 == NULL)
		return (ps_strdup_bonus(str2));
	join = malloc(ps_strlen_bonus(str1) + ps_strlen_bonus(str2) + 1);
	if (join == NULL)
		return (NULL);
	while (str1[i])
	{
		join[i] = str1[i];
		i++;
	}
	join[i++] = ' ';
	while (*str2)
	{
		join[i++] = *str2;
		str2++;
	}
	join[i] = '\0';
	return (join);
}
