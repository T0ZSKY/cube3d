/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:43:05 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/09 22:10:32 by tomlimon         ###   ########.fr       */
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
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == 'W')
			{
				p->x = x + 0.5;
				p->y = y + 0.5;
				p->speed = 1;
    			p->run_speed = 2;
    			p->is_running = 0;
				if (map[y][x] == 'N')
				{
					p->dir_x = 0;
					p->dir_y = -1;
					p->plane_x = FOV;
					p->plane_y = 0;
				}
				else if (map[y][x] == 'S')
				{
					p->dir_x = 0;
					p->dir_y = 1;
					p->plane_x = -FOV;
					p->plane_y = 0;
				}
				else if (map[y][x] == 'E')
				{
					p->dir_x = 1;
					p->dir_y = 0;
					p->plane_x = 0;
					p->plane_y = FOV;
				}
				else if (map[y][x] == 'W')
				{
					p->dir_x = -1;
					p->dir_y = 0;
					p->plane_x = 0;
					p->plane_y = -FOV;
				}
				map[y][x] = '0';
				return ;
			}
		}
	}
}
