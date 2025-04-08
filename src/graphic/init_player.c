/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:43:05 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/08 00:44:54 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

void	rotate_player(t_player *p, int keycode)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	rot_speed = ROT_SPEED;
	if (keycode == KEY_LEFT)
		rot_speed = -rot_speed;
	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rot_speed) - p->dir_y * sin(rot_speed);
	p->dir_y = old_dir_x * sin(rot_speed) + p->dir_y * cos(rot_speed);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(rot_speed) - p->plane_y * sin(rot_speed);
	p->plane_y = old_plane_x * sin(rot_speed) + p->plane_y * cos(rot_speed);
}

void	init_player(t_player *p, char **map)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'N')
			{
				p->x = x + 0.5;
				p->y = y + 0.5;
				p->dir_x = 0;
				p->plane_x = FOV;
				p->plane_y = 0.0;
				p->dir_y = -1;
				map[y][x] = '0';
				return ;
			}
		}
	}
}
