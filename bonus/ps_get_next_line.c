/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:45:07 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/19 11:12:10 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	*ps_realloc_bonus(char *str, char c)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(ps_strlen_bonus(str) + 2);
	if (new == NULL)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	free(str);
	new[i++] = c;
	new[i] = '\0';
	return (new);
}

char	*ps_get_next_line_bonus(void)
{
	char	*word;
	char	c;
	int		i;

	word = malloc(1);
	word[0] = '\0';
	while (1)
	{
		i = read(0, &c, 1);
		if (i == 0)
			return (NULL);
		if (c != '\n')
			word = ps_realloc_bonus(word, c);
		if (c == '\n')
			return (word);
	}
}
