/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triggers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static void	check_key_stargate(t_data *dt, t_player *p, t_sprites *s)
{
	if (dist(p->px, p->py, s->x[17], s->y[17]) < dt->tr.sb * 0.5 && s->type[17])
	{
		s->type[17] = 0;
		dt->maps.doors_state[8] = 1;
		dt->ui.key = 1;
		dt->sd.sound_playing = 1;
		play_audio(dt, 8);
	}
	if (dist(p->px, p->py, s->x[27], s->y[27]) < dt->tr.sb * 1.0)
	{
		dt->game_state = 4;
		dt->sd.sound_playing = 1;
		play_audio(dt, 10);
	}
}

static void	check_cat_saw_key(t_data *dt, t_player *p, t_sprites *s)
{
	if (dist(p->px, p->py, s->x[0], s->y[0]) < dt->tr.sb
		* 1.3 && dt->game_step < 1)
	{
		dt->game_step = 1;
		dt->player.k_up = 0;
		dt->player.k_lstep = 0;
		dt->player.k_rstep = 0;
		dt->player.k_down = 0;
		dt->sd.sound_playing = 1;
		play_audio(dt, 7);
	}
	if (dist(p->px, p->py, s->x[16], s->y[16]) < dt->tr.sb * 0.5 && s->type[16])
	{
		p->cur_weapon = 1;
		s->type[16] = 0;
		dt->sd.sound_playing = 1;
		play_audio(dt, 0);
	}
}

static void	update_ammos(t_data *dt, t_player *p)
{
	if (p->attack)
	{
		if (dt->difficulty == 1)
			p->ammo -= 1;
		else if (dt->difficulty == 2)
			p->ammo -= 2;
	}
	if (p->ammo <= 0)
		p->attack = 0;
}

void	check_triggers(t_data *dt, t_player *p, t_sprites *s)
{
	int	i;

	check_cat_saw_key(dt, p, s);
	check_key_stargate(dt, p, s);
	i = -1;
	while (++i < 30)
	{
		if (s->type[i] == 6 && dist(p->px, p->py,
				s->x[i], s->y[i]) < dt->tr.sb * 0.5)
		{
			s->type[i] = 0;
			p->life += 4 + (2 - dt->difficulty);
			if (p->life > 8)
				p->life = 8;
		}
		if (s->type[i] == 7 && dist(p->px, p->py,
				s->x[i], s->y[i]) < dt->tr.sb * 0.5)
		{
			s->type[i] = 0;
			p->ammo += 500 + (1 - dt->difficulty) * 250;
			if (p->ammo > 1000)
				p->ammo = 1000;
		}
	}
	update_ammos(dt, p);
}

void	init_triggers(t_data *dt)
{
	dt->tr.sb = dt->mima.sizebox;
	dt->tr.trig_dist = dt->tr.sb * 0.8;
}
