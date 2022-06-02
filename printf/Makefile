# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 16:25:41 by vdescamp          #+#    #+#              #
#    Updated: 2021/11/15 18:52:19 by vdescamp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = ft_printf.c		\
		ft_check.c 		\
		ft_varchar_c.c 	\
		ft_varstr_s.c 	\
		ft_varint_i.c 	\
		ft_varunsint_u.c\
		ft_varpercent.c \
		ft_varhex_x.c	\
		ft_varptr_p.c	\

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
