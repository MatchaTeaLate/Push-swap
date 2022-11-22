# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matcha <matcha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 10:21:07 by anovikav          #+#    #+#              #
#    Updated: 2022/11/22 14:28:43 by matcha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = clang

CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_DIR) -I $(HEADER_DIR) -I ./ -g3

LFLAGS  = -L $(LIBFT_DIR) -lft

RM = rm -rf

# **********************************FILES************************************* #

LIBFT_NAME = libft.a

HEADER_NAME = push_swap.h

SRCS_NAME =	push_swap.c			\
			action_part_one.c	\
			action_part_two.c	\
			little_sort.c		\
			stack_management.c	\
			tools.c				\
			ft_raddix.c			\
			check_error.c		\
			check_order.c		\
			display.c			\


# ********************************DIRECTORIES********************************* #

LIBFT_DIR = ./libft/

HEADER_DIR = ./includes/

SRCS_DIR = ./srcs/			

OBJS_DIR = ./srcs/

# **********************************FUSION************************************ #

LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

HEADER = $(addprefix $(HEADER_DIR), $(HEADER_NAME))
		
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAME))

OBJS = $(addprefix $(OBJS_DIR), $(SRCS_NAME:.c=.o))

# **********************************RULES************************************* #

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
		$(CC) -o $@ -c $< $(CFLAGS)

all: $(NAME)

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

$(NAME):$(LIBFT) $(OBJS_DIR) $(OBJS)
		$(CC) -o $@ $(OBJS) $(CFLAGS) $(LFLAGS)

$(OBJS_DIR):	
		mkdir -p $@

bonus:

clean:
		$(MAKE) -C libft clean
		$(RM) $(OBJS) ./objs/

fclean: clean
		$(RM) $(NAME) $(LIBFT)

re: fclean all