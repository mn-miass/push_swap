#ifndef LINKED_LIST
# define LINKED_LIST

# include "../headers.h"

t_list  *ps_new_node(int value);
t_list  *ps_creat_stack(char **str);
size_t  ps_list_count(t_list *lst);
bool    ps_is_duplicate(t_list *a);
void    ps_index_list(t_list *a);
void    ps_add_back(t_list **a, t_list *new);
int     set_position(t_list *a, int index);

#endif
