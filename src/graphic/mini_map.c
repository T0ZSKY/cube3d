/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:07:36 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/10 21:23:49 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

void	draw_tile(t_struct *cube, int x, int y, int tile_size)
{
	int	color;

	if (cube->map[y][x] == '1')
		color = 0xAAAAAA;
	else if (cube->map[y][x] == '0')
		color = 0x000000;
	else
		color = 0x444444;
	fill_square(cube, x * tile_size, y * tile_size, tile_size, color);
}

void	draw_minimap_f(t_struct *cube, int tile_size)
{
	int	x;
	int	y;

	y = 0;
	while (y < cube->map_height)
	{
		x = 0;
		while (x < cube->map_width)
		{
			draw_tile(cube, x, y, tile_size);
			x++;
		}
		y++;
	}
}

void	draw_player(t_player *p, t_struct *cube, int tile_size)
{
	int	player_x;
	int	player_y;
	int	i;
	int	j;

	player_x = (int)(p->x * tile_size);
	player_y = (int)(p->y * tile_size);
	i = -3;
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

void	draw_minimap_fullscreen(t_player *p, t_struct *cube)
{
	int	tile_size;

	tile_size = WIDTH / cube->map_width;
	if (HEIGHT / cube->map_height < tile_size)
		tile_size = HEIGHT / cube->map_height;
	draw_minimap_f(cube, tile_size);
	draw_player(p, cube, tile_size);
}
