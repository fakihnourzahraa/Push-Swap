NAME    = push_swap

SRC = ft_atoi.c ft_split.c helper_functions.c push.c \
		reverse_rotate.c rotate.c sorting.c stack_conversion.c \
		stack_creation.c swap.c main.c algo.c stack_helper.c \
		ft_strcmp.c

OBJ     = $(SRC:.c=.o)

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "🏂 done making"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "💄 done cleaning"

fclean: clean
	@rm -f $(NAME)
	@echo "👺 done fcleaning"

re: fclean all

.PHONY: all clean fclean re
