/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:17:56 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/09 03:16:45 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

void	fill_square(t_struct *cube, int start_x, int start_y,
	int size, int color)
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

void	remove_newline(char *path)
{
	int	len;

	if (path)
	{
		len = ft_strlen(path);
		if (len > 0 && path[len - 1] == '\n')
			path[len - 1] = '\0';
	}
}

void	ft_remove_back_path(t_struct *cube)
{
	remove_newline(cube->path_N);
	remove_newline(cube->path_S);
	remove_newline(cube->path_E);
	remove_newline(cube->path_W);
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

unsigned int	get_color(char *code)
{
	unsigned int	i;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	i = 0;
	r = 0;
	g = 0;
	b = 0;
	while (code[i] == ' ')
		i++;
	while (code[i] && code[i] != ',')
		r = r * 10 + (code[i++] - '0');
	i++;
	while (code[i] && code[i] != ',')
		g = g * 10 + (code[i++] - '0');
	i++;
	while (code[i] && code[i] != '\n' && code[i] != '\0')
		b = b * 10 + (code[i++] - '0');
	return ((0x37 << 24) | (r << 16) | (g << 8) | b);
}
