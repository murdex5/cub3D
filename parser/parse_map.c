/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:24:17 by msisto            #+#    #+#             */
/*   Updated: 2026/02/16 13:08:55 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	read_map_files(t_map *map_info, char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map_info->content[i] = ft_strdup(line);
		free(line);
		if (!map_info->content[i])
			return (free_n_return(map_info->content, NULL, NULL), 0);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

void	map_pop(t_data *data, t_map *map_info, char *path)
{
	int	lines;

	lines = count_lines(path);
	if (lines == 0)
		free_exit(data, 2, RED"Error\nFile empty\n"RESET);
	map_info->content = ft_calloc(sizeof(char *), (lines + 1));
	map_info->content[lines] = NULL;
	if (!map_info->content)
		free_exit(data, 2, RED"Error\nCould not allocate memory\n"RESET);
	if (!read_map_files(map_info, path))
		free_exit(data, 3, RED"Error\nRead file failed\n"RESET);
	parse_textures(data);
	if (!set_colors(&data->texture, &data->map_info, lines))
		free_exit(data, 3, NULL);
}

void	get_just_map(t_data *data, t_map *map_info)
{
	int		arr_len;
	int		actual_lines;
	int		i;
	int		j;

	i = map_info->lst_itr;
	arr_len = str_arr_len(map_info->content);
	actual_lines = arr_len - map_info->lst_itr;
	if (actual_lines <= 0)
		free_exit(data, 3, NULL);
	data->map = ft_calloc(sizeof(char *), actual_lines + 1);
	if (!data->map)
		free_exit(data, 3, RED"Error\nCould not allocate memory"RESET);
	j = 0;
	while (i < arr_len && map_info->content[i])
	{
		data->map[j] = ft_strdup(map_info->content[i]);
		if (!data->map[j])
			return (free_tab((void **)data->map));
		i++;
		j++;
	}
}

void	parse_map(t_data *data, char *path)
{
	struct stat	buffer;

	if (!check_file_type(path, ".cub"))
		free_exit(data, 1, "Not a .cub file");
	if (stat(path, &buffer) != 0)
	{
		printf(RED"Error\nFile not found %s\n"RESET, path);
		free_exit(data, 1, NULL);
	}
	map_setup(&data->map_info);
	map_pop(data, &data->map_info, path);
	check_map(data, &data->map_info);
	get_just_map(data, &data->map_info);
	if (!data->texture.ceiling || !data->texture.floor)
		free_err_file(data, 3, RED"Invalid color\n"RESET, COLOR_NEG);
}
