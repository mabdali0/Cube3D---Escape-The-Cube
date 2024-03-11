/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_screen_items.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../includes/loading_items.h"

void	ft_draw_backgound(t_data *dt)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIN_HEIGHT)
	{
		j = -1;
		while (++j < WIN_WIDTH)
			ft_put_pixel(&dt->img, j, i, trgb(0,
					loading_text[(j + i * 1280) * 3],
					loading_text[(j + i * 1280) * 3 + 1],
					loading_text[(j + i * 1280) * 3 + 2]));
	}
}

void	ft_draw_menu(t_data *dt, int *pic)
{
	int	i;
	int	j;
	int	w;

	w = 250;
	i = -1;
	while (++i < 220)
	{
		j = -1;
		while (++j < w)
			ft_put_pixel(&dt->img, j + 480, i + 310, trgb(0,
					pic[(j + i * w) * 3],
					pic[(j + i * w) * 3 + 1],
					pic[(j + i * w) * 3 + 2]));
	}
}

void	ft_draw_menu_kitty(t_data *dt)
{
	int	pix;
	int	x;
	int	y;

	y = -1;
	while (++y < 64)
	{
		x = -1;
		while (++x < 64)
		{
			pix = (x + y * 64) + 64 * 64 * dt->menu.anim_state;
			dt->draw.color = trgb(0,
					kitty_walk[pix * 3],
					kitty_walk[pix * 3 + 1],
					kitty_walk[pix * 3 + 2]);
			dt->draw.x = x * 3 + 1000;
			dt->draw.y = y * 3 + 450;
			dt->draw.size = 3;
			if (dt->draw.color != 0x00FF00FF)
				draw_square(&dt->img, &dt->draw);
		}
	}
}
