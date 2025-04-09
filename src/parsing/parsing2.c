/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 03:07:32 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/09 03:08:37 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

int	parse_texture_path(t_struct *cube, char *line)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		cube->path_N = ft_substr(line, 3, ft_strlen(line) - 3);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		cube->path_S = ft_substr(line, 3, ft_strlen(line) - 3);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		cube->path_W = ft_substr(line, 3, ft_strlen(line) - 3);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		cube->path_E = ft_substr(line, 3, ft_strlen(line) - 3);
	else
		return (0);
	return (1);
}

int	parse_color(t_struct *cube, char *line)
{
	if (line[0] == 'F' && line[1] == ' ')
		cube->color.floor = get_color(ft_substr(line, 2, ft_strlen(line) - 2));
	else if (line[0] == 'C' && line[1] == ' ')
		cube->color.sky = get_color(ft_substr(line, 2, ft_strlen(line) - 2));
	else
		return (0);
	return (1);
}

int	ft_path_texture(t_struct *cube, char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_error("error path"), 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strlen(line) >= 3)
		{
			if (!parse_texture_path(cube, line) && !parse_color(cube, line))
				free(line);
		}
		line = get_next_line(fd);
	}
	close(fd);
	if (!cube->path_N || !cube->path_E || !cube->path_S || !cube->path_W
		|| !cube->color.sky || !cube->color.floor)
		return (0);
	return (1);
}
