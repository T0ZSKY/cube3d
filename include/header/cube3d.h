/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 06:59:07 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/04 16:10:45 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
#define CUBE3D_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../GNL/get_next_line.h"
#include "../minilibx/mlx.h"

typedef struct s_struct
{
	char **map;
	void    *mlx;
	void    *win;
	
	char	*path_N;
	char	*path_E;
	char	*path_W;
	char	*path_S;
}	t_struct;

void ft_error(char *str);
int verif_extension(char *str);
int open_file(char *str);
void ft_parsing(char *path, t_struct *cube);
void ft_print_map(t_struct *cube);
int ft_check_closed_map(t_struct *cube);
void ft_create_windows(t_struct *cube);
int ft_path_texture(t_struct *cube, char *path);

#endif
