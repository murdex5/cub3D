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
SRCS = 	${SRCS_DIR}/errors/detailed_errors.c \
		${SRCS_DIR}/errors/errors.c \
		${SRCS_DIR}/frees/textures_free.c \
		${SRCS_DIR}/frees/map_free.c \
		${SRCS_DIR}/frees/free.c \
		${SRCS_DIR}/utils/check_map_utils.c \
		${SRCS_DIR}/utils/parse_textures_utils.c \
		${SRCS_DIR}/utils/parse_map_utils.c \
		${SRCS_DIR}/utils/utils.c \
		${SRCS_DIR}/checks/check_map.c \
		${SRCS_DIR}/checks/checks.c \
		${SRCS_DIR}/parsing/parse_player.c \
		${SRCS_DIR}/parsing/parse_colors.c \
		${SRCS_DIR}/parsing/parse_textures.c \
		${SRCS_DIR}/parsing/parse_map.c \
		${SRCS_DIR}/parsing/parse.c \
		${SRCS_DIR}/main/main.c
CFLAGS = -Wall -Werror -Wextra
OBJS = ${SRCS:.c=.o}
OBJS = ${SRCS:.c=.o}

# LIBFT	
LIBFT_PATH = ./libft
LIBFT_LIB  = $(LIBFT_PATH)/libft.a

# MLX
MLX_PATH = ./mlx
MLX_LIB	 = $(MLX_PATH)/libmlx.a

NAME = cub3D

ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
	MLX_INCLUDES = -I/usr/include -Imlx
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
	MLX_INCLUDES = -I/opt/X11/include -Imlx
endif

all: subsystems $(NAME) 

%.o : %.c
	$(CC) $(CFLAGS)  $(MLX_INCLUDES) -O3 -c -o $@ $<

subsystems:
	@make -C $(LIBFT_PATH) all
	@make -C $(MLX_PATH) all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(MLX_PATH) clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re subsytems