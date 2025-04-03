/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tom.limon@>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:54:09 by tomlimon          #+#    #+#             */
/*   Updated: 2025/03/31 14:55:04 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

void ft_print_map(t_struct *cube)
{
	int i;

	i = 0;
	while (cube->map[i])
	{
		printf("contenue dans la matrice : %s", cube->map[i]);
		i++;
	}
}
