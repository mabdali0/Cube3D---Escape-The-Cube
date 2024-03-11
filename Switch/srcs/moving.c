/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static void	check_monsters(t_data *dt, t_player *p, t_sprites *s, float dir)
{
	int	i;

	i = -1;
	while (++i < 30)
	{
		if (s->type[i] == 2 || s->type[i] == 3)
		{
			if (dist(p->px, p->py, s->x[i], s->y[i]) < dt->mima.sizebox * 0.4)
			{
				if ((dir < 0.25 * PI || dir > 1.75) && p->px < s->x[i])
					p->blocked_dir[0] = 1;
				else if (dir < 0.75 * PI && p->py > s->y[i])
					p->blocked_dir[1] = 1;
				else if (dir < 1.25 * PI && p->px > s->x[i])
					p->blocked_dir[2] = 1;
				else if (p->py < s->y[i])
					p->blocked_dir[3] = 1;
			}
		}
	}
}

void	check_move(t_data *dt, t_player *p)
{
	t_move	mv;

	mv.ipx = p->px / dt->mima.sizebox;
	mv.ipy = p->py / dt->mima.sizebox;
	mv.new_ipx = (p->px + p->pdx * 5) / dt->mima.sizebox;
	mv.new_ipy = (p->py + p->pdy * 5) / dt->mima.sizebox;
	if (dt->maps.main[mv.ipy + 1][mv.new_ipx + 1] == '0')
	{
		if (!(p->blocked_dir[1] || p->blocked_dir[3]))
			p->px += p->pdx;
	}
	if (dt->maps.main[mv.new_ipy + 1][mv.ipx + 1] == '0')
	{
		if (!(p->blocked_dir[0] || p->blocked_dir[2]))
			p->py += p->pdy;
	}
}

void	do_moves(t_data *dt, t_player *p)
{
	float	speed;
	float	dir;
	int		i;

	speed = PLAYER_SPEED;
	if (dt->player.run)
		speed = RUN_SPEED;
	get_player_rot(p);
	if (p->moving)
	{
		dir = get_new_dir(p);
		p->pdx = cos(dir) * speed;
		p->pdy = sin(dir) * speed;
		p->next_px = p->px + p->pdx;
		p->next_py = p->py + p->pdy;
		i = -1;
		while (++i < 4)
			p->blocked_dir[i] = 0;
		check_monsters(dt, p, &dt->sp, dir);
		check_move(dt, p);
	}
	fix_player_pos(p);
	check_door(dt);
}
