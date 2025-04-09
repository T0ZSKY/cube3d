/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 06:30:48 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/09 22:47:12 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

void	draw_pixel(t_struct *cube, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = cube->img_data + (y * cube->size_line + x * (cube->bpp / 8));
	*(unsigned int *)dst = color;
}

void draw_vertical_line(t_struct *cube, int x, int height, t_texture *texture)
{
    int start;
    int end;
    int y;
    int tex_x;  // Coordonnée x sur la texture
    int tex_y;  // Coordonnée y sur la texture
    unsigned int color;

    if (!texture || !texture->data) {
        fprintf(stderr, "Erreur : texture ou texture->data est nul.\n");
        return;
    }

    // Vérification des propriétés de la texture
    if (texture->width <= 0 || texture->height <= 0 || texture->size_line <= 0 || texture->bpp <= 0) {
        fprintf(stderr, "Erreur : propriétés de la texture invalides.\n");
        return;
    }

    start = (HEIGHT / 2) - (height / 2);
    end = (HEIGHT / 2) + (height / 2);
    y = start;
    if (start < 0)
        start = 0;
    if (end > HEIGHT)
        end = HEIGHT;

    // Calcul de la coordonnée x de la texture
    tex_x = (x * texture->width) / WIDTH;
    if (tex_x < 0) tex_x = 0;
    if (tex_x >= texture->width) tex_x = texture->width - 1;

    while (y < end)
    {
        // Calcul de la coordonnée y de la texture en fonction de la hauteur du mur
        tex_y = (y - start) * texture->height / height;
        if (tex_y < 0) tex_y = 0;
        if (tex_y >= texture->height) tex_y = texture->height - 1;

        // Récupérer la couleur de la texture
        color = *(unsigned int *)(texture->data + (tex_y * texture->size_line + tex_x * (texture->bpp / 8)));

        draw_pixel(cube, x, y, color);
        y++;
    }
}



static void	init_ray_data(t_player *p, int screen_x, double *rx, double *ry)
{
	double	camera_x;
	double	ray_angle;

	camera_x = 2 * screen_x / (double)WIDTH - 1;
	ray_angle = atan2(p->dir_y, p->dir_x) + camera_x * (M_PI / 4);
	*rx = cos(ray_angle);
	*ry = sin(ray_angle);
}

static int	wall_dist(t_player *p, t_struct *cube, double rx, double ry)
{
	double	pos_x;
	double	pos_y;
	double	raw_dist;
	double	cos_angle;
	double	corrected_dist;

	pos_x = p->x;
	pos_y = p->y;
	while (1)
	{
		pos_x += rx * 0.01;
		pos_y += ry * 0.01;
		if (cube->map[(int)pos_y][(int)pos_x] == '1')
		{
			raw_dist = get_distance(p->x, p->y, pos_x, pos_y);
			cos_angle = rx * p->dir_x + ry * p->dir_y;
			corrected_dist = raw_dist * cos_angle;
			return ((int)(HEIGHT / corrected_dist));
		}
	}
	return (0);
}

void	raycast_column(t_player *p, t_struct *cube, int screen_x, t_texture *texture)
{
	double	rx;
	double	ry;
	int		line_height;

	init_ray_data(p, screen_x, &rx, &ry);
	line_height = wall_dist(p, cube, rx, ry);
	draw_vertical_line(cube, screen_x, line_height, texture);
}
