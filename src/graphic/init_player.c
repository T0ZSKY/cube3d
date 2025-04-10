/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tom.limon@>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:43:05 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/11 01:34:02 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

int	initialize_player_and_window(t_player *bob, t_struct *cube)
{
	if (init_player(bob, cube->map) == 0)
		return (ft_error("error player is not here\n"), 1);
	ft_create_windows(cube);
	if (!cube->mlx || !cube->win)
		return (ft_error("mlx ou window NULL\n"), 1);
	ft_fog_init(cube);
	printf("MLX OK, WIN OK\n");
	return (0);
}

int	init_player(t_player *p, char **map)
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
				return (1);
			}
		}
	}
	return (0);
}
