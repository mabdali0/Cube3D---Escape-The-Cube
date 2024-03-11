/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_calculs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	select_sprite_type(t_sprites *s, int id)
{
	if (s->type[id] == 2 || s->type[id] == 3)
	{
		s->textw = 150.0;
		s->texth = 150.0;
	}
	else if (s->type[id] == -2 || s->type[id] == -3)
	{
		s->textw = 161.0;
		s->texth = 76.0;
	}
	else
	{
		s->textw = s->w[id];
		s->texth = s->h[id];
	}
}

void	sets_init_values(t_data *dt, t_sprites *s, int id)
{
	s->sx = dt->sp.x[id] - dt->player.px;
	s->sy = dt->sp.y[id] - dt->player.py;
	s->sz = -6;
	s->cos = cos(dt->player.pa);
	s->sin = sin(dt->player.pa);
	s->a = s->sy * s->cos - s->sx * s->sin;
	s->b = s->sx * s->cos + s->sy * s->sin;
	s->sx = s->a;
	s->sy = s->b;
	s->sx = (s->sx * 1170.0 / s->sy) + (WIN_WIDTH / 2);
	s->sy = (-s->sz * 1170.0 / s->sy) + (dt->win_h / 2);
	s->scale = s->texth * s->sscale[id] / s->b;
	if (s->scale < 0)
		s->scale = 1;
	if (s->scale > 3000)
		s->scale = 3000;
	s->tx = 0.0;
	s->ty = s->texth;
	s->tx_step = s->textw / (float)s->scale;
	if (s->tx_step > 10)
		s->tx_step = 10;
	s->ty_step = s->texth / (float)s->scale;
	if (s->ty_step > 10)
		s->ty_step = 10;
}
