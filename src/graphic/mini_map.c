/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tom.limon@>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:07:36 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/11 00:56:20 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

void	draw_tile(t_struct *cube, int x, int y, int tile_size)
{
	int	color;

	if (cube->fog_map[y][x] == '1')
		color = 0xAAAAAA;
	else if (cube->fog_map[y][x] == '0')
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

	update_fog_map(cube, p);
	tile_size = WIDTH / cube->map_width;
	if (HEIGHT / cube->map_height < tile_size)
		tile_size = HEIGHT / cube->map_height;
	draw_minimap_f(cube, tile_size);
	draw_player(p, cube, tile_size);
}

void ft_print_map_int(char **map)
{
	int x;

	x = 0;
	while (map[x])
	{
		printf("%s", map[x]);
		x++;
	}
}

void	ft_fog_init(t_struct *cube)
{
	int	y;
	int	a;
	int	b;

	y = 0;
	a = 0;
	cube->fog_map = malloc(sizeof(char *) * (cube->map_height + 1));
	while (y < cube->map_height)
	{
		cube->fog_map[y] = ft_strdup(cube->map[y]);
		y++;
	}
	cube->fog_map[y] = NULL;
	while (cube->fog_map[a])
	{
		b = 0;
		while (cube->fog_map[a][b])
		{
			if (cube->fog_map[a][b] != '\0' && (cube->fog_map[a][b] == '1' || cube->fog_map[a][b] == '0'))
				cube->fog_map[a][b] = '0';
			b++;
		}
		a++;
	}
	ft_print_map_int(cube->fog_map);
}

void	update_fog_map(t_struct *cube, t_player *p)
{
	int	radius;
	int	px;
	int	py;
	int	x;
	int	y;
	int	wx;
	int	wy;

	radius = 5;
	px = (int)p->x;
	py = (int)p->y;
	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			wx = px + x;
			wy = py + y;
			if (wx >= 0 && wx < cube->map_width && wy >= 0 && wy < cube->map_height)
				cube->fog_map[wy][wx] = cube->map[wy][wx];
			x++;
		}
		y++;
	}
}
