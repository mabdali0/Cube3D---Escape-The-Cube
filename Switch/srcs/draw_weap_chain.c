/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_weap_chain.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../includes/chainsaw.h"

static void	pos_chainsaw_low(t_sprites *sp, t_draw *d, t_weapons *w)
{
	w->hand_w = 140;
	w->hand_h = 55;
	d->x = 500;
	d->y = 465 + 50;
	if (sp->states[29] == 1 || sp->states[29] == 3)
		d->y += 5;
	else if (sp->states[29] == 2)
		d->y += 10;
	else if (sp->states[29] == 5 || sp->states[29] == 7)
	{
		d->y -= 5;
		d->x += 5;
	}
	else if (sp->states[29] == 6)
		d->y -= 10;
	w->rhandy = d->y;
}

static void	draw_chainsaw_low(t_data *dt, t_sprites *sp,
	t_draw *d, t_weapons *w)
{
	pos_chainsaw_low(sp, d, w);
	w->i = -1;
	while (++w->i < w->hand_w)
	{
		w->j = -1;
		while (++w->j < w->hand_h)
		{
			d->w = w->i;
			d->h = w->j;
			w->pix = (w->i + w->hand_w * w->j) * 3;
			d->color = trgb(0, chainsaw[sp->states[28]][w->pix],
					chainsaw[sp->states[28]][w->pix + 1],
					chainsaw[sp->states[28]][w->pix + 2]);
			scale_pic(dt, d, 4);
		}
	}
}

static void	pos_chainsaw_high(t_sprites *sp, t_draw *d, t_weapons *w)
{
	d->x = 300;
	d->y = 253 + 50;
	w->hand_w = 153;
	w->hand_h = 89;
	if (sp->states[29] == 1 || sp->states[29] == 3)
	{
		d->y += 5;
		d->x -= 30;
	}
	else if (sp->states[29] == 2)
	{
		d->y += 10;
		d->x -= 15;
	}
	else if (sp->states[29] == 5 || sp->states[29] == 7)
	{
		d->y -= 5;
		d->x += 15;
	}
	else if (sp->states[29] == 6)
	{
		d->y -= 10;
		d->x += 30;
	}
	w->rhandy = d->y;
}

static void	draw_chainsaw_high(t_data *dt, t_sprites *sp,
	t_draw *d, t_weapons *w)
{
	pos_chainsaw_high(sp, d, w);
	w->i = -1;
	while (++w->i < w->hand_w)
	{
		w->j = -1;
		while (++w->j < w->hand_h)
		{
			d->w = w->i;
			d->h = w->j;
			w->pix = (w->i + w->hand_w * w->j) * 3;
			d->color = trgb(0, chainsaw[sp->states[28] + 2][w->pix],
					chainsaw[sp->states[28] + 2][w->pix + 1],
					chainsaw[sp->states[28] + 2][w->pix + 2]);
			scale_pic(dt, d, 4);
		}
	}
}

void	draw_chainsaw_main(t_data *dt)
{
	t_weapons	w;

	if (dt->player.attack == 0)
		draw_chainsaw_low(dt, &dt->sp, &dt->draw, &w);
	else
		draw_chainsaw_high(dt, &dt->sp, &dt->draw, &w);
}
