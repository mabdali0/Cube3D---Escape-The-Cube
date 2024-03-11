/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	draw_map(t_data *dt, t_minimap *mi)
{
	int	i;
	int	j;
	int	size;

	size = mi->sizebox;
	j = -1;
	while (++j < (int)dt->maps.h)
	{
		i = -1;
		while (++i < (int)dt->maps.w)
		{
			if (dt->maps.main[j + 1][i + 1] != '0')
			{
				dt->draw.x = size / 2 + size * i;
				dt->draw.y = size / 2 + size * j;
				dt->draw.size = size - 1;
				dt->draw.color = 0x00600000;
				draw_square(&(dt->img), &dt->draw);
			}
		}
	}
}

void	draw_player(t_data *dt)
{
	dt->draw.x = dt->player.px;
	dt->draw.y = dt->player.py;
	dt->draw.size = 5;
	dt->draw.color = trgb(0, 255, 255, 0);
	draw_square(&(dt->img), &dt->draw);
	dt->draw.startx = dt->player.px;
	dt->draw.starty = dt->player.py;
	dt->draw.endx = dt->player.px + cos(dt->player.pa) * dt->mima.sizebox - 1;
	dt->draw.endy = dt->player.py + sin(dt->player.pa) * dt->mima.sizebox - 1;
	dt->draw.color = trgb(0, 200, 200, 0);
	dt->draw.line_width = 2;
	draw_line(&dt->img, &dt->draw);
}
