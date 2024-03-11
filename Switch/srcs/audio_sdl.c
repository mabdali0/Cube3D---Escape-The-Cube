/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio_sdl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	destroy_sdl(t_sounds *s)
{
	int	i;

	SDL_ClearQueuedAudio(s->audiodevice);
	i = -1;
	while (++i <= 14)
		SDL_FreeWAV(s->audiodata[i]);
	SDL_CloseAudioDevice(s->audiodevice);
	SDL_Quit();
}

static void	load_sound_files2(t_sounds *s)
{
	SDL_LoadWAV("./ressources/audio/hurt.wav",
		&(s->loadedaudiospec), &(s->audiodata[12]), &(s->audiolenght[12]));
	SDL_LoadWAV("./ressources/audio/title.wav",
		&(s->loadedaudiospec), &(s->audiodata[13]), &(s->audiolenght[13]));
	SDL_LoadWAV("./ressources/audio/growl.wav",
		&(s->loadedaudiospec), &(s->audiodata[14]), &(s->audiolenght[14]));
}

static void	load_sound_files(t_sounds *s)
{
	SDL_LoadWAV("./ressources/audio/chainsaw_start.wav",
		&(s->loadedaudiospec), &(s->audiodata[0]), &(s->audiolenght[0]));
	SDL_LoadWAV("./ressources/audio/chainsaw_idle.wav",
		&(s->loadedaudiospec), &(s->audiodata[1]), &(s->audiolenght[1]));
	SDL_LoadWAV("./ressources/audio/chainsaw_speedup.wav",
		&(s->loadedaudiospec), &(s->audiodata[2]), &(s->audiolenght[2]));
	SDL_LoadWAV("./ressources/audio/chainsaw_run.wav",
		&(s->loadedaudiospec), &(s->audiodata[3]), &(s->audiolenght[3]));
	SDL_LoadWAV("./ressources/audio/chainsaw_speeddown.wav",
		&(s->loadedaudiospec), &(s->audiodata[4]), &(s->audiolenght[4]));
	SDL_LoadWAV("./ressources/audio/steps.wav",
		&(s->loadedaudiospec), &(s->audiodata[5]), &(s->audiolenght[5]));
	SDL_LoadWAV("./ressources/audio/thunder.wav",
		&(s->loadedaudiospec), &(s->audiodata[6]), &(s->audiolenght[6]));
	SDL_LoadWAV("./ressources/audio/secret.wav",
		&(s->loadedaudiospec), &(s->audiodata[7]), &(s->audiolenght[7]));
	SDL_LoadWAV("./ressources/audio/key.wav",
		&(s->loadedaudiospec), &(s->audiodata[8]), &(s->audiolenght[8]));
	SDL_LoadWAV("./ressources/audio/door.wav",
		&(s->loadedaudiospec), &(s->audiodata[9]), &(s->audiolenght[9]));
	SDL_LoadWAV("./ressources/audio/win.wav",
		&(s->loadedaudiospec), &(s->audiodata[10]), &(s->audiolenght[10]));
	SDL_LoadWAV("./ressources/audio/gameover.wav",
		&(s->loadedaudiospec), &(s->audiodata[11]), &(s->audiolenght[11]));
}

void	init_sdl(t_sounds *s)
{
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		printf("------------ SDL AUDIO INIT ERROR ------------\n");
		return ;
	}
	s->audiospec.freq = 44100;
	s->audiospec.format = AUDIO_S16SYS;
	s->audiospec.channels = 2;
	s->audiospec.samples = 1024;
	s->audiospec.callback = NULL;
	s->audiospec.userdata = NULL;
	s->audiodevice = SDL_OpenAudioDevice(NULL, 0, &s->audiospec, NULL, 0);
	printf("\nAudio device: %d\n\n", s->audiodevice);
	if (s->audiodevice == 0)
	{
		printf("------------ SDL CANT OPEN DEVICE ERROR ------------\n");
		return ;
	}
	SDL_PauseAudioDevice(s->audiodevice, 0);
	load_sound_files(s);
	load_sound_files2(s);
	s->sound_playing = 0;
}
