#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_list{
    int             value;
    int             index;
    int             cost;
    int             position;
    int             direction;
    bool            is_bigger;
    bool            is_smaller;
    struct s_list   *next;
    struct s_list   *target;
}t_list;


#endif
