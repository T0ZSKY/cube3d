/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 06:58:33 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/07 17:09:30 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

//le joueur = bob
void	render_scene(t_player *bob, t_struct *cube)
{
	int	x;

	x = 0;
	mlx_clear_window(cube->mlx, cube->win);
	while (x < WIDTH)
	{
		raycast_column(bob, cube, x);
		x++;
	}
}

int	main(int argc, char **argv)
{
	t_struct	*cube;
	t_player	*bob;
	t_context *ctx;

	cube = malloc(sizeof(t_struct));
	bob = malloc(sizeof(t_player));
	ctx = malloc(sizeof(t_context));
	ctx->p = bob;
	ctx->cube = cube;
	
	if (argc != 2)
		return (ft_error("Error number argument incorrect\n"), 1);
	if (verif_extension(argv[1]) == 1)
		return (ft_error("Error map need to be in .ber\n"), 1);
	if (open_file(argv[1]) == -1)
		return (ft_error("file not found\n"), 1);
	ft_parsing(argv[1], cube);
	if (ft_check_closed_map(cube) == 0)
		return (ft_error("map incorrect\n"), 1);
	ft_print_map(cube);
	if (ft_path_texture(cube, argv[1]) == 0)
		return (ft_error("error path assets missing\n"), 1);
	ft_remove_back_path(cube);
	if (ft_chech_assets(cube) == 0)
		return (ft_error("bad path assets\n"), 1);
	ft_set_max(cube);
	printf("\nhauteur de la map : %d\n", cube->map_height);
	printf("\nlargeur de la map : %d\n", cube->map_width);
	init_player(bob, cube->map);
	ft_create_windows(cube);
	if (!cube->mlx || !cube->win)
		return (ft_error("mlx ou window NULL\n"), 1);
	printf("MLX OK, WIN OK\n");

	render_scene(bob, cube);
	mlx_hook(cube->win, 2, 1L << 0, handle_keypress, ctx);
	mlx_loop(cube->mlx);
}
