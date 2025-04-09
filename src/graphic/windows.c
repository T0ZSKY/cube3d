/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:08:10 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/09 03:12:30 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

void	render_scene(t_player *bob, t_struct *cube)
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
			raycast_column(bob, cube, x);
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

	new_x = p->x + dir_x * MOVE_SPEED;
	new_y = p->y + dir_y * MOVE_SPEED;
	return (move_player(p, cube, new_x, new_y));
}

int	handle_movement(int keycode, t_player *p, t_struct *cube)
{
	if (keycode == KEY_W)
		return (move_player_in_direction(p, cube, p->dir_x, p->dir_y));
	if (keycode == KEY_S)
		return (move_player_in_direction(p, cube, -p->dir_x, -p->dir_y));
	if (keycode == KEY_A)
		return (move_player_in_direction(p, cube, -p->plane_x, -p->plane_y));
	if (keycode == KEY_D)
		return (move_player_in_direction(p, cube, p->plane_x, p->plane_y));
	return (0);
}
