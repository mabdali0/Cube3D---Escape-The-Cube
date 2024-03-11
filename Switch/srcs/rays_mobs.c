/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_mobs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static void	detect1(t_sprites *s, int x, int y)
{
	if ((((x == 24 || x == 25) && y == 6)
			|| (x == 24 && y == 3)) && !s->active[1])
		s->active[1] = 1;
	if (((x == 19 && y == 6) || (x == 22 && y == 1)) && !s->active[2])
		s->active[2] = 1;
	if ((x == 29 && y == 9) && !s->active[3])
		s->active[3] = 1;
	if ((x == 29 && y == 3) && !s->active[4])
		s->active[4] = 1;
}

static void	detect2(t_sprites *s, int x, int y)
{
	if (((x == 28 && y == 14) || (x == 31 && y == 19)) && !s->active[5])
		s->active[5] = 1;
	if (((x == 31 && y == 19) || (x == 28 && y == 23)) && !s->active[6])
		s->active[6] = 1;
	if (((x == 21 && y == 21) || (x == 24 && y == 25)) && !s->active[8])
		s->active[8] = 1;
	if ((x == 20 && y == 20) && !s->active[9])
		s->active[9] = 1;
	if ((((x == 26 || x == 24) && y == 18) || (x == 24
				&& (y == 24 || y == 46))) && !s->active[7])
		s->active[7] = 1;
}

static void	detect3(t_sprites *s, int x, int y)
{
	if (x == 15 && y == 15 && !s->active[10])
	{
		s->active[10] = 1;
		s->active[11] = 1;
	}
	if (x == 17 && y == 21 && !s->active[12])
	{
		s->active[12] = 1;
		s->active[13] = 1;
		s->active[14] = 1;
	}
	if (x == 11 && y == 24 && !s->active[15])
	{
		s->active[15] = 1;
	}
}

void	rays_mobs(t_data *dt)
{
	t_sprites	*s;
	int			casex;
	int			casey;
	int			i;

	s = &dt->sp;
	(void)s;
	casex = dt->player.px / dt->mima.sizebox;
	casey = dt->player.py / dt->mima.sizebox;
	detect1(s, casex, casey);
	detect2(s, casex, casey);
	detect3(s, casex, casey);
	i = -1;
	while (++i < 30)
	{
		if (dt->sp.type[i] == 2 || dt->sp.type[i] == 3)
		{
			if (dt->sp.active[i] == 1)
			{
				dt->sd.sound_playing = 1;
				play_audio(dt, 14);
				dt->sp.active[i] = 2;
			}
		}
	}
}
