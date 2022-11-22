# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 15:23:13 by anovikav          #+#    #+#              #
#    Updated: 2022/10/01 20:26:30 by anovikav         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	ft_atoi.c ft_calloc.c ft_isalpha.c ft_isdigit.c ft_itoa.c ft_memcmp.c ft_memmove.c ft_putchar_fd.c ft_tolower.c							\
		ft_putnbr_fd.c ft_split.c ft_strdup.c ft_strjoin.c ft_strlcpy.c ft_strmapi.c ft_strnstr.c ft_strtrim.c 	ft_bzero.c						\
		ft_isalnum.c ft_isascii.c ft_isprint.c ft_memchr.c ft_memcpy.c ft_memset.c ft_putendl_fd.c ft_putstr_fd.c ft_strchr.c					\
		ft_striteri.c ft_strlcat.c ft_strlen.c ft_strncmp.c ft_strrchr.c ft_substr.c ft_toupper.c ft_printf/printf_x.c ft_printf/ft_printf.c	\
		ft_printf/printf_c.c ft_printf/printf_id.c ft_printf/printf_p.c ft_printf/printf_s.c ft_printf/printf_u.c ft_printf/tools.c				\

BONUS =	ft_lstadd_back.c ft_lstdelone.c ft_lstsize.c ft_lstadd_front.c ft_lstlast.c ft_lstclear.c ft_lstnew.c ft_lstiter.c ft_lstmap.c	\

CC = gcc

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	ar -rc libft.a $(OBJ)

bonus: $(OBJ) $(BONUS_OBJ)
	ar -rc libft.a $(OBJ) $(BONUS_OBJ)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

fclean: clean
	$(RM) $(NAME)

re: fclean all
