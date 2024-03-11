/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	floor_shade(t_data *dt, int y)
{
	int	shade;

	if (dt->rays.night == 0)
		return (100);
	shade = (y - (dt->win_h / 2 + 20)) / 4;
	if (shade < 0)
		shade = 0;
	if (shade > 100)
		shade = 100;
	return (shade);
}

float	deg_to_rad(float deg)
{
	return (deg * PI / 180);
}

float	rad_to_deg(float rad)
{
	return (rad * 180 / PI);
}

float	fixang(float a)
{
	if (a > 359)
		a -= 360;
	if (a < 0)
		a += 360;
	return (a);
}

float	dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}
