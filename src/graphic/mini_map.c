/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:07:36 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/08 16:26:27 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"


void	draw_minimap_fullscreen(t_player *p, t_struct *cube)
{
	int	x;
	int	y;
	int	color;
	int	tile_size;

	tile_size = WIDTH / cube->map_width;
	if (HEIGHT / cube->map_height < tile_size)
		tile_size = HEIGHT / cube->map_height;
	y = 0;
	while (y < cube->map_height)
	{
		x = 0;
		while (x < cube->map_width)
		{
			if (cube->map[y][x] == '1')
				color = 0xAAAAAA;
			else if (cube->map[y][x] == '0')
				color = 0x000000;
			else
				color = 0x444444;

			fill_square(cube, x * tile_size, y * tile_size, tile_size, color);
			x++;
		}
		y++;
	}
	int	player_x = (int)(p->x * tile_size);
	int	player_y = (int)(p->y * tile_size);
	int i = -3;
	int j;
	while (i <= 3)
	{
		j = -3;
		while (j <= 3)
		{
			draw_pixel(cube, player_x + i, player_y + j, 0xFF0000);
			j++;
		}
		i++;
	}
}


void	draw_minimap(t_player *p, t_struct *cube)
{
	int	x;
	int	y;
	int	world_x;
	int i = -2;
	int j;
	int	world_y;
	int	color;

	y = -MINIMAP_RADIUS;
	while (y < MINIMAP_RADIUS)
	{
		x = -MINIMAP_RADIUS;
		while (x < MINIMAP_RADIUS)
		{
			if (x * x + y * y < MINIMAP_RADIUS * MINIMAP_RADIUS)
			{
				world_x = (int)(p->x + (float)x / MINIMAP_SCALE);
				world_y = (int)(p->y + (float)y / MINIMAP_SCALE);
				if (world_y >= 0 && world_y < cube->map_height
					&& world_x >= 0 && cube->map[world_y][world_x] != '\0')
				{
					if (cube->map[world_y][world_x] == '1')
						color = 0xFFFFFF;
					else
						color = 0x000000;
					draw_pixel(cube, 10 + MINIMAP_RADIUS + x,
						10 + MINIMAP_RADIUS + y, color);
				}
				else
				{
					color = 0x000000;
					draw_pixel(cube, 10 + MINIMAP_RADIUS + x,
						10 + MINIMAP_RADIUS + y, color);
				}
			}
			x++;
		}
		y++;
	}
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			draw_pixel(cube, 10 + MINIMAP_RADIUS + i, 10 + MINIMAP_RADIUS + j, 0xFF0000);
			j++;
		}
		i++;
}
}
