/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_draw_walls2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static void	each_line(t_data *dt, t_raycast *rc, int y, int shade)
{
	int	pix;

	pix = ((int)(rc->ty) * 256.0 + (int)(rc->tx)) * 3.0;
	if (pix >= 0 && pix < 196608)
	{
		dt->draw.color = ft_add_shade(trgb(0, dt->tx.walls[rc->wtype - 1][pix],
					dt->tx.walls[rc->wtype - 1][pix + 1],
					dt->tx.walls[rc->wtype - 1][pix + 2]), shade);
		ft_put_pixel_res(&dt->img, dt->draw.startx, y
			+ dt->draw.starty, dt->draw.color);
	}
}

void	put_wall_text(t_data *dt, t_raycast *rc, t_draw *d)
{
	int	y;
	int	shade;

	shade = 80;
	if (rc->night)
		shade = 70 - rc->dist * 0.9;
	if (shade < 0)
		shade = 0;
	if (rc->wtype < 0)
		return ;
	if (rc->night)
		rc->wtype += 5;
	if (rc->lineh + d->starty > dt->win_h)
		rc->lineh = dt->win_h - d->starty;
	y = -1;
	while (++y < rc->lineh)
	{
		each_line(dt, rc, y, shade);
		rc->ty += rc->ty_step;
	}
}
