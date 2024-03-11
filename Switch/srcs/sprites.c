/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../includes/sprites.h"

void	select_text_type2(t_sprites *s, t_draw *d, int id)
{
	if (s->type[id] == 4)
		d->color = trgb(0, chainsaw_item[s->pix * 3],
				chainsaw_item[s->pix * 3 + 1],
				chainsaw_item[s->pix * 3 + 2]);
	else if (s->type[id] == 5)
	{
		d->color = trgb(0, key[s->pix * 3],
				key[s->pix * 3 + 1],
				key[s->pix * 3 + 2]);
	}
	else if (s->type[id] == 6)
		d->color = trgb(0, firstkit[s->pix * 3],
				firstkit[s->pix * 3 + 1],
				firstkit[s->pix * 3 + 2]);
	else if (s->type[id] == 7)
		d->color = trgb(0, jerrican[s->pix * 3],
				jerrican[s->pix * 3 + 1],
				jerrican[s->pix * 3 + 2]);
	else if (s->type[id] == 9)
	{
		d->color = trgb(0, exitdoor[s->pix * 3],
				exitdoor[s->pix * 3 + 1],
				exitdoor[s->pix * 3 + 2]);
	}
}

void	select_text_type(t_sprites *s, t_draw *d, int id)
{
	int	pic;

	pic = s->states[id];
	if (s->type[id] == 1)
		d->color = trgb(0, kitty[s->states[id]][s->pix * 3],
				kitty[s->states[id]][s->pix * 3 + 1],
				kitty[s->states[id]][s->pix * 3 + 2]);
	else if (s->type[id] == 2 || s->type[id] == 3)
	{
		if (s->damaged[id] && !(s->states[id] == 1 || s->states[id] == 3))
			pic = 6;
		if (s->damaged[id] && (s->states[id] == 1 || s->states[id] == 3))
			s->damaged[id] = 0;
		d->color = trgb(0, ennemy[pic][s->pix * 3],
				ennemy[pic][s->pix * 3 + 1],
				ennemy[pic][s->pix * 3 + 2]);
	}
	else if (s->type[id] == -2 || s->type[id] == -3)
		d->color = trgb(0, ennemy_dead[s->pix * 3],
				ennemy_dead[s->pix * 3 + 1],
				ennemy_dead[s->pix * 3 + 2]);
	else
		select_text_type2(s, d, id);
}

void	draw_each(t_data *dt, t_sprites *s, t_draw *d, int id)
{
	if (s->px > 0 && s->px < WIN_WIDTH - DOWNSCALE && s->b
		< dt->rays.depth[(int)(s->px / DOWNSCALE)])
	{
		s->py = 0;
		while (s->py < s->scale && s->ty >= 0)
		{
			if (s->sy - s->py > 0 && s->sy - s->py < dt->win_h - DOWNSCALE)
			{
				s->pix = ((int)(s->ty) % ((int)s->texth)) * s->textw
					+ ((int)(s->tx) % ((int)s->textw));
				select_text_type(s, d, id);
				if (d->color != 0x00FF00FF)
				{
					if (dt->game_step > 1)
						d->color = ft_add_shade(d->color,
								100 - dist(dt->player.px,
									dt->player.py, s->x[id], s->y[id]) * 0.8);
					ft_put_pixel_res(&dt->img, s->px, s->sy - s->py, d->color);
				}
			}
			s->ty -= s->ty_step;
			s->py++;
		}
	}
}

void	draw_sprites(t_data *dt, t_sprites *s, t_draw *d)
{
	int	i;

	order_sprites(dt, s);
	i = -1;
	while (s->order[++i] >= 0)
	{
		if (s->type[s->order[i]] != 0)
		{
			select_sprite_type(s, s->order[i]);
			sets_init_values(dt, s, s->order[i]);
			s->px = s->sx - s->scale / 2;
			while (s->px < s->sx + s->scale / 2)
			{
				s->ty = s->texth;
				draw_each(dt, s, d, s->order[i]);
				s->tx += s->tx_step;
				s->px++;
			}
		}
	}
}
