/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tom.limon@>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 07:08:25 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/05 00:23:06 by tomlimon         ###   ########.fr       */
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
