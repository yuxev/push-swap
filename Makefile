# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 19:53:47 by aasselma          #+#    #+#              #
#    Updated: 2023/04/27 00:23:30 by aasselma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
B_NAME = checker

SRC = push_swap.c utils.c \
		cont_of_instru.c \
		instruction.c \
		check_err.c  \
		sort_stack.c \
		small_sort.c \

BONUS =	push_swap_bonus.c utils_bonus.c \
		cont_of_instru_bonus.c \
		instruction_bonus.c \
		check_err_bonus.c  \
		sort_stack_bonus.c \

BONUS_OBJ = $(BONUS:.c=.o)

OBJ = $(SRC:.c=.o)

utils =	./get_next_line/get_next_line_utils.c \
		./get_next_line/get_next_line.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJ) $(BONUS_OBJ)
	@echo "<<<<all files are deleted>>>>"

fclean: clean
	@$(RM) $(NAME) $(B_NAME)

re:	fclean all

$(B_NAME) : $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(utils) -o $(B_NAME)

bonus: $(B_NAME)
