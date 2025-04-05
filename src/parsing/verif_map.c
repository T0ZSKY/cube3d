/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tom.limon@>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:08:38 by tomlimon          #+#    #+#             */
/*   Updated: 2025/04/05 00:21:51 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

int	ft_check_top_border(t_struct *cube)
{
	int	i;

	i = 0;
	while (cube->map[0][i] && cube->map[0][i] != '\n')
	{
		if (cube->map[0][i] != '1' && cube->map[0][i] != ' ')
			return (ft_error("Error: map not closed (top)"), 0);
		i++;
	}
	return (1);
}

int	ft_check_bottom_border(t_struct *cube, int i)
{
	int	j;

	j = 0;
	while (cube->map[i][j] && cube->map[i][j] != '\n')
	{
		if (cube->map[i][j] != '1' && cube->map[i][j] != ' ')
			return (ft_error("Error: map not closed (bottom)"), 0);
		j++;
	}
	return (1);
}

int	ft_check_side_borders(t_struct *cube, int i)
{
	int	len;

	len = ft_strlen(cube->map[i]);
	if (len > 0 && cube->map[i][len - 1] == '\n')
		len--;
	if (cube->map[i][0] != '1' && cube->map[i][0] != ' ')
		return (ft_error("Error: map not closed (left border)"), 0);
	if (len > 0 && cube->map[i][len - 1] != '1' && cube->map[i][len - 1] != ' ')
		return (ft_error("Error: map not closed (right border)"), 0);
	return (1);
}

int	ft_check_open_spaces(t_struct *cube, int i, int j)
{
	int	above_len;
	int	below_len;

	if (!cube->map[i - 1] || !cube->map[i + 1])
		return (ft_error("Error: map open (missing line above/below)"), 0);
	above_len = ft_strlen(cube->map[i - 1]);
	if (above_len > 0 && cube->map[i - 1][above_len - 1] == '\n')
		above_len--;
	if (j >= above_len || cube->map[i - 1][j] == ' ' || cube->map[i - 1][j] == '\0')
		return (ft_error("Error: map has an open space (top)"), 0);
	below_len = ft_strlen(cube->map[i + 1]);
	if (below_len > 0 && cube->map[i + 1][below_len - 1] == '\n')
		below_len--;
	if (j >= below_len || cube->map[i + 1][j] == ' ' || cube->map[i + 1][j] == '\0')
		return (ft_error("Error: map has an open space (bottom)"), 0);
	if (j > 0 && cube->map[i][j - 1] == ' ')
		return (ft_error("Error: map has an open space (left)"), 0);
	if (cube->map[i][j + 1] == ' ' || cube->map[i][j + 1] == '\n' || cube->map[i][j + 1] == '\0')
		return (ft_error("Error: map has an open space (right)"), 0);
	return (1);
}

int	ft_check_closed_map(t_struct *cube)
{
	int	i;
	int	j;

	i = 1;
	if (!ft_check_top_border(cube))
		return (0);
	while (cube->map[i + 1])
	{
		if (!ft_check_side_borders(cube, i))
			return (0);
		j = 1;
		while (cube->map[i][j] && cube->map[i][j] != '\n')
		{
			if (cube->map[i][j] == '0' && !ft_check_open_spaces(cube, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (ft_check_bottom_border(cube, i));
}
