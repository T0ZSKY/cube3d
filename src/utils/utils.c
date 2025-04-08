/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:17:56 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/09 00:01:20 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

void	ft_remove_back_path(t_struct *cube)
{
	char	*path;
	int		len;

	path = cube->path_N;
	if (path)
	{
		len = ft_strlen(path);
		if (len > 0 && path[len - 1] == '\n')
			path[len - 1] = '\0';
	}
	path = cube->path_S;
	if (path)
	{
		len = ft_strlen(path);
		if (len > 0 && path[len - 1] == '\n')
			path[len - 1] = '\0';
	}
	path = cube->path_E;
	if (path)
	{
		len = ft_strlen(path);
		if (len > 0 && path[len - 1] == '\n')
			path[len - 1] = '\0';
	}
	path = cube->path_W;
	if (path)
	{
		len = ft_strlen(path);
		if (len > 0 && path[len - 1] == '\n')
			path[len - 1] = '\0';
	}
}

void	ft_set_max(t_struct *cube)
{
	int		i;
	size_t	max;

	i = 0;
	max = 0;
	while (cube->map[i])
	{
		if (max < ft_strlen(cube->map[i]))
			max = ft_strlen(cube->map[i]);
		i++;
	}
	cube->map_width = (int)max;
}

unsigned int	get_color(char *code)
{
	unsigned int	i;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	i = 0;
	r = 0;
	g = 0;
	b = 0;
	while (code[i] == ' ')
		i++;
	while (code[i] && code[i] != ',')
		r = r * 10 + (code[i++] - '0');
	i++;
	while (code[i] && code[i] != ',')
		g = g * 10 + (code[i++] - '0');
	i++;
	while (code[i] && code[i] != '\n' && code[i] != '\0')
		b = b * 10 + (code[i++] - '0');
	return ((0x37 << 24) | (r << 16) | (g << 8) | b);
}
