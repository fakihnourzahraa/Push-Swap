NAME    = push_swap

SRC = ft_atoi.c ft_split.c helper_functions.c node_data.c push.c \
		reverse_rotate.c rotate.c sorting.c stack_conversion.c \
		stack_creation.c swap.c turk_two.c turk.c main.c

OBJ     = $(SRC:.c=.o)

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
#remove the -g
#cc ft_atoi.c ft_split.c helper_functions.c node_data.c push.c reverse_rotate.c rotate.c sorting.c stack_conversion.c stack_creation.c swap.c turk_two.c turk.c main.c 