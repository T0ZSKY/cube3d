/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 06:59:07 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/11 00:01:03 by tomlimon         ###   ########.fr       */
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

# define WIDTH 1280
# define HEIGHT 720
# define FOV 0.86 
# define ROT_SPEED 0.04
# define SPEED 0.5

#define MINIMAP_SCALE 10
#define MINIMAP_RADIUS 120 // rayon de la minimap en pixels


# define KEY_ESC    65307
# define KEY_LEFT   65361
# define KEY_RIGHT  65363
# define KEY_TAB	65289

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keys;

typedef struct s_minimap
{
    int color;
    int tile_size;
    int start_x;
    int start_y;
} t_minimap;

typedef struct s_player
{
    double x;          // Position X du joueur
    double y;          // Position Y du joueur
    double dir_x;      // Direction X
    double dir_y;      // Direction Y
    double plane_x;    // Plan X
    double speed;      // Vitesse normale
    double run_speed;  // Vitesse en mode course
    int is_running;    // Indicateur de mode course
    double plane_y;    // Plan Y
} t_player;

typedef struct s_color
{
    unsigned int floor;
    unsigned int wall;
    unsigned int sky;
} t_color;

typedef struct s_texture
{
    void    *imgN;
    void    *imgS;
    void    *imgE;
    void    *imgW;
    char    *data;
    int     width;
    int     height;
    int     bpp;
    int     size_line;
    int     endian;
} t_texture;

typedef struct s_struct
{
    char    **map;
    int     map_width;
    int     map_height;
    void    *mlx;
    void    *win;
    char    *path_N;
    char    *path_E;
    char    *path_W;
    char    *path_S;
	t_keys	keys;
    t_color color;
    void    *img;
    char    *img_data;
    int     bpp;
    int     size_line;
    int     endian;
    int     full_screen;
} t_struct;

typedef struct s_context
{
    t_player *p;
    t_struct *cube;
    t_texture *texture;
} t_context;

/* Structure pour les calculs de raycasting */
typedef struct s_ray_calc
{
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	double	perp_wall_dist;
	double	wall_x;
}	t_ray_calc;

/* Structure pour les données du rayon à dessiner */
typedef struct s_ray_data
{
	t_texture	*texture;
	double		wall_x;
	int			tex_y;
}	t_ray_data;

/* Structure pour les paramètres de texture */
typedef struct s_tex_params
{
	int			y;
	int			start;
	int			height;
	t_texture	*texture;
	int			*tex_y;
}	t_tex_params;

/* Structure pour les paramètres de raycasting */
typedef struct s_raycast_params
{
	t_player	*p;
	t_struct	*cube;
	double		rx;
	double		ry;
	double		*wall_x;
}	t_raycast_params;

/* Structure pour les données de ligne verticale */
typedef struct s_line_data
{
	int			start;
	int			end;
	int			y;
	int			height;
	int			tex_x;
	t_ray_data	*ray;
}	t_line_data;

/* Structure pour la direction du rayon */
typedef struct s_ray_dir
{
	double	rx;
	double	ry;
}	t_ray_dir;

/* main.c */
void	fill_background(t_struct *cube);

/* maths.c */
double			power2(double x);
double			get_distance(double x1, double y1, double x2, double y2);

/* utils.c */
unsigned int	get_color(char *code);
void 			ft_set_max(t_struct *cube);
void 			ft_remove_back_path(t_struct *cube);
void			fill_square(t_struct *cube, int start_x, int start_y, int size, int color);

/* error.c */
void 			ft_error(char *str);

/* debug.c */
void 			ft_print_map(t_struct *cube);

/* verif.c */
int 			verif_extension(char *str);
int 			open_file(char *str);
int				check_args(int argc, char **argv);
int				check_map_and_assets(t_struct *cube, char *map_path);

/* verif_map.c */
int 			ft_check_closed_map(t_struct *cube);

/* parsing.c */
void 			ft_parsing(char *path, t_struct *cube);
int 			ft_path_texture(t_struct *cube, char *path);
int 			ft_chech_assets(t_struct *cube);

/* windows.c */
void 			ft_create_windows(t_struct *cube);
int				handle_keypress(int keycode, void *param);
void	render_scene(t_player *bob, t_struct *cube, t_texture *texture);
int				handle_movement(int keycode, t_player *p, t_struct *cube);
int		move_player_in_direction(t_player *p, t_struct *cube, double dir_x, double dir_y);

/* mini_map.c */
void			draw_minimap(t_player *p, t_struct *cube);
void			draw_minimap_fullscreen(t_player *p, t_struct *cube);
void			draw_player(t_player *p, t_struct *cube, int tile_size);
int	get_minimap_color(t_player *p, t_struct *cube, double rotated_x, double rotated_y);
void	draw_minimap_tile(t_player *p, t_struct *cube, double angle, int x, int y);
void	draw_player_on_minimap(t_struct *cube);

/* init_player.c */
int         init_player(t_player *p, char **map);
int			initialize_player_and_window(t_player *bob, t_struct *cube);

/* raycasting.c */
void	draw_pixel(t_struct *cube, int x, int y, unsigned int color);
void	set_tex_x(int *tex_x, double wall_x, t_texture *texture);
void	set_tex_y_params(t_tex_params *params);
void	draw_v_line_part1(t_line_data *data);
void	raycast_column(t_player *p, t_struct *cube, int screen_x, t_texture *texture);

/* raycasting2.c */
void	draw_v_line(t_struct *cube, int x, int height, t_ray_data *ray);
void	init_step_x(t_ray_calc *calc, t_player *p, double rx);
void	init_step_y(t_ray_calc *calc, t_player *p, double ry);
void	set_step_and_side_dist(t_ray_calc *calc, t_player *p, t_ray_dir *dir);

/* raycasting3.c */
void	perform_dda_part1(t_ray_calc *calc);
void	perform_dda(t_ray_calc *calc, t_struct *cube);
void	calculate_wall_dist(t_ray_calc *calc, t_player *p, t_ray_dir *dir);
int		wall_dist(t_raycast_params *params);
void	init_ray_data(t_player *p, int screen_x, double *rx, double *ry);

/* player_move.c */
int		key_press(int keycode, t_context *ctx);
int		key_release(int keycode, t_context *ctx);
void	rotate_player(t_player *p, double angle);
int		move_player(t_player *p, t_struct *cube, double new_x, double new_y);
int		move_player_in_direction(t_player *p, t_struct *cube, double dir_x, double dir_y);

/* textures.c */
void	ft_texture(t_texture *texture, t_struct *cube);

#endif
