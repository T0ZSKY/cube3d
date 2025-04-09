/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 07:26:09 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/09 03:07:52 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

int	ft_is_map(char *line)
{
	int	i;
	int	has_valid_char;

	i = 0;
	has_valid_char = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != ' '
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W'
			&& line[i] != '\n')
			return (0);
		if (line[i] != ' ' && line[i] != '\n')
			has_valid_char = 1;
		i++;
	}
	return (has_valid_char);
}

void	ft_init_map(t_struct *cube, char *path)
{
	int		size;
	char	*line;
	int		fd;

	size = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_is_map(line))
			size++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	cube->map = malloc(sizeof(char *) * (size + 1));
	if (!cube->map)
		return ;
	cube->map[size] = NULL;
	cube->map_height = size;
}

void	ft_parsing(char *path, t_struct *cube)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	ft_init_map(cube, path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_error("error open file"));
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_is_map(line))
		{
			cube->map[i] = line;
			i++;
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	cube->map[i] = NULL;
	close(fd);
}

int	ft_chech_assets(t_struct *cube)
{
	int	fd;

	fd = open(cube->path_N, O_RDONLY);
	if (fd == -1)
		return (printf("erreur : %s", cube->path_N), 0);
	close(fd);
	fd = open(cube->path_E, O_RDONLY);
	if (fd == -1)
		return (printf("erreur : %s", cube->path_E), 0);
	close(fd);
	fd = open(cube->path_W, O_RDONLY);
	if (fd == -1)
		return (printf("erreur : %s", cube->path_W), 0);
	close(fd);
	fd = open(cube->path_S, O_RDONLY);
	if (fd == -1)
		return (printf("erreur : %s", cube->path_S), 0);
	close(fd);
	return (1);
}
