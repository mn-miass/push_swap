/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:01:40 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/15 14:03:26 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

bool	is_digit_bonus(char c)
{
	return (c >= '0' && c <= '9');
}

bool	is_space_bonus(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

bool	is_sign_bonus(char c)
{
	return (c == '+' || c == '-');
}

bool	is_invalid_bonus(char c)
{
	return (!is_digit_bonus(c) && !is_sign_bonus(c) && !is_space_bonus(c));
}

bool	cmp_bonus(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (0);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (1);
	return (0);
}
