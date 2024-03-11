/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	draw_line(t_imgd *img, t_draw *d)
{
	t_linedraw	ld;

	if (abs((int)round(d->endx - d->startx))
		> abs((int)round(d->endy - d->starty)))
		ld.steps = abs((int)round(d->endx - d->startx));
	else
		ld.steps = abs((int)round(d->endy - d->starty));
	ld.xinc = (float)(d->endx - d->startx) / ld.steps;
	ld.yinc = (float)(d->endy - d->starty) / ld.steps;
	ld.j = -1;
	while (++ld.j < d->line_width)
	{
		ld.x = d->startx;
		ld.y = d->starty;
		ld.i = -1;
		while (++ld.i <= ld.steps)
		{
			ft_put_pixel(img, (int)round(ld.x - d->line_width
					+ ld.j), (int)round(ld.y), d->color);
			ld.x += ld.xinc;
			ld.y += ld.yinc;
		}
	}
}

void	draw_v_line(t_imgd *img, t_draw *d)
{
	int	i;
	int	n;

	n = -1;
	while (++n < d->line_width)
	{
		i = d->starty;
		while (i < d->endy)
		{
			ft_put_pixel(img, d->startx - d->line_width + n, i, d->color);
			i++;
		}
	}
}
