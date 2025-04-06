/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tom.limon@>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 06:58:33 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/06 21:36:13 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

//le joueur = bob

int	main(int argc, char **argv)
{
	t_struct	*cube;
	t_player	*bob;

	cube = malloc(sizeof(t_struct));
	bob = malloc(sizeof(t_player));
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
	simple_raycast(bob, cube->map);
	ft_create_windows(cube);
	if (!cube->mlx || !cube->win)
		return (ft_error("mlx ou window NULL\n"), 1);
	printf("MLX OK, WIN OK\n");
	draw_vertical_line(cube->mlx, cube->win, 800 / 2, 200, 600);
	mlx_loop(cube->mlx);
}
