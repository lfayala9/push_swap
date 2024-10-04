# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: layala-s <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/22 18:37:30 by layala-s          #+#    #+#              #
#    Updated: 2024/09/22 18:37:31 by layala-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

SRCS = ./instructions/reverse_rotate.c \
	   ./instructions/rotate.c \
	   ./instructions/push.c \
	   ./instructions/swap.c \
	   ./error_handlers/arg_errors.c \
	   ./utils/create_stack.c \
	   ./stack_sort/simple_sort.c

OBJS = $(SRCS:.c=.o)

all: push_swap

push_swap: $(OBJS)
				@make -C libft
				@cc $(FLAGS) push_swap.c $(SRCS) -I include ./libft/libft.a -o push_swap

clean:
		@make clean -C libft
		@rm -rf $(OBJS)

fclean:
		@make fclean -C libft
		@rm -rf $(OBJS)
		@rm -rf push_swap

re: all fclean

.PHONY: all re clean fclean bonus
