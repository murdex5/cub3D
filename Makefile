# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kadferna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 14:25:48 by kadferna          #+#    #+#              #
#    Updated: 2025/11/17 14:25:49 by kadferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRCS_DIR = ./srcs
SRCS = ${SRCS_DIR}/main.c
CFLAGS = -Wall -Werror -Wextra
OBJS = ${SRCS:.c=.o}
OBJS = ${SRCS:.c=.o}
LIBFT_PATH = ./libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a
NAME = cub3D

all: subsystems $(NAME) 

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

subsystems:
	@make -C $(LIBFT_PATH) all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re subsytems