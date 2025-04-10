/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:08:18 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/10 22:30:30 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

int	move_player(t_player *p, t_struct *cube, double new_x, double new_y)
{
	if (cube->map[(int)new_y] && cube->map[(int)new_y][(int)new_x] != '1')
	{
		p->x = new_x;
		p->y = new_y;
	}
	return (0);
}

int	move_player_in_direction(t_player *p, t_struct *cube,
	double dir_x, double dir_y)
{
	double	new_x;
	double	new_y;

	new_x = p->x + dir_x * 0.1;
	new_y = p->y + dir_y * 0.1;
	return (move_player(p, cube, new_x, new_y));
}

int	key_press(int keycode, t_context *ctx)
{
	if (keycode == KEY_W)
		ctx->cube->keys.w = 1;
	if (keycode == KEY_S)
		ctx->cube->keys.s = 1;
	if (keycode == KEY_A)
		ctx->cube->keys.a = 1;
	if (keycode == KEY_D)
		ctx->cube->keys.d = 1;
	if (keycode == KEY_LEFT)
		ctx->cube->keys.left = 1;
	if (keycode == KEY_RIGHT)
		ctx->cube->keys.right = 1;
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int	key_release(int keycode, t_context *ctx)
{
	if (keycode == KEY_W)
		ctx->cube->keys.w = 0;
	if (keycode == KEY_S)
		ctx->cube->keys.s = 0;
	if (keycode == KEY_A)
		ctx->cube->keys.a = 0;
	if (keycode == KEY_D)
		ctx->cube->keys.d = 0;
	if (keycode == KEY_LEFT)
		ctx->cube->keys.left = 0;
	if (keycode == KEY_RIGHT)
		ctx->cube->keys.right = 0;
	return (0);
}

void	rotate_player(t_player *p, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir_x;
	old_plane_x = p->plane_x;
	p->dir_x = p->dir_x * cos(angle) - p->dir_y * sin(angle);
	p->dir_y = old_dir_x * sin(angle) + p->dir_y * cos(angle);
	p->plane_x = p->plane_x * cos(angle) - p->plane_y * sin(angle);
	p->plane_y = old_plane_x * sin(angle) + p->plane_y * cos(angle);
}
