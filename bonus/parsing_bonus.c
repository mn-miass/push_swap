#include "checker_bonus.h"

t_list  *parsing(int argc, char **argv)
{
    char    *join;
    char    **splited;
    t_list  *a;
    int     i;

    i = 1;
    join = NULL;
    a = NULL;
    if (argc == 1)
        exit(0);
    while (argv[i])
    {
        join = ps_strjoin_bonus(join, argv[i]);
        if (join == NULL)
            error_bonus();
        i++;
    }
    splited = ps_split_bonus(join);
    free(join);
    if (splited == NULL)
        return (free_2d_bonus(splited), NULL);
    a = creat_stract_bonus(a, splited);
    free_2d_bonus(splited);
    return (a);
}
