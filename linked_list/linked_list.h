#ifndef LINKED_LIST
# define LINKED_LIST

# include "../headers.h"

typedef struct s_list{
    int value;
    int index;
    struct s_list *next;
}t_list;

void    ps_add_back(t_list **a, t_list *new);
t_list  *ps_new_node(int value);
t_list  *ps_creat_stack(char **str);
size_t  ps_list_count(t_list *lst);
void    ps_add_back(t_list **a, t_list *new);
bool    ps_is_duplicate(t_list *a);

#endif
