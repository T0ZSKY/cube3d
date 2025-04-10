/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 06:30:48 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/10 21:43:37 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

void	perform_dda_part1(t_ray_calc *calc)
{
	if (calc->side_dist_x < calc->side_dist_y)
	{
		calc->side_dist_x += calc->delta_dist_x;
		calc->map_x += calc->step_x;
		calc->side = 0;
	}
	else
	{
		calc->side_dist_y += calc->delta_dist_y;
		calc->map_y += calc->step_y;
		calc->side = 1;
	}
}

void	perform_dda(t_ray_calc *calc, t_struct *cube)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		perform_dda_part1(calc);
		if (cube->map[calc->map_y][calc->map_x] == '1')
			hit = 1;
	}
}

void	calculate_wall_dist(t_ray_calc *calc, t_player *p, t_ray_dir *dir)
{
	if (calc->side == 0)
	{
		calc->perp_wall_dist = (calc->map_x - p->x + (1 - calc->step_x) / 2)
			/ dir->rx;
		calc->wall_x = p->y + calc->perp_wall_dist * dir->ry;
	}
	else
	{
		calc->perp_wall_dist = (calc->map_y - p->y + (1 - calc->step_y) / 2)
			/ dir->ry;
		calc->wall_x = p->x + calc->perp_wall_dist * dir->rx;
	}
	calc->wall_x -= floor(calc->wall_x);
}

int	wall_dist(t_raycast_params *params)
{
	t_ray_calc	calc;
	t_ray_dir	dir;

	dir.rx = params->rx;
	dir.ry = params->ry;
	set_step_and_side_dist(&calc, params->p, &dir);
	perform_dda(&calc, params->cube);
	calculate_wall_dist(&calc, params->p, &dir);
	*params->wall_x = calc.wall_x;
	return ((int)(HEIGHT / calc.perp_wall_dist));
}

void	init_ray_data(t_player *p, int screen_x, double *rx, double *ry)
{
	double	camera_x;

	camera_x = 2 * screen_x / (double)WIDTH - 1;
	*rx = p->dir_x + p->plane_x * camera_x;
	*ry = p->dir_y + p->plane_y * camera_x;
}
