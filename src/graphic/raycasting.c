/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tom.limon@>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 06:30:48 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/06 21:33:06 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

//raycasting wyp

void	draw_vertical_line(void *mlx, void *win, int x, int height, int win_height)
{
	int y;
	int start;
	int end;

	start = (win_height / 2) - (height / 2);
	end = (win_height / 2) + (height / 2);

	if (start < 0)
		start = 0;
	if (end > win_height)
		end = win_height;

	y = start;

	while (y < end)
	{
		if (x >= 0 && x < 800) // protection horizontale aussi
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
		y++;
	}
}

void	simple_raycast(t_player *p, char **map)
{
	double	ray_x = p->dir_x;
	double	ray_y = p->dir_y;

	double	pos_x = p->x;
	double	pos_y = p->y;

	while (1)
	{
		pos_x += ray_x * 0.01;
		pos_y += ray_y * 0.01;

		if (map[(int)pos_y][(int)pos_x] == '1')
		{
			double dist = sqrt((pos_x - p->x) * (pos_x - p->x) + (pos_y - p->y) * (pos_y - p->y));
			printf("Mur détecté à %.2f unités !\n", dist);
			break ;
		}
	}
}
