/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tom.limon@>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:08:10 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/06 21:36:09 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

void	ft_create_windows(t_struct *cube)
{
	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, 800, 600, "Cube3D");
	printf("creation fenetre ok\n");
}
