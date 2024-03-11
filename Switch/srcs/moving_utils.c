/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	get_player_rot(t_player *p)
{
	if (p->k_left)
		p->pa -= ROT_SPEED;
	else if (p->k_right)
		p->pa += ROT_SPEED;
	if (p->pa < 0)
		p->pa += 2 * PI;
	else if (p->pa > 2 * PI)
		p->pa -= 2 * PI;
}

float	get_new_dir(t_player *p)
{
	float	dir;

	dir = p->pa;
	if (p->k_up && p->k_lstep)
		dir = p->pa + PI / 4;
	else if (p->k_up && p->k_rstep)
		dir = p->pa - PI / 4;
	else if (p->k_down && p->k_lstep)
		dir = p->pa + 3 * PI / 4;
	else if (p->k_down && p->k_rstep)
		dir = p->pa - 3 * PI / 4;
	else if (p->k_up)
		dir = p->pa;
	else if (p->k_down)
		dir = p->pa + PI;
	else if (p->k_lstep)
		dir = p->pa + P2;
	else if (p->k_rstep)
		dir = p->pa - P2;
	if (dir < 0)
		dir += 2 * PI;
	if (dir > 2 * PI)
		dir -= 2 * PI;
	return (dir);
}

void	fix_player_pos(t_player *p)
{
	if (p->py < 0)
		p->py = 0.0;
	if (p->py > WIN_HEIGHT)
		p->py = (float)WIN_HEIGHT;
	if (p->px < 0)
		p->px = 0.0;
	if (p->px > WIN_WIDTH)
		p->px = (float)WIN_WIDTH;
}
