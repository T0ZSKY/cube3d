/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:32:22 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/10 22:44:27 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

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
