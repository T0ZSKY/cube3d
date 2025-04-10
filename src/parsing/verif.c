/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 07:08:25 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/10 22:44:33 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

int	open_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (0);
}

int	verif_extension(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	if (str[i] == 'b')
	{
		i--;
		if (str[i] == 'u')
		{
			i--;
			if (str[i] == 'c')
			{
				i--;
				if (str[i] == '.')
					return (0);
			}
		}
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	if (argc != 2)
		return (ft_error("Error number argument incorrect\n"), 1);
	if (verif_extension(argv[1]) == 1)
		return (ft_error("Error map need to be in .ber\n"), 1);
	if (open_file(argv[1]) == -1)
		return (ft_error("file not found\n"), 1);
	return (0);
}

int	check_map_and_assets(t_struct *cube, char *map_path)
{
	if (ft_check_closed_map(cube) == 0)
		return (ft_error("map incorrect\n"), 1);
	ft_print_map(cube);
	if (ft_path_texture(cube, map_path) == 0)
		return (ft_error("error path assets missing\n"), 1);
	ft_remove_back_path(cube);
	if (ft_chech_assets(cube) == 0)
		return (ft_error("bad path assets\n"), 1);
	return (0);
}
