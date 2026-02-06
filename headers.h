#ifndef HEADERS
# define HEADERS

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_list{
    int             value;
    int             index;
    struct s_list   *next;
    bool	    is_bigger;
}t_list;

#endif
