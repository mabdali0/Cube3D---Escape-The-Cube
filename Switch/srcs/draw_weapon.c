/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_weapon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../includes/weapons.h"

static void	calc_pos_hands(t_sprites *sp, t_draw *d, t_weapons *w)
{
	w->hand_w = 113;
	w->hand_h = 42;
	d->y = 495 + 50;
	if (sp->states[29] == 1 || sp->states[29] == 3)
		d->y += 10;
	else if (sp->states[29] == 2)
		d->y += 20;
	else if (sp->states[29] == 5 || sp->states[29] == 7)
		d->y -= 10;
	else if (sp->states[29] == 6)
		d->y -= 20;
	w->lhandy = d->y;
	w->rhandy = (495 + 50) + ((495 + 50) - w->lhandy);
}

static void	draw_hands(t_data *dt, t_sprites *sp, t_draw *d, t_weapons *w)
{
	calc_pos_hands(sp, d, w);
	w->i = -1;
	while (++w->i < w->hand_w)
	{
		w->j = -1;
		while (++w->j < w->hand_h)
		{
			d->w = w->i;
			d->h = w->j;
			d->x = 840;
			d->y = w->rhandy;
			w->pix = (w->i + w->hand_w * w->j) * 3;
			d->color = trgb(0, hand_text[w->pix], hand_text[w->pix + 1],
					hand_text[w->pix + 2]);
			scale_pic(dt, d, 3);
			d->x = 100;
			d->y = w->lhandy;
			w->pix = (w->hand_w - 1 - w->i + w->hand_w * w->j) * 3;
			d->color = trgb(0, hand_text[w->pix], hand_text[w->pix + 1],
					hand_text[w->pix + 2]);
			scale_pic(dt, d, 3);
		}
	}
}

void	draw_weapon(t_data *dt, t_sprites *sp, t_draw *d)
{
	t_weapons	w;

	is_player_moving(dt);
	if (dt->player.cur_weapon == 0)
		draw_hands(dt, sp, d, &w);
	else
		draw_chainsaw_main(dt);
}
