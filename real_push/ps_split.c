/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:05:17 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/18 19:37:04 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	num_digits(char *str)
{
	int		num;
	bool	is_digit;

	num = 0;
	is_digit = 0;
	while (*str)
	{
		if ((is_digit && ps_is_sign(*str)) || (ps_is_sign(*str)
				&& !ps_is_digit(str[1])))
			return (-1);
		if ((ps_is_sign(*str) || ps_is_digit(*str)) && is_digit == 0)
		{
			num++;
			is_digit = 1;
		}
		if (ps_is_spaces(*str) && is_digit)
			is_digit = 0;
		if (ps_is_novalid(*str))
			return (-1);
		str++;
	}
	return (num);
}

static int	digit_size(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (ps_is_digit(str[i]) || ps_is_sign(str[i])))
		i++;
	return (i);
}

char	**creat_2d(char *str)
{
	int		size;
	char	**splitted;

	size = num_digits(str);
	if (size == -1)
		return (NULL);
	splitted = malloc((size + 1) * sizeof(char *));
	return (splitted);
}

char	**ps_split(char *str)
{
	char	**splited;
	int		i;
	int		j;
	int		dc;

	i = 0;
	splited = creat_2d(str);
	if (splited == NULL)
		return (NULL);
	dc = num_digits(str);
	while (dc > i)
	{
		j = 0;
		while (*str && ps_is_spaces(*str))
			str++;
		if (*str == '\0')
			break ;
		splited[i] = malloc(digit_size(str) + 1);
		if (splited[i] == NULL)
			return (free_2d(splited), NULL);
		while (*str && (ps_is_digit(*str) || ps_is_sign(*str)))
			splited[i][j++] = *str++;
		splited[i++][j] = '\0';
	}
	return (splited[i] = NULL, splited);
}
