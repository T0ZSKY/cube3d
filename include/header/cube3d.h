/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 06:59:07 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/07 17:06:40 by tomlimon         ###   ########.fr       */
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
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

# define KEY_ESC    65307
# define KEY_LEFT   65361
# define KEY_RIGHT  65363


typedef struct s_player
{
	double x;        // Position X du joueur
	double y;        // Position Y du joueur
	double dir_x;    // Direction X
	double dir_y;    // Direction Y
	double plane_x;  // Ajoute cette ligne
    double plane_y;  // Ajoute cette ligne
}	t_player;

typedef struct s_struct
{
	char	**map;
	int		map_width;
	int		map_height;

	void	*mlx;
	void	*win;

	char	*path_N;
	char	*path_E;
	char	*path_W;
	char	*path_S;

	char	*color_F;
	char	*color_C;

}	t_struct;

typedef struct s_context
{
	t_player	*p;
	t_struct	*cube;
}	t_context;


void ft_error(char *str);
int verif_extension(char *str);
int open_file(char *str);
void ft_parsing(char *path, t_struct *cube);
void ft_print_map(t_struct *cube);
int ft_check_closed_map(t_struct *cube);
void ft_create_windows(t_struct *cube);
int ft_path_texture(t_struct *cube, char *path);
int ft_chech_assets(t_struct *cube);
void ft_remove_back_path(t_struct *cube);
void ft_set_max(t_struct *cube);
void	init_player(t_player *p, char **map);
void	raycast_column(t_player *p, t_struct *cube, int screen_x);
void	draw_vertical_line(void *mlx, void *win, int x, int height, int win_height);
int	handle_keypress(int keycode, void *param);
void	render_scene(t_player *bob, t_struct *cube);
void	rotate_player(t_player *p, int keycode);

#endif
