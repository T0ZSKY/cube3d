/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tom.limon@>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 07:26:09 by tomlimon          #+#    #+#             */
/*   Updated: 2025/03/31 20:28:51 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

int ft_is_map(char *line)
{
	int i;
	int has_valid_char;

	i = 0;
	has_valid_char = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != ' ' &&
			line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W' &&
			line[i] != '\n')
			return (0); // Caractère invalide, ce n'est pas une map
		if (line[i] != ' ' && line[i] != '\n')
			has_valid_char = 1; // On a au moins un caractère valable
		i++;
	}
	return (has_valid_char); // Retourne 1 si la ligne contient au moins un élément valide
}

void ft_init_map(t_struct *cube, char *path)
{
	int size;
	char *line;
	int fd;

	size = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return ;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (ft_is_map(line))
			size++;
		free(line);
	}
	close(fd);
	cube->map = malloc(sizeof(char *) * (size + 1));
	if (!cube->map)
		return ;
	cube->map[size] = NULL;
}

void ft_parsing(char *path, t_struct *cube)
{
	int fd;
	char *line;
	int i;

	i = 0;
	ft_init_map(cube, path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_error("error open file"));

	while ((line = get_next_line(fd)) != NULL)
	{
		if (ft_is_map(line))
		{
			cube->map[i] = line;
			i++;
		}
		else
			free(line);
	}
	cube->map[i] = NULL;
	close(fd);
}
