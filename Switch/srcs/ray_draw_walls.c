/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_draw_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../includes/texture_draw_wall.h"

void	draw_wall_wall_size(t_data *dt, t_draw *d, t_raycast *rc)
{
	float	w_correction;

	w_correction = 6600.0;
	rc->ca = (dt->player.pa - rc->ra);
	if (rc->ca < 0)
		rc->ca += 2 * PI;
	if (rc-> ca > 2 * PI)
		rc->ca -= 2 * PI;
	rc->dist = rc->dist * cos(rc->ca);
	d->startx = (WIN_WIDTH / rc->rmax) * rc->r + 0;
	if (d->startx < 1)
		d->startx = 1;
	d->endx = d->startx;
	d->starty = dt->win_h / 2.0 - w_correction / rc->dist;
	d->endy = dt->win_h / 2.0 + w_correction / rc->dist;
	rc->lineh = d->endy - d->starty - 1;
	if (d->starty < 1)
		d->starty = 1;
	else if (d->starty > dt->win_h)
		d->starty = dt->win_h;
	if (d->endy < 1)
		d->endy = 1;
	else if (d->endy > dt->win_h)
		d->endy = dt->win_h;
	d->color = dt->wall_color;
}

void	calc_walls(t_data *dt, t_raycast *rc)
{
	float	ty_offset;

	rc->ty_step = 256.0 / (float)rc->lineh;
	ty_offset = 0;
	if (rc->lineh > dt->win_h)
		ty_offset = (rc->lineh - dt->win_h) / 2.0;
	rc->depth[rc->r] = rc->dist;
	rc->ty = ty_offset * rc->ty_step;
	if (rc->worient == 0)
	{
		rc->tx = (int)(rc->rx * 256.0 / dt->mima.sizebox) % 256;
		if (rc->ra > PI)
			rc->tx = 255 - rc->tx;
	}
	else
	{
		rc->tx = (int)(rc->ry * 256.0 / dt->mima.sizebox) % 256;
		if (rc->ra > P2 && rc->ra < P3)
			rc->tx = 255 - rc->tx;
	}
}

void	draw_floor_ceil(t_data *dt, t_draw *d, t_raycast *rc, int y)
{
	float	dy;
	int		pix;
	float	cor_const;

	while (y < dt->win_h)
	{
		dy = (y - (dt->win_h / 2.0));
		cor_const = 32 / dy / rc->rafix;
		rc->tx = dt->player.px * 4.7 + cos(rc->deg) * 990 * cor_const + 3;
		rc->ty = -dt->player.py * 4.7 - sin(rc->deg) * 990 * cor_const - 2;
		pix = ((int)(rc->ty) & 255) * 256 + ((int)(rc->tx) & 255);
		d->color = ft_add_shade(trgb(0, texture_floor[rc->night][pix * 3],
					texture_floor[rc->night][pix * 3 + 1],
					texture_floor[rc->night][pix * 3 + 2]), floor_shade(dt, y));
		ft_put_pixel_res(&dt->img, d->startx, y, d->color);
		rc->tx = dt->player.px / 10 + cos(rc->deg) * 200 * cor_const + 3;
		rc->ty = -dt->player.py / 10 - sin(rc->deg) * 200 * cor_const - 2;
		pix = ((int)(rc->ty) & 31) * 32 + ((int)(rc->tx) & 31);
		d->color = trgb(0, texture_sky[rc->night][pix * 3],
				texture_sky[rc->night][pix * 3 + 1],
				texture_sky[rc->night][pix * 3 + 2]);
		ft_put_pixel_res(&dt->img, d->startx, dt->win_h - y, d->color);
		y += 1;
	}
}

void	draw_wall(t_data *dt, t_draw *d, t_raycast *rc)
{
	int	y;

	dt->tx.walls[4] = texture_door;
	dt->tx.walls[5] = hedge_purple[0];
	dt->tx.walls[6] = hedge_purple[1];
	dt->tx.walls[7] = hedge_purple[2];
	dt->tx.walls[8] = hedge_purple[3];
	dt->tx.walls[9] = door_purple;
	draw_wall_wall_size(dt, d, rc);
	calc_walls(dt, rc);
	put_wall_text(dt, rc, d);
	d->shade = 50;
	rc->deg = rc->ra;
	rc->rafix = cos(deg_to_rad(fixang(rad_to_deg(dt->player.pa - rc->ra))));
	y = d->starty + rc->lineh;
	draw_floor_ceil(dt, d, rc, y);
}

//rc->tx correction without downscale : 2.12
//cor_const * 434
