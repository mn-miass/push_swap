NAME   = push_swap
CC     = cc
CFLAGS = -Wall -Wextra -Werror
SRC    = ./error_free/error.c ./error_free/free.c \
		 ./linked_list/ps_add_back.c ./linked_list/ps_creat_stack.c ./linked_list/ps_is_duplicate.c ./linked_list/ps_index_list.c \
		 ./linked_list/ps_list_count.c ./linked_list/ps_new_node.c \
		 ./operations/pa.c ./operations/pb.c ./operations/ra.c ./operations/rb.c ./operations/rr.c ./operations/rra.c ./operations/rrb.c \
		 ./operations/rrr.c ./operations/sa.c ./operations/sb.c ./operations/ss.c \
		 ./parsing/is_functions.c ./parsing/ps_atoi.c ./parsing/ps_parsing.c ./parsing/ps_split.c ./parsing/ps_strdup.c ./parsing/ps_strjoin.c \
		 ./parsing/ps_strlen.c 
OBJ	   = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c headers.h push_swap.h ./operations/operations.h ./linked_list/linked_list.h ./parsing/parsing.h ./error_free/error_free.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all