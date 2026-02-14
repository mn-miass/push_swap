/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:17:15 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/14 22:09:50 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ps_atoi(char *c)
{
	int				flag;
	long long int	num;

	flag = 1;
	num = 0;
	if (ps_is_sign(*c))
	{
		if (*c == '-')
			flag = -1;
		c++;
	}
	while (*c)
	{
		num = num * 10 + (*c - '0');
		if (num > (INT_MAX + (long long)1))
			// long here to convert 1 to long and operate the operation with long long not int
			return (num);
		c++;
	}
	return (num * flag);
}

char	*ps_strdup(char *str)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = malloc(ps_strlen(str) + 1);
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

char	*ps_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	i;

	i = 0;
	if (s2[0] == '\0' || is_empty(s2))
		return (free(s1), NULL);
	if (s1 == NULL)
		return (ps_strdup(s2));
	join = malloc(ps_strlen(s1) + ps_strlen(s2) + 2);
	if (join == NULL)
		return (free(s1), NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	join[i++] = ' ';
	while (*s2)
	{
		join[i++] = *s2;
		s2++;
	}
	join[i] = '\0';
	free(s1);
	return (join);
}

size_t	ps_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
