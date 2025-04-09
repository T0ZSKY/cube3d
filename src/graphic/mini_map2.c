/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 03:01:14 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/09 03:01:37 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

void	draw_tile_minimap(t_struct *cube, t_player *p, int x,
	int y, double angle)
{
	int		world_x;
	int		world_y;
	int		color;
	double	rotated_x;
	double	rotated_y;

	rotated_x = x * cos(angle) - y * sin(angle);
	rotated_y = x * sin(angle) + y * cos(angle);
	world_x = (int)(p->x + rotated_x / MINIMAP_SCALE);
	world_y = (int)(p->y + rotated_y / MINIMAP_SCALE);
	if (world_y >= 0 && world_y < cube->map_height && world_x >= 0
		&& world_x < cube->map_width && cube->map[world_y][world_x] != '\0')
	{
		if (cube->map[world_y][world_x] == '1')
			color = 0xFFFFFF;
		else
			color = 0x000000;
	}
	else
		color = 0x000000;
	draw_pixel(cube, 10 + MINIMAP_RADIUS + x, 10 + MINIMAP_RADIUS + y, color);
}

void	draw_minimap_area(t_player *p, t_struct *cube, double angle)
{
	int	x;
	int	y;

	y = -MINIMAP_RADIUS;
	while (y < MINIMAP_RADIUS)
	{
		x = -MINIMAP_RADIUS;
		while (x < MINIMAP_RADIUS)
		{
			if (x * x + y * y < MINIMAP_RADIUS * MINIMAP_RADIUS)
				draw_tile_minimap(cube, p, x, y, angle);
			x++;
		}
		y++;
	}
}

void	draw_player_minimap(t_struct *cube)
{
	int	i;
	int	j;

	i = -2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			draw_pixel(cube, 10 + MINIMAP_RADIUS + i,
				10 + MINIMAP_RADIUS + j, 0xFF0000);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_player *p, t_struct *cube)
{
	double	angle;

	angle = atan2(p->dir_y, p->dir_x) + M_PI_2;
	draw_minimap_area(p, cube, angle);
	draw_player_minimap(cube);
}
