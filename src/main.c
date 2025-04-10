/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 06:58:33 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/10 21:34:35 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header/cube3d.h"

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

int	check_args(int argc, char **argv)
{
	if (argc != 2)
		return (ft_error("Error number argument incorrect\n"), 1);
	if (verif_extension(argv[1]) == 1)
		return (ft_error("Error map need to be in .ber\n"), 1);
	if (open_file(argv[1]) == -1)
		return (ft_error("file not found\n"), 1);
	return (0);
}

int	check_map_and_assets(t_struct *cube, char *map_path)
{
	if (ft_check_closed_map(cube) == 0)
		return (ft_error("map incorrect\n"), 1);
	ft_print_map(cube);
	if (ft_path_texture(cube, map_path) == 0)
		return (ft_error("error path assets missing\n"), 1);
	ft_remove_back_path(cube);
	if (ft_chech_assets(cube) == 0)
		return (ft_error("bad path assets\n"), 1);
	return (0);
}

int	initialize_player_and_window(t_player *bob, t_struct *cube)
{
	init_player(bob, cube->map);
	ft_create_windows(cube);
	if (!cube->mlx || !cube->win)
		return (ft_error("mlx ou window NULL\n"), 1);
	printf("MLX OK, WIN OK\n");
	return (0);
}

void	ft_texture_init(t_texture *texture, t_struct *cube, int *dim)
{
	texture->imgN = mlx_xpm_file_to_image(cube->mlx, cube->path_N, 
			&dim[0], &dim[1]);
	texture->imgE = mlx_xpm_file_to_image(cube->mlx, cube->path_E, 
			&dim[0], &dim[1]);
	texture->imgS = mlx_xpm_file_to_image(cube->mlx, cube->path_S, 
			&dim[0], &dim[1]);
	texture->imgW = mlx_xpm_file_to_image(cube->mlx, cube->path_W, 
			&dim[0], &dim[1]);
}

void	ft_texture(t_texture *texture, t_struct *cube)
{
	int	dim[2];

	dim[0] = 600;
	dim[1] = 600;
	ft_texture_init(texture, cube, dim);
	texture->data = mlx_get_data_addr(texture->imgN, &texture->bpp, 
			&texture->size_line, &texture->endian);
	if (!texture->data)
	{
		ft_error("Error retrieving texture data.\n");
		return ;
	}
	texture->width = dim[0];
	texture->height = dim[1];
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
	mlx_hook(cube->win, 2, 1L << 0, handle_keypress, ctx);
	mlx_loop(cube->mlx);
}
