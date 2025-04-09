/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 06:30:48 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/09 23:36:00 by tomlimon         ###   ########.fr       */
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

void draw_vertical_line(t_struct *cube, int x, int height, t_texture *texture, double wall_x)
{
    int start;
    int end;
    int y;
    int tex_x;
    int tex_y;
    unsigned int color;

    start = (HEIGHT / 2) - (height / 2);
    end = (HEIGHT / 2) + (height / 2);
    y = start;

    if (start < 0)
        start = 0;
    if (end > HEIGHT)
        end = HEIGHT;

    tex_x = (int)(wall_x * (double)texture->width);
    if (tex_x < 0) tex_x = 0;
    if (tex_x >= texture->width) tex_x = texture->width - 1;

    while (y < end)
    {
        tex_y = ((y - start) * texture->height) / height;
        if (tex_y < 0) tex_y = 0;
        if (tex_y >= texture->height) tex_y = texture->height - 1;

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

static int wall_dist(t_player *p, t_struct *cube, double rx, double ry, double *wall_x)
{
    double pos_x = p->x;
    double pos_y = p->y;
    double side_dist_x, side_dist_y;
    double delta_dist_x = fabs(1 / rx);
    double delta_dist_y = fabs(1 / ry);
    int map_x = (int)pos_x;
    int map_y = (int)pos_y;
    double perp_wall_dist;
    int step_x, step_y;
    int hit = 0;
    int side;

    if (rx < 0) {
        step_x = -1;
        side_dist_x = (pos_x - map_x) * delta_dist_x;
    } else {
        step_x = 1;
        side_dist_x = (map_x + 1.0 - pos_x) * delta_dist_x;
    }
    if (ry < 0) {
        step_y = -1;
        side_dist_y = (pos_y - map_y) * delta_dist_y;
    } else {
        step_y = 1;
        side_dist_y = (map_y + 1.0 - pos_y) * delta_dist_y;
    }

    while (hit == 0) {
        if (side_dist_x < side_dist_y) {
            side_dist_x += delta_dist_x;
            map_x += step_x;
            side = 0;
        } else {
            side_dist_y += delta_dist_y;
            map_y += step_y;
            side = 1;
        }
        if (cube->map[map_y][map_x] == '1') hit = 1;
    }

    if (side == 0) {
        perp_wall_dist = (map_x - pos_x + (1 - step_x) / 2) / rx;
        *wall_x = pos_y + perp_wall_dist * ry;
    } else {
        perp_wall_dist = (map_y - pos_y + (1 - step_y) / 2) / ry;
        *wall_x = pos_x + perp_wall_dist * rx;
    }
    *wall_x -= floor(*wall_x);

    return ((int)(HEIGHT / perp_wall_dist));
}

void raycast_column(t_player *p, t_struct *cube, int screen_x, t_texture *texture)
{
    double rx;
    double ry;
    int line_height;
    double wall_x; // Position exacte où le rayon a touché le mur

    init_ray_data(p, screen_x, &rx, &ry);
    line_height = wall_dist(p, cube, rx, ry, &wall_x); // Modifier wall_dist pour retourner wall_x
    draw_vertical_line(cube, screen_x, line_height, texture, wall_x);
}
