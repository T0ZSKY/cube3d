/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:08:10 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/08 16:24:49 by tomlimon         ###   ########.fr       */
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

	ctx = (t_context *)param;
	p = ctx->p;
	cube = ctx->cube;
	printf("\nkey code : %d\n", keycode);
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		rotate_player(p, keycode);
	if (keycode == KEY_TAB)
		cube->full_screen = !cube->full_screen;
	render_scene(p, cube);
	return (0);
}
