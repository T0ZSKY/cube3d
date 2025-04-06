/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tom.limon@>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:43:05 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/06 21:19:25 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

void	init_player(t_player *p, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N')
			{
				p->x = x + 0.5;
				p->y = y + 0.5;
				p->dir_x = 0;
				p->dir_y = -1;
				map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}
