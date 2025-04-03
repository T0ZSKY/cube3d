/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tom.limon@>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 06:58:33 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/01 15:20:19 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

int main(int argc, char **argv)
{
	t_struct *cube;

	(void)argv;
	cube = malloc(sizeof(cube));
	if (argc != 2)
		return (ft_error("Error number argument incorrect\n"), 1);
	if (verif_extension(argv[1]) == 1)
		return (ft_error("Error map need to be in .ber\n"), 1);
	if (open_file(argv[1]) == -1)
		return (ft_error("file not found\n"), 1);
	ft_parsing(argv[1], cube);
	if (ft_check_closed_map(cube) == 0)
		return (ft_error("map incorrect\n"), 1);
	ft_create_windows(cube);
	//init la fenetre
}
