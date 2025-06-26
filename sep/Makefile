# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/26 16:25:20 by nfakih            #+#    #+#              #
#    Updated: 2025/06/26 16:25:58 by nfakih           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CC = cc
SRCS = 
OBJS = $(SRCS:.c=.o)
NAME = push_swap.a
all: $(NAME)
$(NAME) : $(OBJS)
	ar rcs $@ $^
%.o : %.c
	cc $(CFLAGS) -c $< -o $@
clean: 
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re