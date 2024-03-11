/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../includes/text_ui.h"

void	choose_heart(t_data *dt, int n, int cat)
{
	if (n <= cat + 2 && n >= cat && (n % 2 == 1))
		draw_image_ppm(dt, 30, 30, texture_half_heart);
	else if (n == cat + 2 || n > cat + 2)
		draw_image_ppm(dt, 30, 30, texture_heart);
}

void	draw_heart(t_data *dt)
{
	dt->draw.x = 290;
	dt->draw.y = 620;
	draw_image_ppm(dt, 150, 30, texture_health);
	dt->draw.y += 40;
	if (dt->player.life > 0)
		choose_heart(dt, dt->player.life, 0);
	else
		draw_image_ppm(dt, 30, 30, texture_noheart);
	dt->draw.x += 40;
	if (dt->player.life > 2)
		choose_heart(dt, dt->player.life, 2);
	else
		draw_image_ppm(dt, 30, 30, texture_noheart);
	dt->draw.x += 40;
	if (dt->player.life > 4)
		choose_heart(dt, dt->player.life, 4);
	else
		draw_image_ppm(dt, 30, 30, texture_noheart);
	dt->draw.x += 40;
	if (dt->player.life > 6)
		choose_heart(dt, dt->player.life, 6);
	else
		draw_image_ppm(dt, 30, 30, texture_noheart);
}

void	draw_timer(t_data *dt)
{
	int	time;
	int	secu;
	int	secd;
	int	minu;
	int	mind;

	time = (double)(clock() - dt->ui.start_time) / CLOCKS_PER_SEC;
	secu = (time % 60) % 10;
	secd = (time % 60) / 10;
	minu = (time / 60) % 10;
	mind = (time / 60) / 10;
	dt->draw.y = 710;
	dt->draw.x = 300;
	draw_image_ppm(dt, 30, 50, texture_number[mind]);
	dt->draw.x += 28;
	draw_image_ppm(dt, 30, 50, texture_number[minu]);
	dt->draw.x += 28;
	draw_image_ppm(dt, 20, 50, texture_twodot);
	dt->draw.x += 18;
	draw_image_ppm(dt, 30, 50, texture_number[secd]);
	dt->draw.x += 28;
	draw_image_ppm(dt, 30, 50, texture_number[secu]);
}

void	sprite_hurt(t_data *dt, t_ui *ui)
{
	if (clock() - ui->spriteclock >= 2500000)
	{
		ui->sprite_face++;
		ui->spriteclock = clock();
	}
	if (ui->sprite_face > 2)
		ui->sprite_face = 0;
	dt->draw.x = 640 - 62;
	dt->draw.y = 625;
	if (dt->player.life >= 7)
		draw_image_ppm(dt, 124, 150, texture_hurt0[ui->sprite_face]);
	else if (dt->player.life >= 5)
		draw_image_ppm(dt, 124, 150, texture_hurt1[ui->sprite_face]);
	else if (dt->player.life >= 3)
		draw_image_ppm(dt, 120, 150, texture_hurt2[ui->sprite_face]);
	else if (dt->player.life >= 1)
		draw_image_ppm(dt, 116, 150, texture_hurt3[ui->sprite_face]);
	else if (dt->player.life <= 0)
		draw_image_ppm(dt, 116, 150, texture_hurt4);
}

void	draw_interface(t_data *dt, t_minimap *mi)
{
	dt->draw.x = 0;
	dt->draw.y = 600;
	dt->draw.w = WIN_WIDTH;
	dt->draw.h = dt->ui_h;
	dt->draw.color = trgb(0, 50, 0, 50);
	draw_rect(&dt->img, &dt->draw);
	dt->draw.x = 100;
	dt->draw.y = 700;
	dt->draw.size = 180;
	dt->draw.color = trgb(0, 50, 0, 50);
	draw_square(&(dt->img), &dt->draw);
	dt->draw.size = 175;
	dt->draw.color = trgb(0, 0, 0, 0);
	draw_square(&(dt->img), &dt->draw);
	draw_minimap(dt, mi);
	draw_heart(dt);
	sprite_hurt(dt, &dt->ui);
	draw_timer(dt);
	draw_key_fuel(dt, &dt->draw);
}
