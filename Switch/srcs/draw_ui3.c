/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ui3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../includes/text_ui2.h"

void	draw_key_fuel(t_data *dt, t_draw *d)
{
	int	i;

	d->x = 900;
	d->y = 613;
	if (dt->ui.key)
		draw_image_ppm(dt, 126, 65, key_ui);
	d->x = 1130;
	d->y = 705;
	if (dt->player.cur_weapon == 1)
		draw_image_ppm(dt, 72, 72, jerrican_ui);
	d->starty = 760;
	i = -1;
	while (++i < dt->player.ammo / 7 && dt->player.cur_weapon == 1)
	{
		d->startx = 970 + i;
		d->endx = d->startx;
		d->endy = d->starty - 0.2 * i;
		d->color = 0x0000FF00;
		if (i < 500 / 7)
			d->color = 0x00FFE800;
		if (i < 200 / 7)
			d->color = 0x00FF0000;
		draw_line(&dt->img, d);
	}
}
