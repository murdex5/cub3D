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
# include <stdio.h>
# include <stdlib.h>

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

/* Structs */

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
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
	char		start_dir;

	t_textures	*textures;
	int			floor_color;
	int			ceiling_color;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_player	*player;
}				t_game;

// Errors
int				err_msg_std(char *msg);

// Freees
void			free_texture(t_textures *texture, void *mlx);
void			free_map(t_map *map, void *mlx);
void			free_char_array(char **arr);
int				free_n_return(char **str, char *temp, char *msg);

// Utils
int				check_if_null_text(t_textures *textures);
int				ft_strcmp(const char *s1, const char *s2);

// Checks
int				check_loaded(t_textures *textures);
int				check_file_type(char *file, char *type);
int				check_map(t_map *map);

// Parsing
int				assign_colors(char **content, int i, t_map *map);
int				count_lines(char *file);
t_textures		*parse_textures(t_map *map, void *mlx);
t_map			*parse_map(char *path, void *mlx);

#endif