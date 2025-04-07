/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:08:10 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/07 17:04:13 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

#define ROT_SPEED 0.05

void	ft_create_windows(t_struct *cube)
{
	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, 800, 600, "Cube3D");
	printf("creation fenetre ok\n");
}

int	handle_keypress(int keycode, void *param)
{
	t_context	*ctx;
	t_player	*p;
	t_struct	*cube;

	ctx = (t_context *)param;
	p = ctx->p;
	cube = ctx->cube;

	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		rotate_player(p, keycode); // suppose que t’as une fonction pour tourner
	render_scene(p, cube);
	return (0);
}
