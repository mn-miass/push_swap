//now im creating the linked list function that should help me with adding input to linked list 
//so i can work on error function later
//add all functions prototypes

#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

# ifndef LINKED_LIST
typedef struct s_stack_node
{
    int value;
    int index;
    bool is_max;
    bool is_min;
    struct s_stack_node *next;
} t_stack_node;
# endif

void            free_2d(char **str);
void            error();
int             ps_strlen(char *s);
char            *ps_strjoin(char *s1, char *s2);
char            **ps_split(char *s);
bool            node_exist(t_stack_node *head, int value);
void            ps_index_nodes(t_stack_node *head, int len);
long long int   ps_atoi(char *c);
bool            is_space(char c);
bool            is_digit(char c);
bool            is_nonvalid(char c);
bool            is_sign(char c);
t_stack_node    *ps_creat_node(int value);
int             ps_count_nodes(t_stack_node* head);
void            ps_add_front(t_stack_node **head, t_stack_node *new);
void            ps_add_back(t_stack_node **head, t_stack_node *new);
void            ps_add_back(t_stack_node **head, t_stack_node *new);
void            free_2d(char **str);
void            sb(t_stack_node **b);
void            sa(t_stack_node **b);
void            pa(t_stack_node **a);
void            pb(t_stack_node **a);
void            rb(t_stack_node **b);
void            ra(t_stack_node **a);
void            rra(t_stack_node **a);
void            rrb(t_stack_node **b);
