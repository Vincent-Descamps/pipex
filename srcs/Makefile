# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 14:26:32 by vdescamp          #+#    #+#              #
#    Updated: 2022/06/16 14:45:53 by vdescamp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
FLAGS = -Wall -Wextra -Werror -fsanitize=address
RM = rm -f
SRCS = pipex.c \
		main.c \
		get_cmd.c \
		get_path.c \
		../libft/ft_putstr_fd.c \
		../libft/ft_split.c \
		../libft/ft_strjoin.c \
		../libft/ft_strlen.c \
		../libft/ft_strnstr.c \
		../libft/ft_substr.c \
		../libft/ft_strdup.c \
		../libft/ft_strlcat.c \
		../libft/ft_strlcpy.c

OBJS = ${SRCS:.c=.o}
all: ${NAME}
${NAME}: ${OBJS}
				${CC} ${OBJS} ${FLAGS} -o ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
				${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
