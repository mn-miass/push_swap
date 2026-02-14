/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-miass <mn-miass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:45:07 by mn-miass          #+#    #+#             */
/*   Updated: 2026/02/12 10:20:34 by mn-miass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <fcntl.h>

char    *ps_realloc(char *str, char c)
{
    char    *new;
    int     i;

    i = 0;
    new = malloc(ps_strlen(str) + 2);
    if (new == NULL)
        return (NULL); // need to free
    while (str[i])
    {
        new[i] = str[i];
        i++;
    }
    free(str);
    new[i++] = c;
    new[i] = '\0';
    return(new);
}

char    *ps_get_next_line(int fd)
{
    char    *word;
    char    c;
    int     i;

    word = malloc(1);
    word[0] = '\0';
    while (i = (read(fd, &c, 1)))
    {
        if (c != '\n')
           word = ps_realloc(word, c);
        if (c == '\n')
            return (word);
    }
    if (i == 0)
        return NULL;
}

int main()
{
    int i = open("parsing_helper_bonus.c", O_RDONLY); 
    while (getchar())
        printf("%s", ps_get_next_line(i));
}