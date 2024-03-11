/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	find_shorter_ray(t_data *dt, t_raycast *rc)
{
	rc->wtype = 0;
	rc->worient = 0;
	if (rc->disth < rc->distv)
	{
		rc->rx = rc->hx;
		rc->ry = rc->hy;
		rc->dist = rc->disth;
		dt->draw.shade = 65;
		rc->wtype = rc->wtypeh;
		rc->worient = 0;
	}
	else
	{
		rc->rx = rc->vx;
		rc->ry = rc->vy;
		rc->dist = rc->distv;
		dt->draw.shade = 100;
		rc->wtype = rc->wtypev;
		rc->worient = 1;
	}
	dt->draw.endx = rc->rx;
	dt->draw.endy = rc->ry;
}

void	pick_color(t_draw *d, int c)
{
	if (c == 0)
		d->color = ft_add_shade(trgb(0, 0, 0, 0), d->shade);
	else if (c == 1)
		d->color = ft_add_shade(trgb(0, 255, 255, 255), d->shade);
	else if (c == 2)
		d->color = ft_add_shade(trgb(0, 255, 0, 0), d->shade);
	else
		d->color = ft_add_shade(trgb(0, 0, 0, 255), d->shade);
}

static void	init_rays(t_data *dt, t_raycast *rc)
{
	rc->r = -1;
	rc->rmax = RAYS;
	rc->dr = deg_to_rad(60.0 / rc->rmax);
	rc->ra = dt->player.pa - rc->dr * rc->rmax / 2;
	rc->xo = 0;
	rc->yo = 0;
	rc->rx = 0;
	rc->ry = 0;
}

void	draw_rays(t_data *dt)
{
	t_raycast	*rc;

	rc = &dt->rays;
	init_rays(dt, rc);
	while (++rc->r < rc->rmax)
	{
		if (rc->ra < 0)
			rc->ra += 2 * PI;
		else if (rc->ra > 2 * PI)
			rc->ra -= 2 * PI;
		dt->draw.startx = dt->player.px;
		dt->draw.starty = dt->player.py;
		horizontal_lines(dt, &dt->rays, &dt->player);
		vertical_lines(dt, &dt->rays, &dt->player);
		find_shorter_ray(dt, rc);
		draw_wall(dt, &dt->draw, rc);
		rc->ra += rc->dr;
	}
}
