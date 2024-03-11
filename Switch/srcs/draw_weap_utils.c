/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_weap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	is_player_moving(t_data *dt)
{
	if (dt->player.k_up || dt->player.k_down
		|| dt->player.k_lstep || dt->player.k_rstep)
		dt->player.moving = 1;
	else
	{
		dt->player.moving = 0;
		if (!dt->player.attack)
			dt->sp.states[29] = 0;
	}
}

void	scale_pic(t_data *dt, t_draw *d, int scale)
{
	int	i;
	int	j;
	int	posx;
	int	posy;

	i = 0;
	while (++i <= scale)
	{
		j = 0;
		while (++j <= scale)
		{
			posx = d->w * scale + i + d->x;
			posy = d->h * scale + j + d->y;
			if (d->color != 0x0000FFFF && d->color != 0x00FF00FF
				&& posx > 0 && posx < WIN_WIDTH && posy < WIN_HEIGHT)
				ft_put_pixel(&dt->img, posx, posy, d->color);
		}
	}
}
