# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/26 16:25:20 by nfakih            #+#    #+#              #
#    Updated: 2025/07/05 16:22:13 by nfakih           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CC = cc
SRCS = ft_atoi.c ft_split.c helper_functions.c node_data.c push.c \
		reverse_rotate.c rotate.c sorting.c stack_conversion.c \
		stack_creation.c swap.c turk_two.c turk.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap

all: $(NAME)
$(NAME): $(OBJS)
$(CC): $(CFLAGS) -o $@ $^
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean: 
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re