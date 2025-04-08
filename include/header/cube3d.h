/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 06:59:07 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/09 00:26:55 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../GNL/get_next_line.h"
# include "../minilibx/mlx.h"
# include <math.h>

# define WIDTH 800
# define HEIGHT 600
# define FOV 0.60
# define ROT_SPEED 0.1

#define MINIMAP_SCALE 10
#define MINIMAP_RADIUS 120 // rayon de la minimap en pixels

#define MOVE_SPEED 0.1


# define KEY_ESC    65307
# define KEY_LEFT   65361
# define KEY_RIGHT  65363
# define KEY_TAB	65289

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100


typedef struct s_player
{
	double x;        // Position X du joueur
	double y;        // Position Y du joueur
	double dir_x;    // Direction X
	double dir_y;    // Direction Y
	double plane_x;  // Ajoute cette ligne
    double plane_y;  // Ajoute cette ligne
}	t_player;

typedef struct color
{
	unsigned int	floor;
	unsigned int	wall;
	unsigned int	 sky;
}	t_color;

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

	t_color	color;
	
	void	*img;
	char	*img_data;

	int		bpp;
	int		size_line;
	int		endian;


	int		full_screen;
}	t_struct;

typedef struct s_context
{
	t_player	*p;
	t_struct	*cube;
}	t_context;


void 			ft_error(char *str);
int 			verif_extension(char *str);
int 			open_file(char *str);
void 			ft_parsing(char *path, t_struct *cube);
void 			ft_print_map(t_struct *cube);
int 			ft_check_closed_map(t_struct *cube);
void 			ft_create_windows(t_struct *cube);
int 			ft_path_texture(t_struct *cube, char *path);
int 			ft_chech_assets(t_struct *cube);
void 			ft_remove_back_path(t_struct *cube);
void 			ft_set_max(t_struct *cube);
void			init_player(t_player *p, char **map);
void			raycast_column(t_player *p, t_struct *cube, int screen_x);
void			draw_vertical_line(t_struct *cube, int x, int height);
void			draw_pixel(t_struct *cube, int x, int y, unsigned int color);
int				handle_keypress(int keycode, void *param);
void			render_scene(t_player *bob, t_struct *cube);
void			rotate_player(t_player *p, int keycode);

/* maths.c */
double			power2(double x);
double			get_distance(double x1, double y1, double x2, double y2);

/* utils.c */
unsigned int	get_color(char *code);

void			draw_minimap(t_player *p, t_struct *cube);
void			draw_minimap_fullscreen(t_player *p, t_struct *cube);
void			fill_square(t_struct *cube, int start_x, int start_y, int size, int color);

#endif
