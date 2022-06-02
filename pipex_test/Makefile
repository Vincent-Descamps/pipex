# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 10:53:08 by vdescamp          #+#    #+#              #
#    Updated: 2022/05/31 11:06:39 by vdescamp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a
CC = gcc
CFLAGS = #-Wall -Wextra -Werror
RM = rm -f

SRCS = retest.c \
		../libft/ft_strlen.c \
		../libft/ft_strnstr.c \
		../libft/ft_substr.c \
		../libft/ft_strdup.c \
		../ft_printf/ft_printf.c \
		../ft_printf/ft_check.c \
		../ft_printf/ft_str_s.c \
		../ft_printf/ft_char_c.c \
		../ft_printf/ft_hex_x.c \
		../ft_printf/ft_int_i.c \
		../ft_printf/ft_percent.c \
		../ft_printf/ft_ptr_p.c \
		../ft_printf/ft_unsint_u.c \

OBJS = ${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re : fclean all clean

.PHONY: all clean fclean re
