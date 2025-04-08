/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:17:56 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/08 13:45:39 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

void	fill_square(t_struct *cube, int start_x, int start_y, int size, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			draw_pixel(cube, start_x + x, start_y + y, color);
			x++;
		}
		y++;
	}
}


void	ft_remove_back_path(t_struct *cube)
{
	char	*path;
	int		len;

	path = cube->path_N;
	if (path)
	{
		len = ft_strlen(path);
		if (len > 0 && path[len - 1] == '\n')
			path[len - 1] = '\0';
	}
	path = cube->path_S;
	if (path)
	{
		len = ft_strlen(path);
		if (len > 0 && path[len - 1] == '\n')
			path[len - 1] = '\0';
	}
	path = cube->path_E;
	if (path)
	{
		len = ft_strlen(path);
		if (len > 0 && path[len - 1] == '\n')
			path[len - 1] = '\0';
	}
	path = cube->path_W;
	if (path)
	{
		len = ft_strlen(path);
		if (len > 0 && path[len - 1] == '\n')
			path[len - 1] = '\0';
	}
}

void	ft_set_max(t_struct *cube)
{
	int		i;
	size_t	max;

	i = 0;
	max = 0;
	while (cube->map[i])
	{
		if (max < ft_strlen(cube->map[i]))
			max = ft_strlen(cube->map[i]);
		i++;
	}
	cube->map_width = (int)max;
}

/*
char	*get_color(char *color)
{
	
}
*/
