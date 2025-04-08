/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:08:10 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/08 23:00:35 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

void	ft_create_windows(t_struct *cube)
{
	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, WIDTH, HEIGHT, "Cube3D");
	cube->img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	cube->img_data = mlx_get_data_addr(cube->img, &cube->bpp,
			&cube->size_line, &cube->endian);
}

int	handle_keypress(int keycode, void *param)
{
	t_context	*ctx;
	t_player	*p;
	t_struct	*cube;
	double		new_x;
	double		new_y;

	ctx = (t_context *)param;
	p = ctx->p;
	cube = ctx->cube;

	printf("\n keycode : %d\n", keycode);
	if (keycode == KEY_ESC)
		exit(0);

	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		rotate_player(p, keycode);
	if (keycode == KEY_W)
	{
		new_x = p->x + p->dir_x * MOVE_SPEED;
		new_y = p->y + p->dir_y * MOVE_SPEED;
		if (cube->map[(int)new_y] && cube->map[(int)new_y][(int)new_x] != '1')
		{
			p->x = new_x;
			p->y = new_y;
		}
	}
	if (keycode == KEY_S)
	{
		new_x = p->x - p->dir_x * MOVE_SPEED;
		new_y = p->y - p->dir_y * MOVE_SPEED;
		if (cube->map[(int)new_y] && cube->map[(int)new_y][(int)new_x] != '1')
		{
			p->x = new_x;
			p->y = new_y;
		}
	}
	if (keycode == KEY_A)
	{
		new_x = p->x - p->plane_x * MOVE_SPEED;
		new_y = p->y - p->plane_y * MOVE_SPEED;
		if (cube->map[(int)new_y] && cube->map[(int)new_y][(int)new_x] != '1')
		{
			p->x = new_x;
			p->y = new_y;
		}
	}
	if (keycode == KEY_D)
	{
		new_x = p->x + p->plane_x * MOVE_SPEED;
		new_y = p->y + p->plane_y * MOVE_SPEED;
		if (cube->map[(int)new_y] && cube->map[(int)new_y][(int)new_x] != '1')
		{
			p->x = new_x;
			p->y = new_y;
		}
	}
	if (keycode == KEY_TAB)
		cube->full_screen = !cube->full_screen;
	render_scene(p, cube);
	return (0);
}
