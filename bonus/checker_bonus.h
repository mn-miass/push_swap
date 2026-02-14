#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

typedef struct s_list {
    int             value;
    struct s_list   *next;
}   t_list;

bool            is_sign_bonus(char c);
bool            is_space_bonus(char c);
bool            is_digit_bonus(char c);
bool            is_invalid_bonus(char c);
char            *ps_strjoin_bonus(char *str1, char *str2);
char            **ps_split_bonus(char *c);
int             ps_strlen_bonus(char *c);
void            error_bonus();
char            *ps_get_next_line_bonus(int fd);
long long int   ps_atoi_bonus(char *c);
void            free_2d_bonus(char **str);
void            free_struct_bonus(t_list  *a);
