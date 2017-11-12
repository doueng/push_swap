# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: douglas <douglas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/20 09:25:40 by dengstra          #+#    #+#              #
#    Updated: 2017/07/20 13:37:14 by dengstra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER = checker
FLAGS = -Wextra -Wall -Werror
LIBFT = ./libft
LIB = libft/libft.a

CHECK_SRC =	checker.c			\
			instructions.c		\
			print_stacks.c		\
			moves.c				\
			ft_error.c			\
			free_stacks.c		\
			add_to_stack.c

CHECK_SRCO = ${CHECK_SRC:%.c=%.o}

PUSH_SRC =	push_swap.c			\
			moves.c				\
			quicksort_stacks.c	\
			ft_error.c			\
			selection_sort.c	\
			cpy_to_array.c		\
			add_to_stack.c		\
			free_stacks.c		\
			print_stacks.c

PUSH_SRCO = ${PUSH_SRC:%.c=%.o}

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(PUSH_SRCO)
	@make -C $(LIBFT)
	gcc -o $(PUSH_SWAP) $(PUSH_SRCO) $(LIB)

$(CHECKER): $(CHECK_SRCO)
	@make -C $(LIBFT)
	gcc -o $(CHECKER) $(CHECK_SRCO) $(LIB)

%.o: %.c
	@gcc -c $(FLAGS) $< -o $@

clean:
	/bin/rm -f $(CHECK_SRCO) $(PUSH_SRCO)
	@make clean -C $(LIBFT)

fclean: clean
	/bin/rm -f $(PUSH_SWAP) $(CHECKER)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: clean fclean re all
