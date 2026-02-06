NAME = cub3D

FLAGS = -Wall -Wextra -Werror

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

MINILIBX_PATH = ./mlx

MINILIBX = $(MINILIBX_PATH)/libmlx.a

CC = gcc

SRC = main/main.c main/hook.c \
		movement/player_dir.c movement/player_rotate.c movement/input.c movement/player_move.c movement/player_check.c \
		init/datasetup.c init/mlx_setup.c init/texture_setup.c\
		checks/check_map.c checks/checks.c \
		parser/parse_colors.c parser/parse.c parser/parse_map.c parser/parse_texture.c parser/parse_player.c \
		render/texture.c render/render.c render/raycast.c \
		utils/check_map_utils.c utils/utils.c utils/utils_2.c utils/parse_map_utils.c utils/get_next_line.c \
		frees/free.c \
		errors/errors.c errors/detailed_errors.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
		$(CC) $(OBJ) $(FLAGS) \
		$(LIBFT) \
		$(MINILIBX_PATH)/libmlx_Linux.a \
		-L/usr/lib -lXext -lX11 -lm -lz \
		-o $(NAME)

clean:
		rm -f $(OBJ)
		$(MAKE) -C $(MINILIBX_PATH) clean
		$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

%.o: %.c
		$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(MINILIBX):
		$(MAKE) -C $(MINILIBX_PATH)

$(LIBFT):
		$(MAKE) -C $(LIBFT_PATH)
