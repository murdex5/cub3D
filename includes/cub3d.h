/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:25:34 by kadferna          #+#    #+#             */
/*   Updated: 2025/11/17 14:25:36 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>

/* DATA TYPES */

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

# define IDLE 0
# define RUN 1
# define ATTACK 2
# define RIGHT 3
# define LEFT 4

# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480

# define ERR_MSG "Error\nFailed to Populate. Please check File Paths Or Colour inputs\n"
# define COLOR_MSG "err_files/color_order.txt"
# define TEXTURE_MSG "err_files/texture_order.txt"
# define MAP_MSG "err_files/map_order.txt"
# define EXPECTED_MSG "err_files/expected_format.txt"
# define COLOR_NEG "err_files/color_negative.txt"

/* Structs */

typedef struct s_player
{
	int			pos_x;
	int			pos_y;
	int			dir_x;
	int			dir_y;
}				t_player;

typedef struct s_texture
{
	void		*img;
	char		*path;
	int			img_height;
	int			img_width;
}				t_texture;

typedef struct s_textures
{
	t_texture	*north;
	t_texture	*south;
	t_texture	*west;
	t_texture	*east;

}				t_textures;

typedef struct s_map
{
	char		**content;
	int			width;
	int			height;
	int			start_x;
	int			start_y;
	int			lst_itr;
	int			playr_count;
	t_textures	*textures;
	int			floor_color;
	int			ceiling_color;
	int			content_order;
}				t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_textures	*textures;
	int			win_height;
	int			win_width;
	t_player	*player;
}				t_data;

// Errors
int				err_msg_std(char *msg);
void			detailed_err_msg_order(char *path);
void			mulitiple_de_msg(char *path1, char *path2);

// Freees
void			free_mlx(void *mlx);
void			free_player(t_player *player);
void			free_mlx(void *mlx);
void			free_texture(t_textures *texture, void *mlx);
void			free_map(t_map *map, void *mlx);
void			free_char_array(char **arr);
int				free_n_return(char **str, char *temp, char *msg);
void			free_t_data(t_data *data);

// Utils
void			mod_lst_it(t_map *map);
void			get_h_w(t_map *map);
int				check_one(char c);
int				check_just_chars(char c);
int				set_colors(t_map *map, int lines);
t_textures		*assign_paths(char **content, int i, t_textures *textures);
int				count_lines_arr(char **arr);
int				load_textures(t_textures *textures, void *mlx);
int				get_player_pos(t_map *map);
int				count_lines(char *file);
int				is_present(char c);
int				str_arr_len(char **str);
int				str_arr_len_EOF(char **str);
int				check_if_null_text(t_textures *textures);
int				ft_strcmp(const char *s1, const char *s2);

// Checks
int				check_holes(char **map, char *line, int k);
int				has_holes(char **map);
int				check_loaded(t_textures *textures);
int				check_file_type(char *file, char *type);
int				check_map(t_map *map);

// Parsing
int				read_map_files(t_map *map, char *file);
int				assign_colors(char **content, int i, t_map *map);
t_textures		*get_tex_path(t_map *map, t_textures *textures);
int				load_texture(t_texture *texture, void *mlx);
t_textures		*parse_textures(t_map *map, void *mlx);
t_map			*parse_map(char *path, void *mlx);
t_player		*parse_player(t_map *map);
t_data			*parse_data(char *path);

// hooks
int				on_keypress(int keysym, t_data *data);

#endif