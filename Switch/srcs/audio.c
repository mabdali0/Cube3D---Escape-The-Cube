/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	play_audio(t_data *dt, int id)
{
	t_sounds	*s;

	s = &dt->sd;
	if (dt->sd.chainsaw_state != id)
	{
		SDL_ClearQueuedAudio(s->audiodevice);
	}
	SDL_QueueAudio(s->audiodevice, s->audiodata[id], s->audiolenght[id]);
	dt->sd.chainsaw_state = id;
}

void	manage_sounds_chainsaw(t_data *dt, Uint32 soundsize)
{
	if (dt->player.cur_weapon == 1)
	{
		if (dt->player.attack == 1)
		{
			if (dt->sd.chainsaw_state == 3 || dt->sd.chainsaw_state == 2)
			{
				if (soundsize < 10000)
					play_audio(dt, 3);
			}
			else
				play_audio(dt, 2);
		}
		else
		{
			if (dt->sd.chainsaw_state == 1 || dt->sd.chainsaw_state >= 4)
			{
				if (soundsize < 10000)
					play_audio(dt, 1);
			}
			else
				play_audio(dt, 4);
		}
	}
}

void	manage_sounds_steps(t_data *dt, Uint32 soundsize)
{
	if (dt->player.moving)
	{
		if (soundsize < 10000)
			play_audio(dt, 5);
	}
	else
	{
		if (soundsize > 0)
			SDL_ClearQueuedAudio(dt->sd.audiodevice);
	}
}

void	manage_sounds(t_data *dt)
{
	Uint32	soundsize;

	soundsize = SDL_GetQueuedAudioSize(dt->sd.audiodevice);
	if (soundsize <= 0)
	{
		dt->sd.sound_playing = 0;
		if (dt->sd.sound_playing == 0)
			dt->sd.chainsaw_state = 1;
	}
	if (dt->sd.sound_playing == 0)
	{
		if (dt->player.cur_weapon == 0)
			manage_sounds_steps(dt, soundsize);
		else if (dt->player.cur_weapon == 1)
			manage_sounds_chainsaw(dt, soundsize);
	}
}
