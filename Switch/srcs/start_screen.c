/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../includes/loading.h"

void	you_win(t_data *dt)
{
	dt->draw.x = 0;
	dt->draw.y = 0;
	draw_image_ppm(dt, 1280, 800, youwin);
	mlx_put_image_to_window(dt->mlx, dt->win, dt->img.img, 0, 0);
}

void	you_died(t_data *dt)
{
	dt->draw.x = 0;
	dt->draw.y = 313;
	draw_image_ppm(dt, 1280, 174, youdied);
	mlx_put_image_to_window(dt->mlx, dt->win, dt->img.img, 0, 0);
}

void	update_loading(t_data *dt, t_main_menu *mm, int loading)
{
	int			i;
	int			j;
	static int	lasti;

	i = lasti;
	while (i < mm->loading_bar_w * loading / 100)
	{
		j = -1;
		while (++j < mm->loading_bar_h)
			ft_put_pixel(&dt->img, mm->loading_bar_x + i,
				mm->loading_bar_y + j, 0x00BB00BB);
		i++;
	}
	mlx_put_image_to_window(dt->mlx, dt->win, dt->img.img, 0, 0);
}

void	main_menu(t_data *dt)
{
	Uint32	soundsize;

	soundsize = SDL_GetQueuedAudioSize(dt->sd.audiodevice);
	if (soundsize <= 0)
	{
		dt->sd.sound_playing = 0;
		play_audio(dt, 13);
	}
	ft_draw_backgound(dt);
	if (dt->menu.select == 0)
		ft_draw_menu(dt, menu_start);
	else
		ft_draw_menu(dt, menu_exit);
	if (dt->frame_nb % 20 == 0)
		dt->menu.anim_state++;
	if (dt->menu.anim_state > 3)
		dt->menu.anim_state = 0;
	ft_draw_menu_kitty(dt);
	mlx_put_image_to_window(dt->mlx, dt->win, dt->img.img, 0, 0);
}

void	loading_scren(t_data *dt)
{
	ft_draw_backgound(dt);
	dt->menu.loading_bar_x = 50;
	dt->menu.loading_bar_y = WIN_HEIGHT - 100;
	dt->menu.loading_bar_w = WIN_WIDTH - 100;
	dt->menu.loading_bar_h = 30;
	dt->draw.x = dt->menu.loading_bar_x;
	dt->draw.w = dt->menu.loading_bar_w;
	dt->draw.y = dt->menu.loading_bar_y;
	dt->draw.h = dt->menu.loading_bar_h;
	dt->draw.color = 0x330033;
	draw_rect(&dt->img, &dt->draw);
	update_loading(dt, &dt->menu, 5);
	update_loading(dt, &dt->menu, 5);
	update_loading(dt, &dt->menu, 5);
	dt->menu.anim_state = 0;
}
