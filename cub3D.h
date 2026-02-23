/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:25:31 by msisto            #+#    #+#             */
/*   Updated: 2026/02/16 13:08:35 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define RESET	"\e[0m"

# define WIN_HEIGHT 720
# define WIN_WIDTH 960

# define ROTSPEED 0.015
# define MOVSPEED 0.015

# define ERR_MSG "Error\nFailed to Populate.check File Paths Or Colour inputs\n"
# define TEXTURE_MSG "err_files/texture_order.txt"
# define MAP_MSG "err_files/map_order.txt"
# define EXPECTED_MSG "err_files/expected_format.txt"
# define COLOR_NEG "err_files/color_negative.txt"

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_texture
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_texture;

typedef struct s_player
{
	char	dir;
	int		moved;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;

typedef struct s_raycast
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_map
{
	char		**content;
	int			width;
	int			height;
	int			lst_itr;
	int			content_order;
	int			player_count;
}				t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	t_player	player;
	t_ray		ray;
	t_texture	texture;
	int			**texture_pixels;
	int			**textures;
	t_map		map_info;
	char		**map;
}	t_data;

/*checks*/

/*check_map.c*/
int				check_top_bot(t_map *map);
int				check_surrounded(t_map *map_info);
int				check_valid_chars(t_map *map_info);
void			check_map(t_data *data, t_map *map_info);
int				has_holes(char **map);
/*checks.c*/
int				check_file_type(char *file, char *type);
int				check_instances(char *line);
int				check_zero(char **map, int k);

/*init*/

/*datasetup.c*/
void			map_setup(t_map *map_info);
void			ray_set(t_ray *ray);
void			player_setup(t_player *player);
void			data_setup(t_data *data);
/*mlx_setup.c*/
void			init_img_clean(t_img *img);
void			img_setup(t_data *data, t_img *image, int width, int height);
void			init_texture_img(t_data *data, t_img *image, char *path);
void			mlx_setup(t_data *data);
/*texture_setup.c*/
int				*xpm_to_img(t_data *data, char *path);
void			init_textures(t_data *data);
void			texture_setup(t_texture *textures);

/*render*/

/*raycast.c*/
void			init_ray_info(int x, t_ray *ray, t_player *player);
void			start_dda(t_ray *ray, t_player *player);
void			perform_dda(t_data *data, t_ray *ray);
void			line_calc(t_data *data, t_ray *ray, t_player *player);
void			raycasting(t_player *player, t_data *data);
/*render.c*/
void			set_frame_image_pixel(t_data *data, t_img *image, int x, int y);
void			render_frame(t_data *data);
void			render_raycast(t_data *data);
void			render_images(t_data *data);
int				render(t_data *data);
/*texture.c*/
void			init_texture_pixels(t_data *data);
void			get_texture_index(t_data *data, t_ray *ray);
void			update_tp(t_data *data, t_texture *tex, t_ray *ray, int x);

/*parser*/

/*parse_colors.c*/
int				*get_color(char *line);
void			assign_colors(t_texture *tex, char *line);
unsigned long	convert_rgb_to_hex(int *rgb_tab);
int				set_colors(t_texture *tex, t_map *map_info, int lines);

/*parse.c*/
void			parse_data(t_data *data, char *path);
/*parse_map.c*/
int				read_map_files(t_map *map_info, char *file);
void			map_pop(t_data *data, t_map *map_info, char *path);
void			get_just_map(t_data *data, t_map *map_info);
void			parse_map(t_data *data, char *path);
/*parse_texture.c*/
void			assign_paths(char **content, int i, t_texture *textures);
void			get_text_path(t_data *data, t_map *map, t_texture *texture);
void			parse_textures(t_data *data);
/*parse_player.c*/
void			player_pos(t_map *map_info, t_player *player, char **map);
void			parse_player(t_data *data);

/*utils*/

/*check_map_utils.c*/
void			mod_lst_it(t_map *map_info);
int				check_just_chars(char c);
void			get_h_w(t_map *map_info);
int				check_one(char c);
/*parse_map_utils.c*/
int				check_for_map(t_map *map_info, int lines, int i);
/*utils.c*/
int				ft_strcmp(const char *s1, const char *s2);
int				count_lines(char *file);
int				str_arr_len(char **str);
int				count_lines_arr(char **arr);
void			set_image_pixel(t_img *image, int x, int y, int color);
/*utils_2.c*/
int				check_whole_str(char *str);
int				str_arr_len_eof(char **str);
int				is_present(char c);
/*get_next_line.c*/
char			*get_line(int fd, char *buf, char *buffer);
char			*clean_up(char *line);
char			*get_next_line(int fd);

/*frees*/

/*free.c*/
void			free_exit(t_data *data, int lvl, char *msg);
void			free_tab(void **tab);
int				free_n_return(char **str, char *temp, char *msg);
void			free_err_file(t_data *data, int lvl, char *msg, char *f_p);
/*errors*/

/*errors.c*/
int				err_msg_std(char *msg);
/*detailed_errors.c*/
int				read_files(char *file);
void			detailed_err_msg_order(char *path);

/*movement*/

/*input.c*/
int				key_press_handler(int key, t_data *data);
int				key_release_handler(int key, t_data *data);
void			input(t_data *data);
/*player_check.c*/
bool			map_pos_check(t_data *data, double x, double y);
bool			is_valid_pos(t_data *data, double x, double y);
int				validate_move(t_data *data, double new_x, double new_y);
/*player_dir.c*/
void			init_player_north_south(t_player *player);
void			init_player_east_west(t_player *player);
void			init_player_direction(t_data *data);
/*player_move.c*/
int				move_forward(t_data *data);
int				move_backward(t_data *data);
int				move_left(t_data *data);
int				move_right(t_data *data);
int				move_player(t_data *data);
/*player_rotate.c*/
int				rotate_left_right(t_data *data, double rotspeed);
int				rotate_player(t_data *data, double rotdir);

/*main*/

/*hook.c*/
void			t_struct_free(t_texture *texture);
void			on_key_press_exit(t_data *data, int lvl);
int				quit(t_data *data);
/*main.c*/
void			texture_setup(t_texture *texture);

#endif
