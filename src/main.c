/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tom.limon@>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 06:58:33 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/11 01:33:40 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header/cube3d.h"

void	handle_movement_loop(t_struct *cube, t_player *p)
{
	double	speed;
	double	rot_speed;

	speed = SPEED;
	rot_speed = ROT_SPEED;
	if (cube->keys.w)
		move_player_in_direction(p, cube,
			p->dir_x * (speed), p->dir_y * speed);
	if (cube->keys.s)
		move_player_in_direction(p, cube,
			-p->dir_x * (speed * 0.5), -p->dir_y * speed);
	if (cube->keys.a)
		move_player_in_direction(p, cube,
			-p->plane_x * (speed * 0.5), -p->plane_y * speed);
	if (cube->keys.d)
		move_player_in_direction(p, cube,
			p->plane_x * (speed * 0.5), p->plane_y * speed);
	if (cube->keys.left)
		rotate_player(p, -rot_speed);
	if (cube->keys.right)
		rotate_player(p, rot_speed);
}

int	game_loop(t_context *ctx)
{
	handle_movement_loop(ctx->cube, ctx->p);
	render_scene(ctx->p, ctx->cube, ctx->texture);
	return (0);
}

int	main(int argc, char **argv)
{
	t_struct	*cube;
	t_player	*bob;
	t_context	*ctx;
	t_texture	*texture;

	cube = malloc(sizeof(t_struct));
	bob = malloc(sizeof(t_player));
	texture = malloc(sizeof(t_texture));
	ctx = malloc(sizeof(t_context));
	ctx->p = bob;
	ctx->cube = cube;
	ctx->texture = texture;
	cube->full_screen = 0;
	if (check_args(argc, argv))
		return (1);
	ft_parsing(argv[1], cube);
	if (check_map_and_assets(cube, argv[1]))
		return (1);
	ft_set_max(cube);
	if (initialize_player_and_window(bob, cube))
		return (1);
	ft_texture(texture, cube);
	render_scene(bob, cube, texture);
	mlx_hook(cube->win, 2, 1L << 0, key_press, ctx);
	mlx_hook(cube->win, 3, 1L << 1, key_release, ctx);
	mlx_loop_hook(cube->mlx, game_loop, ctx);
	mlx_loop(cube->mlx);
}
