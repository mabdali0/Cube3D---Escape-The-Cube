/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ui2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	draw_image_ppm(t_data *dt, int w, int h, int *tab)
{
	t_draw	*d;
	int		i;
	int		j;
	int		pix;

	d = &(dt->draw);
	i = 0;
	while (i < w)
	{
		j = 0;
		while (j < h)
		{
			pix = j * w + i;
			d->color = trgb(0, tab[pix * 3],
					tab[pix * 3 + 1], tab[pix * 3 + 2]);
			if (dt->draw.color != 0x00800080 && dt->draw.color != 0x00FF00FF)
				ft_put_pixel(&dt->img, i + d->x, j + d->y, d->color);
			j++;
		}
		i++;
	}
}

static void	draw_square_mini(t_data *dt, int x, int y, int color)
{
	int	i;
	int	j;
	int	pixx;
	int	pixy;

	i = -1;
	while (++i < 15)
	{
		j = -1;
		while (++j < 15)
		{
			pixx = i + x - 15 / 2;
			pixy = j + y - 15 / 2;
			if (pixx >= 20 && pixx < 180 && pixy
				>= 621 && pixy < 780)
			{
				if (dt->rays.night)
					ft_put_pixel(&dt->img, pixx, pixy, ft_add_shade(color,
							80 - 1.2 * dist(pixx, pixy, 90, 700)));
				else
					ft_put_pixel(&dt->img, pixx, pixy, color);
			}
		}
	}
}

static void	draw_player_ui(t_data *dt)
{
	dt->draw.x = 90;
	dt->draw.y = 700;
	dt->draw.size = 7;
	dt->draw.color = trgb(0, 0, 0, 0);
	draw_square(&(dt->img), &dt->draw);
	dt->draw.startx = 92;
	dt->draw.starty = 700;
	dt->draw.endx = 92 + cos(dt->player.pa) * (float)dt->mima.sizebox - 1;
	dt->draw.endy = 700 + sin(dt->player.pa) * (float)dt->mima.sizebox - 1;
	dt->draw.color = trgb(0, 0, 0, 0);
	dt->draw.line_width = 2;
	draw_line(&dt->img, &dt->draw);
}

void	draw_minimap(t_data *dt, t_minimap *mi)
{
	int	i;
	int	j;
	int	color;
	int	size;

	size = mi->sizebox;
	j = -1;
	while (++j < (int)dt->maps.h)
	{
		i = -1;
		while (++i < (int)dt->maps.w)
		{
			if (dt->maps.main[j + 1][i + 1] != '0')
				color = trgb(0, 0, 128, 0);
			else
				color = trgb(0, 250, 250, 210);
			draw_square_mini(dt, size / 2 + size * i - dt->player.px
				+ 90, size / 2 + size * j - dt->player.py + 700, color);
		}
	}
	draw_player_ui(dt);
}
