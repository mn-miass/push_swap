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
        join = ps_strjoin(join, argv[i]);
        i++;
    }
    splited = ps_split(join);
    a = creat_stract(a, splited);
    return (a);
}
