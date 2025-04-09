/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 03:12:18 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/09 22:45:41 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

int handle_keypress(int keycode, void *param)
{
    t_context *ctx;
    t_player *p;
    t_struct *cube;
    t_texture *texture;  // Déclarez un pointeur vers la texture

    ctx = (t_context *)param;
    p = ctx->p;
    cube = ctx->cube;
    texture = ctx->texture;  // Récupère la texture depuis ctx

    if (keycode == KEY_ESC)
        exit(0);
    if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
        rotate_player(p, keycode);

    if (keycode == 65505)
    {
        if (p->is_running == 0)
        {
            p->is_running = 1;
            p->speed = p->run_speed;
        }
        else
        {
            p->is_running = 0;
            p->speed = 1;
        }
    }
    handle_movement(keycode, p, cube);
    
    if (keycode == KEY_TAB)
        cube->full_screen = !cube->full_screen;

    // Appel de render_scene avec la texture récupérée depuis ctx
    render_scene(p, cube, texture);

    return (0);
}

