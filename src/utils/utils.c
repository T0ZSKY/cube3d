/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tom.limon@>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:17:56 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/04 23:59:51 by tomlimon         ###   ########.fr       */
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
