NAME   = push_swap
CC     = cc
CFLAGS = -Wall -Wextra -Werror
SRC    = free_error.c is_functions.c moves.c parsing_utils.c ps_parsing.c ps_split.c push.c reverse_rotate.c \
		 rotate.c sort_small.c sort_utils.c sorting.c stack_init.c stack_utils.c swap.c cost.c main.c
SRCB   = ../bonus/apply_operations_bonus.c ../bonus/checker_bonus.c ../bonus/free_error_bonus.c ../bonus/helper_bonus.c \
		../bonus/main_bonus.c ../bonus/operations_bonus.c ../bonus/parsing_bonus.c ../bonus/parsing_helper_bonus.c \
		../bonus/ps_atoi.c ../bonus/ps_get_next_line.c ../bonus/ps_split_bonus.c ../bonus/struct_creation_bonus.c ../bonus/must_delete.c

OBJ	   = $(SRC:.c=.o)
OBJB   = $(SRCB:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h 
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ) $(OBJB)

fclean : clean
	rm -rf $(NAME) checker

bonus : $(OBJB)
	$(CC) $(CFLAGS) $(OBJB)  -o checker

re : fclean all