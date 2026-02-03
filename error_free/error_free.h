/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:53:42 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/03 10:40:49 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_FREE
# define ERROR_FREE

# include "../headers.h"

void    error();
void    free_2d(char **str);
void    free_1d(char *str);

#endif