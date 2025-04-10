/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:08:10 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/10 23:12:15 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

void	fill_background(t_struct *cube)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (y < HEIGHT / 2)
				draw_pixel(cube, x, y, cube->color.sky);
			else
				draw_pixel(cube, x, y, cube->color.floor);
		}
	}
}

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
