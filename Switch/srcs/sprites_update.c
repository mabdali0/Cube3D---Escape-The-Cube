/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static void	check_doors_unlocking(t_data *dt, t_sprites *sp)
{
	if (sp->life[10] <= 0 && sp->life[11] <= 0 && dt->maps.doors_state[9] == 2)
	{
		dt->maps.doors_state[9] = 1;
		printf("South door 1 has been unlocked\n");
		dt->sd.sound_playing = 1;
		play_audio(dt, 7);
	}
	if (sp->life[12] <= 0 && sp->life[13] <= 0
		&& sp->life[14] <= 0 && dt->maps.doors_state[11] == 2)
	{
		dt->maps.doors_state[11] = 1;
		printf("South door 2 has been unlocked\n");
		dt->sd.sound_playing = 1;
		play_audio(dt, 7);
	}
	if (sp->life[15] <= 0 && dt->maps.doors_state[10] == 2)
	{
		dt->maps.doors_state[10] = 1;
		printf("Boss door has been unlocked\n");
		dt->sd.sound_playing = 1;
		play_audio(dt, 7);
	}
}

static void	check_damage_from_player(t_data *dt, t_sprites *sp, int id)
{
	float	dist_to_player;
	float	dammage_dist;

	if (dt->player.attack == 0 || sp->life[id] <= 0
		|| dt->player.cur_weapon == 0)
		return ;
	if (sp->type[id] == 2)
		dammage_dist = dt->mima.sizebox * 0.7;
	else
		dammage_dist = dt->mima.sizebox * 0.9;
	dist_to_player = dist(dt->player.px, dt->player.py, sp->x[id], sp->y[id]);
	if (dist_to_player < dammage_dist)
	{
		sp->life[id] += -20 - (2 - dt->difficulty) * 20;
		sp->damaged[id] = 1;
		if (sp->life[id] <= 0)
		{
			sp->type[id] = -sp->type[id];
			printf("Player killed monster # %d\n", id);
			check_doors_unlocking(dt, sp);
		}
	}
}

static void	check_damage_to_player(t_data *dt, t_sprites *sp, int id)
{
	float	dist_to_player;
	float	dammage_dist;

	if (sp->type[id] == 2)
		dammage_dist = dt->mima.sizebox * 0.8;
	else
		dammage_dist = dt->mima.sizebox * 1.0;
	dist_to_player = dist(dt->player.px, dt->player.py, sp->x[id], sp->y[id]);
	if (dist_to_player < dammage_dist && !dt->god)
	{
		dt->player.damaged = 10;
		dt->player.life--;
		dt->sd.sound_playing = 1;
		play_audio(dt, 12);
		if (dt->player.life <= 0)
		{
			dt->game_state = 5;
			dt->sd.sound_playing = 1;
			play_audio(dt, 11);
		}
	}
}

static void	up_sprites2(t_data *dt, int id)
{
	if (dt->sp.type[id] == 10 && dt->frame_nb % 6 == 0
		&& (dt->player.attack || dt->player.moving))
	{
		dt->sp.states[id]++;
		if (dt->sp.states[id] > 7)
			dt->sp.states[id] = 0;
	}
	else if (dt->sp.type[id] == 11 && dt->frame_nb % 4 == 0
		&& dt->player.ammo > 0)
	{
		dt->sp.states[id]++;
		if (dt->sp.states[id] > 1)
			dt->sp.states[id] = 0;
	}
	else if (dt->sp.type[id] == 9 && dt->frame_nb % 4 == 0)
	{
		dt->sp.states[id]++;
		if (dt->sp.states[id] > 2)
			dt->sp.states[id] = 0;
	}
}

void	update_sprites(t_data *dt)
{
	int	id;

	id = -1;
	while (++id < 30)
	{
		if (dt->sp.type[id] == 1 && dt->frame_nb % 10 == 0)
		{
			dt->sp.states[id]++;
			if (dt->sp.states[id] > 11)
				dt->sp.states[id] = 0;
		}
		else if ((dt->sp.type[id] == 2 || dt->sp.type[id] == 3)
			&& dt->frame_nb % 10 == 0)
		{
			dt->sp.states[id]++;
			if (dt->sp.states[id] > 5)
				dt->sp.states[id] = 0;
			check_damage_from_player(dt, &dt->sp, id);
			if (dt->sp.states[id] == 1 || dt->sp.states[id] == 3)
				check_damage_to_player(dt, &dt->sp, id);
		}
		else
			up_sprites2(dt, id);
	}
}

// 1: cat
// 2, 3: ennemy
// 10: weapon
// 11: chain of chainsaw
