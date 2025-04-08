/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:35:08 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/08 00:56:21 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/cube3d.h"

double	power2(double x)
{
	return (x * x);
}

double	get_distance(double x1, double y1, double x2, double y2)
{
	return (sqrt(power2(x2 - x1) + power2(y2 - y1)));
}
