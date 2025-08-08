NAME    = push_swap.exe

SRC = ft_atoi.c ft_split.c helper_functions.c push.c \
		reverse_rotate.c rotate.c sorting.c stack_conversion.c \
		stack_creation.c swap.c main.c

OBJ     = $(SRC:.c=.o)

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q $(OBJ) 2>nul || true

fclean: clean
	del /Q $(NAME) 2>nul || true

re: fclean all

.PHONY: all clean fclean re

# Windows equivalent of the commented gcc command:
# gcc ft_atoi.c ft_split.c helper_functions.c node_data.c push.c reverse_rotate.c rotate.c sorting.c stack_conversion.c stack_creation.c swap.c turk_two.c turk.c main.c -o push_swap.exe