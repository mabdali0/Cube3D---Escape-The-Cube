/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static void	debug(t_data *dt)
{
	int	i;

	i = -1;
	draw_map(dt, &dt->mima);
	draw_player(dt);
	while (++i < 30)
	{
		if (dt->sp.type[i] == 2)
		{
			dt->draw.x = dt->sp.destx[i];
			dt->draw.y = dt->sp.desty[i];
			dt->draw.color = 0x0000FF00;
			dt->draw.size = 5;
			draw_square(&dt->img, &dt->draw);
			dt->draw.x = dt->sp.x[i];
			dt->draw.y = dt->sp.y[i];
			if (dt->sp.active[i] == 0)
				dt->draw.color = 0x00FFFF00;
			else
				dt->draw.color = 0x00FF0000;
			dt->draw.size = 5;
			draw_square(&dt->img, &dt->draw);
		}
	}
}

void	next_game_frame(t_data *dt)
{
	clock_t	init;
	int		sl_time;
	clock_t	start;

	printf("***************************\n");
	init = clock();

	start = clock();
	manage_mouse(dt);
	do_moves(dt, &dt->player);
	check_triggers(dt, &dt->player, &dt->sp);
	printf("moves	: %ld\n", clock() - start);

	start = clock();
	rays_mobs(dt);
	printf("ray mobs: %ld\n", clock() - start);

	start = clock();
	manage_ai(dt);
	printf("ai		: %ld\n", clock() - start);

	start = clock();
	update_sprites(dt);
	printf("up sp	: %ld\n", clock() - start);

	start = clock();
	draw_rays(dt);
	printf("rays	: %ld\n", clock() - start);

	start = clock();
	draw_sprites(dt, &dt->sp, &dt->draw);
	printf("draw sp	: %ld\n", clock() - start);

	draw_weapon(dt, &dt->sp, &dt->draw);
	//draw_interface(dt, &dt->mima);
	manage_game_steps(dt);
	manage_sounds(dt);
	show_damages(dt);
	if (dt->dev)
		debug(dt);
	dt->img_exists = 1;
	mlx_put_image_to_window(dt->mlx, dt->win, dt->img.img, 0, 0);
	printf("tot 	: %ld\n", clock() - init);
	sl_time = 1000000 / 40 - (int)(((float)(clock() - init)
				/ CLOCKS_PER_SEC) * 1000000);
	if (sl_time > 0)
		usleep(sl_time);
}

int	next_frame(t_data *dt)
{
	dt->frame_nb++;
	if (dt->game_state == 0 || dt->game_state == 2)
	{
		main_menu(dt);
		usleep(10000);
	}
	else if (dt->game_state == 1)
		next_game_frame(dt);
	else if (dt->game_state == 5)
	{
		you_died(dt);
		usleep(10000);
	}
	else if (dt->game_state == 4)
	{
		you_win(dt);
		usleep(10000);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	dt;

	check_args(&dt, argc, argv);
	dt.disable_xwin = 1;
	printf("\n/----------------------------------------------\\\n");
	printf("|                                              |\n");
	printf("|                 C U B E   3 D                |\n");
	printf("|                                              |\n");
	printf("\\----------------------------------------------/\n\n");
	printf("******** USE 'help' TO SEE AVAILLABLE COMMANDS\n\n");
	init_mlx(&dt);
	init_sdl(&dt.sd);
	mlx_loop_hook(dt.mlx, next_frame, &dt);
	init_values(&dt);
	printf("\n>> INITIALISATION DONE\n\n");
	printf(">> GAME LOADED.. ENJOY !!\n\n\n");
	dt.game_step = 0;
	dt.rays.night = 0;
	mlx_loop(dt.mlx);
	return (0);
}

/*
Visee verticale
Sons

GAME STATES:
0: Menu initial
1: Jeu
2: Pause
4: WIN
5: DEAD

GAME STEPS:
0: Cherche le chat
1: Talk with cat
2: Anim orage
3: Cherche gun
4: Cherche key
5: Atteindre sortie

*/
