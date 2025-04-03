/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tom.limon@>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:08:10 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/03 06:27:28 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

void ft_create_windows(t_struct *cube)
{

	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, 800, 600, "Cube3D");
	mlx_loop(cube->mlx);
	printf("creation fenetre ok\n");
}
