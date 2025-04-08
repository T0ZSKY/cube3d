/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tom.limon@>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:07:36 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/08 12:36:58 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"


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
						color = 0xFFFFFF; // Mur
					else
						color = 0x000000; // Vide
					draw_pixel(cube, 10 + MINIMAP_RADIUS + x,
						10 + MINIMAP_RADIUS + y, color);
				}
			}
			x++;
		}
		y++;
	}
	//change les valeurs pour la taille du joueur
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
