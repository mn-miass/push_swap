/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:24:44 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/18 19:39:56 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	*allocate_digit_bonus(char *c)
{
	int		i;
	char	*digits;

	i = 0;
	while (is_sign_bonus(c[i]) || is_digit_bonus(c[i]))
		i++;
	digits = malloc(i + 1);
	if (digits == NULL)
		return (NULL);
	i = 0;
	while (is_sign_bonus(c[i]) || is_digit_bonus(c[i]))
	{
		digits[i] = c[i];
		i++;
	}
	return (digits);
}

int	num_digits_bonus(char *c)
{
	int		num;
	bool	is_digit;

	is_digit = 0;
	num = 0;
	while (*c)
	{
		if (is_sign_bonus(*c) && !is_digit_bonus(c[1]))
			return (-1);
		else if ((is_digit_bonus(*c) || is_sign_bonus(*c)) && is_digit == 0)
		{
			num++;
			is_digit = 1;
		}
		else if ((is_digit && is_sign_bonus(*c)))
			return (-1);
		else if (is_space_bonus(*c))
			is_digit = 0;
		else if (is_invalid_bonus(*c))
			return (-1);
		c++;
	}
	return (num);
}

char	**creat_2d_bonus(char *c)
{
	char	**splited;

	if (num_digits_bonus(c) == -1)
		return (NULL);
	splited = malloc((num_digits_bonus(c) + 1) * sizeof(char *));
	return (splited);
}

char	**ps_split_bonus(char *c)
{
	int		i;
	char	**splited;

	i = 0;
	splited = creat_2d_bonus(c);
	if (splited == NULL)
		return (NULL);
	while (*c)
	{
		while (is_space_bonus(*c))
			c++;
		if (*c != '\0')
			splited[i] = allocate_digit_bonus(c);
		else
			return (splited[i] = NULL, (splited));
		if (splited[i] == NULL)
			return (free_2d_bonus(splited), NULL);
		while (is_digit_bonus(*c) || is_sign_bonus(*c))
			c++;
		i++;
	}
	return (splited);
}
