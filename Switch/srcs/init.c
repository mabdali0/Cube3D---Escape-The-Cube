/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static void	init_player(t_minimap *mima, t_player *p)
{
	p->px = p->start_pos_x * mima->sizebox + mima->sizebox / 2;
	p->py = p->start_pos_y * mima->sizebox - mima->sizebox / 2;
	p->pa = p->start_angle;
	printf("Player starts at x: %.0f, y: %.0f, angle: %.2f\n\n",
		p->px, p->py, p->pa);
	p->k_up = 0;
	p->k_down = 0;
	p->k_left = 0;
	p->k_right = 0;
	p->k_rstep = 0;
	p->k_lstep = 0;
	p->pdx = 0.0;
	p->pdy = 0.0;
	p->speed = 0.0;
	p->life = 8;
	p->cur_weapon = 0;
	p->attack = 0;
	p->damaged = 0;
	p->vangle = 0;
	p->ammo = 1000;
	p->run = 0;
	p->moving = 0;
}

static void	init_mimap(t_minimap *mima, t_maps *map, t_data *dt)
{
	mima->px = MINIMAP_X;
	mima->py = MINIMAP_Y;
	mima->w = MINIMAP_W;
	mima->h = MINIMAP_H;
	mima->sizebox = (mima->w / map->w);
	printf("sb: %d, mapW: %ld\n", mima->sizebox, map->w);
	mima->uix = 40;
	mima->uiy = dt->win_h + 20;
	mima->uih = dt->ui_h - 40;
	mima->uisize = mima->uih / map->w;
	dt->ui.sprite_face = 0;
	dt->ui.start_time = clock();
	dt->ui.spriteclock = clock();
	dt->ui.key = 0;
}

void	init_values2(t_data *dt)
{
	int	i;

	init_sprites(&dt->sp);
	update_loading(dt, &dt->menu, 20);
	load_textures(dt, &dt->tx);
	init_triggers(dt);
	init_scenario(dt, &dt->sc);
	if (dt->dev)
	{
		i = -1;
		while (++i < dt->maps.doors_count)
			dt->maps.doors_state[i] = 1;
	}
	dt->sd.chainsaw_state = 1;
	if (dt->difficulty < 2)
		dt->player.ammo = 1000;
}

void	init_values(t_data *dt)
{
	int		i;

	dt->rays.night = 0;
	dt->tx.walls = malloc(sizeof(int *) * 10);
	i = -1;
	while (++i < 10)
		dt->tx.walls[i] = NULL;
	dt->menu.select = 0;
	dt->game_state = 0;
	dt->game_step = 0;
	dt->maps.doors_count = 0;
	dt->frame_nb = 0;
	dt->img_exists = 0;
	dt->maps.path = "./maps/level1.cub";
	dt->maps.map_malloc = 0;
	update_loading(dt, &dt->menu, 10);
	load_map(dt);
	update_loading(dt, &dt->menu, 15);
	init_mimap(&dt->mima, &dt->maps, dt);
	init_player(&dt->mima, &dt->player);
	dt->ui_h = WIN_HEIGHT * 0; //0.25;
	dt->win_h = WIN_HEIGHT - dt->ui_h;
	dt->var = 400;
	dt->var2 = 1.0;
	init_values2(dt);
}

void	init_mlx(t_data *dt)
{
	dt->dpy = XOpenDisplay(0);
	if (dt->dpy == NULL)
		exit(0);
	dt->screen = XScreenOfDisplay(dt->dpy, DefaultScreen(dt->dpy));
	dt->root_window = XDefaultRootWindow(dt->dpy);
	dt->screen_w = WidthOfScreen(dt->screen);
	dt->screen_h = HeightOfScreen(dt->screen);
	dt->mlx = mlx_init();
	dt->win = mlx_new_window(dt->mlx, WIN_WIDTH, WIN_HEIGHT, "Cube3D");
	if (!dt->disable_xwin)
		init_window(dt);
	dt->img.img = mlx_new_image(dt->mlx, WIN_WIDTH, WIN_HEIGHT);
	dt->img.addr = mlx_get_data_addr(dt->img.img, &(dt->img.bits_per_pixel),
			&(dt->img.line_length), &(dt->img.endian));
	loading_scren(dt);
	mlx_hook(dt->win, ON_DESTROY, 0, quit, dt);
	mlx_hook(dt->win, ON_KEYDOWN, 1L << 0, deal_key, dt);
	mlx_hook(dt->win, ON_KEYUP, 1L << 1, reset_key, dt);
	mlx_hook(dt->win, 4, 1L << 2, mouse_button_press, dt);
	mlx_hook(dt->win, 5, 1L << 3, mouse_button_released, dt);
	if (dt->mousehide)
		mlx_mouse_hide(dt->mlx, dt->win);
}
