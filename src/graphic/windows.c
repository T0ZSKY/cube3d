/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:08:10 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/10 21:26:08 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

void	render_scene(t_player *bob, t_struct *cube, t_texture *texture)
{
	int	x;

	if (cube->img)
		mlx_destroy_image(cube->mlx, cube->img);
	cube->img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	cube->img_data = mlx_get_data_addr(cube->img, &cube->bpp,
			&cube->size_line, &cube->endian);
	if (cube->full_screen == 0)
	{
		fill_background(cube);
		x = -1;
		while (++x < WIDTH)
			raycast_column(bob, cube, x, texture);
		draw_minimap(bob, cube);
	}
	else
		draw_minimap_fullscreen(bob, cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->img, 0, 0);
}

void	ft_create_windows(t_struct *cube)
{
	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, WIDTH, HEIGHT, "Cube3D");
	cube->img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	cube->img_data = mlx_get_data_addr(cube->img, &cube->bpp,
			&cube->size_line, &cube->endian);
}

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

int	handle_movement(int keycode, t_player *p, t_struct *cube)
{
	double	speed;

	if (p->is_running)
		speed = p->run_speed;
	else
		speed = p->speed;
	if (keycode == KEY_W)
		return (move_player_in_direction(p, cube, p->dir_x * speed, p->dir_y * speed));
	if (keycode == KEY_S)
		return (move_player_in_direction(p, cube, -p->dir_x * speed, -p->dir_y * speed));
	if (keycode == KEY_A)
		return (move_player_in_direction(p, cube, -p->plane_x * speed, -p->plane_y * speed));
	if (keycode == KEY_D)
		return (move_player_in_direction(p, cube, p->plane_x * speed, p->plane_y * speed));
	return (0);
}
