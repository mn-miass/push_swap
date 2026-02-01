#include "push_swap.h"

void    ps_parsing(t_stack_node **a, char **argv)
{
    int i = 1;
    char *join;
    char **splited;
    char *tmp;

    while (argv[i])
    {
        tmp = join;
        join = ps_strjoin(join, argv[i]);
        free(tmp);
        if (join == NULL) // i dont free the old join i must do this 
            error();
        i++;
    }
    splited = ps_split(join); //segfault for non digit input or non valid input it must return NULL instead and must free join
    //segfault caused of trying to access null THE FUNCTION WORKS INE NOW BUT I NEED A FREE AND ERROR FUNCTIONS
    free(join);
    if (splited == NULL)
        error(); //must work on error function
    for (int i = 0; splited[i]; i++) 
    {
        long long int j = ps_atoi(splited[i]);
        if (j > INT_MAX || j < INT_MIN)
        {
            free_2d(splited);
            error();
        }  // need to heck if number belong to the range and free splited 
        if (node_exist(*a, j))
        {
            free_2d(splited);
            error();
        }
        ps_add_back(a, ps_creat_node(j));
    }
    ps_index_nodes(*a, (ps_count_nodes(*a)));
}

int main(int argc, char **argv)
{
    t_stack_node *head_a = NULL;
    t_stack_node *head_b = NULL;

    if (argc == 1)
        error();
    ps_parsing(&head_a, argv);
    for (; head_a; head_a = head_a -> next)
        printf("%d  %d\n", head_a -> value, head_a -> index);
    _CrtDump
}