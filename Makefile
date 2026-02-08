NAME   = push_swap
CC     = cc
CFLAGS = -Wall -Wextra -Werror
SRC    = free_error.c is_functions.c moves.c parsing_utils.c ps_parsing.c ps_split.c push.c reverse_rotate.c \
		 rotate.c sort_small.c sort_utils.c sorting.c stack_init.c stack_utils.c swap.c cost.c main.c
OBJ	   = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h 
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all