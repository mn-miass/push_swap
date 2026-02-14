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
char            *ps_strjoin(char *str1, char *str2);
char            **ps_split(char *c);
int             ps_strlen(char *c);
void            error();
char            *ps_get_next_line(int fd);
long long int   ps_atoi(char *c);