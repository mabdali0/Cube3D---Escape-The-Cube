/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	check_door(t_data *dt)
{
	int		i;
	int		unlock_dist;
	float	doorx;
	float	doory;
	int		sb;

	sb = dt->mima.sizebox;
	unlock_dist = sb * 1.2;
	i = -1;
	while (++i < dt->maps.doors_count)
	{
		doorx = (dt->maps.doors_x[i] + 1) * sb - sb / 2;
		doory = dt->maps.doors_y[i] * sb - sb / 2;
		if (dist(dt->player.px, dt->player.py, doorx, doory)
			< unlock_dist && dt->maps.doors_state[i] == 1)
		{
			dt->sd.sound_playing = 1;
			play_audio(dt, 9);
			dt->maps.doors_state[i] = 0;
			dt->maps.main[dt->maps.doors_y[i]][dt->maps.doors_x[i] + 1] = '0';
			if (i == 8)
				dt->ui.key = 0;
		}
	}
}

/*
1 Nord
2
3
4 Ouest
5 Est
6
7
8 Sud
9 Sud1
10 End
11 Sud2



*/
