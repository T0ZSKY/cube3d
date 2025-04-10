/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 06:30:48 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/10 21:23:01 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

void	draw_pixel(t_struct *cube, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = cube->img_data + (y * cube->size_line + x * (cube->bpp / 8));
	*(unsigned int *)dst = color;
}

void	set_tex_x(int *tex_x, double wall_x, t_texture *texture)
{
	*tex_x = (int)(wall_x * (double)texture->width);
	if (*tex_x < 0)
		*tex_x = 0;
	if (*tex_x >= texture->width)
		*tex_x = texture->width - 1;
}

void	set_tex_y_params(t_tex_params *params)
{
	int	tex_y;

	tex_y = ((params->y - params->start) * params->texture->height)
		/ params->height;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= params->texture->height)
		tex_y = params->texture->height - 1;
	*params->tex_y = tex_y;
}

void	draw_v_line_part1(t_line_data *data)
{
	data->start = (HEIGHT / 2) - (data->height / 2);
	data->end = (HEIGHT / 2) + (data->height / 2);
	data->y = data->start;
	set_tex_x(&data->tex_x, data->ray->wall_x, data->ray->texture);
}

void	raycast_column(t_player *p, t_struct *cube, int screen_x,
	t_texture *texture)
{
	t_ray_data			ray;
	t_raycast_params	params;
	double				rx;
	double				ry;

	init_ray_data(p, screen_x, &rx, &ry);
	params.p = p;
	params.cube = cube;
	params.rx = rx;
	params.ry = ry;
	params.wall_x = &(ray.wall_x);
	ray.texture = texture;
	draw_v_line(cube, screen_x, wall_dist(&params), &ray);
}
