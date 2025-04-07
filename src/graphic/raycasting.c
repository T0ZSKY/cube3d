/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 06:30:48 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/07 22:37:28 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

void	draw_pixel(t_struct *cube, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = cube->img_data + (y * cube->size_line + x * (cube->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_vertical_line(t_struct *cube, int x, int height)
{
	int	start;
	int	end;
	int	y;

	start = (HEIGHT / 2) - (height / 2);
	end = (HEIGHT / 2) + (height / 2);
	y = start;
	if (start < 0)
		start = 0;
	if (end > HEIGHT)
		end = HEIGHT;
	while (y < end)
	{
		draw_pixel(cube, x, y, 0x00AA00FF);
		y++;
	}
}

static void	init_ray_data(t_player *p, int screen_x, double *rx, double *ry)
{
	double	camera_x;
	double	ray_angle;

	camera_x = 2 * screen_x / (double)WIDTH - 1;
	ray_angle = atan2(p->dir_y, p->dir_x) + camera_x * (M_PI / 4);
	*rx = cos(ray_angle);
	*ry = sin(ray_angle);
}

static int	wall_dist(t_player *p, t_struct *cube, double rx, double ry)
{
	double	pos_x;
	double	pos_y;
	double	distance;

	pos_x = p->x;
	pos_y = p->y;
	while (1)
	{
		pos_x += rx * 0.01;
		pos_y += ry * 0.01;
		if (cube->map[(int)pos_y][(int)pos_x] == '1')
		{
			distance = get_distance(p->x, p->y, pos_x, pos_y);
			return ((int)(HEIGHT / distance));
		}
	}
	return (0);
}

void	raycast_column(t_player *p, t_struct *cube, int screen_x)
{
	double	rx;
	double	ry;
	int		line_height;

	init_ray_data(p, screen_x, &rx, &ry);
	line_height = wall_dist(p, cube, rx, ry);
	draw_vertical_line(cube, screen_x, line_height);
}
