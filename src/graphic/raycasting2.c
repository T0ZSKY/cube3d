/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 06:30:48 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/10 21:22:01 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

void	draw_v_line(t_struct *cube, int x, int height, t_ray_data *ray)
{
	t_line_data		data;
	t_tex_params	tex_params;
	unsigned int	color;

	data.height = height;
	data.ray = ray;
	draw_v_line_part1(&data);
	while (data.y < data.end)
	{
		tex_params.y = data.y;
		tex_params.start = data.start;
		tex_params.height = data.height;
		tex_params.texture = data.ray->texture;
		tex_params.tex_y = &(data.ray->tex_y);
		set_tex_y_params(&tex_params);
		color = *(unsigned int *)(data.ray->texture->data + (data.ray->tex_y
					* data.ray->texture->size_line + data.tex_x
					* (data.ray->texture->bpp / 8)));
		draw_pixel(cube, x, data.y, color);
		data.y++;
	}
}

void	init_step_x(t_ray_calc *calc, t_player *p, double rx)
{
	if (rx < 0)
	{
		calc->step_x = -1;
		calc->side_dist_x = (p->x - calc->map_x) * calc->delta_dist_x;
	}
	else
	{
		calc->step_x = 1;
		calc->side_dist_x = (calc->map_x + 1.0 - p->x) * calc->delta_dist_x;
	}
}

void	init_step_y(t_ray_calc *calc, t_player *p, double ry)
{
	if (ry < 0)
	{
		calc->step_y = -1;
		calc->side_dist_y = (p->y - calc->map_y) * calc->delta_dist_y;
	}
	else
	{
		calc->step_y = 1;
		calc->side_dist_y = (calc->map_y + 1.0 - p->y) * calc->delta_dist_y;
	}
}

void	set_step_and_side_dist(t_ray_calc *calc, t_player *p, t_ray_dir *dir)
{
	calc->map_x = (int)p->x;
	calc->map_y = (int)p->y;
	calc->delta_dist_x = fabs(1 / dir->rx);
	calc->delta_dist_y = fabs(1 / dir->ry);
	init_step_x(calc, p, dir->rx);
	init_step_y(calc, p, dir->ry);
}
