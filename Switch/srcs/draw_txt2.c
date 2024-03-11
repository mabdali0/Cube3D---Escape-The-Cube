/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_txt2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	draw_space_button(t_data *dt)
{
	dt->draw.x = 1100;
	dt->draw.y = 175;
	dt->draw.h = 40;
	dt->draw.w = 130;
	dt->draw.color = 0x00000000;
	draw_rect(&dt->img, &dt->draw);
	dt->draw.x += 5;
	dt->draw.y += 5;
	dt->draw.h -= 10;
	dt->draw.w -= 10;
	dt->draw.color = 0x00FFFFFF;
	draw_rect(&dt->img, &dt->draw);
	dt->al.str = "Space";
	dt->al.x = 1120;
	dt->al.y = 181;
	ft_put_text(dt, &dt->al, 5);
}

void	draw_txt_back(t_data *dt)
{
	dt->draw.x = 10;
	dt->draw.y = 50;
	dt->draw.h = 115;
	dt->draw.w = 1280 - 2 * dt->draw.x;
	dt->draw.color = 0x00000000;
	draw_rect(&dt->img, &dt->draw);
	dt->draw.x = 20;
	dt->draw.y += 10;
	dt->draw.h = 95;
	dt->draw.w = 1280 - 2 * dt->draw.x;
	dt->draw.color = 0x00FFFFFF;
	draw_rect(&dt->img, &dt->draw);
}
