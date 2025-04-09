/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 03:12:18 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/09 03:12:33 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

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
		rotate_player(p, keycode);
	handle_movement(keycode, p, cube);
	if (keycode == KEY_TAB)
		cube->full_screen = !cube->full_screen;
	render_scene(p, cube);
	return (0);
}
