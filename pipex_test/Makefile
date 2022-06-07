# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 10:53:08 by vdescamp          #+#    #+#              #
#    Updated: 2022/06/07 10:48:44 by vdescamp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = retest.c \
		../libft/ft_strlen.c \
		../libft/ft_strnstr.c \
		../libft/ft_substr.c \
		../libft/ft_strdup.c \
		../printf/ft_printf.c \
		../printf/ft_check.c \
		../printf/ft_varstr_s.c \
		../printf/ft_varchar_c.c \
		../printf/ft_varhex_x.c \
		../printf/ft_varint_i.c \
		../printf/ft_varpercent.c \
		../printf/ft_varptr_p.c \
		../printf/ft_varunsint_u.c \

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
