/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 06:30:48 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/07 16:58:22 by tomlimon         ###   ########.fr       */
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
			mlx_pixel_put(mlx, win, x, y, 0x00AA00FF);
		y++;
	}
}

void	raycast_column(t_player *p, t_struct *cube, int screen_x)
{
	double	camera_x;
	double	ray_angle;
	double	ray_x;
	double	ray_y;
	double	pos_x;
	double	pos_y;
	double	distance;
	int		line_height;

	camera_x = 2 * screen_x / (double)WIDTH - 1; // WIDTH = largeur de l'écran
	ray_angle = atan2(p->dir_y, p->dir_x) + camera_x * (M_PI / 4); // FOV = 60°
	ray_x = cos(ray_angle);
	ray_y = sin(ray_angle);
	pos_x = p->x;
	pos_y = p->y;

	while (1)
	{
		pos_x += ray_x * 0.01;
		pos_y += ray_y * 0.01;
		if (cube->map[(int)pos_y][(int)pos_x] == '1')
		{
			distance = sqrt((pos_x - p->x) * (pos_x - p->x)
							+ (pos_y - p->y) * (pos_y - p->y));
			line_height = (int)(HEIGHT / distance); // plus c'est loin, plus c'est petit
			draw_vertical_line(cube->mlx, cube->win, screen_x, line_height, HEIGHT);
			break ;
		}
	}
}

