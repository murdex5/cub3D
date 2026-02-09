/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:24:17 by msisto            #+#    #+#             */
/*   Updated: 2026/02/09 12:16:49 by kadferna         ###   ########.fr       */
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
	{
		perror("cub3D");
		exit(1);
	}
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
	map_info->content = ft_calloc(sizeof(char *), (lines + 1));
	map_info->content[lines] = NULL;
	if (!map_info->content)
	{
		free_tab((void **)map_info->content);
		map_info->content = NULL;
	}
	if (!read_map_files(map_info, path))
	{
		free_tab((void **)map_info->content);
		map_info->content = NULL;
	}
	parse_textures(data);
	if (!set_colors(&data->texture, &data->map_info, lines))
	{
		free_tab((void **)map_info->content);
		map_info->content = NULL;
	}
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
		free_exit(data, 3, "Error\nCould not allocate memory");
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
		free_err_file(data, 1, "Wrong file type! expected type .cub", MAP_MSG);
	if (stat(path, &buffer) != 0)
	{
		printf("Error\nFile not found %s\n", path);
		free_exit(data, 1, NULL);
	}
	map_setup(&data->map_info);
	map_pop(data, &data->map_info, path);
	check_map(data, &data->map_info);
	get_just_map(data, &data->map_info);
	if (!data->texture.ceiling || !data->texture.floor)
		free_err_file(data, 3, "Invalid color\n", COLOR_MSG);
}
