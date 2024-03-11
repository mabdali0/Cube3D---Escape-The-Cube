/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	key_menu(int key, t_data *dt)
{
	if (key == ESCAPE && dt->game_state == 0)
		quit(dt);
	if (key == ESCAPE && dt->game_state == 2)
		dt->game_state = 1;
	else if (key == ARR_UP)
		dt->menu.select--;
	else if (key == ARR_DOWN)
		dt->menu.select++;
	else if (key == ENTER)
	{
		if (dt->menu.select == 1)
			quit(dt);
		else if (dt->menu.select == 0)
			dt->game_state = 1;
	}
	if (dt->menu.select < 0)
		dt->menu.select = 1;
	if (dt->menu.select > 1)
		dt->menu.select = 0;
}

void	key_play(int key, t_data *dt)
{
	if (key == ESCAPE)
		dt->game_state = 2;
	else if (key == DIR_UP)
		dt->player.k_up = 1;
	else if (key == DIR_DOWN)
		dt->player.k_down = 1;
	else if (key == STEP_LEFT)
		dt->player.k_left = 1;
	else if (key == STEP_RIGHT)
		dt->player.k_right = 1;
	else if (key == DIR_LEFT)
		dt->player.k_lstep = 1;
	else if (key == DIR_RIGHT)
		dt->player.k_rstep = 1;
	else if (key == SPACE && dt->player.ammo > 0)
		dt->player.attack = 1;
	else if (key == SHIFT)
		dt->player.run = 1;
}

void	key_dialogue(int key, t_data *dt)
{
	if (key == SPACE && dt->sc.transition_state != 1)
	{
		if (dt->sc.last_state_space == 0)
		{
			if (dt->al.writting == 1)
			{
				dt->al.nb_char_l1 = 99;
				dt->al.nb_char_l2 = 99;
				dt->al.writting = 0;
			}
			else
			{
				dt->al.writting = 1;
				dt->sc.dialogue_step++;
				dt->sc.last_state_space = 1;
				dt->al.nb_char_l1 = 0;
				dt->al.nb_char_l2 = 0;
			}
		}
	}
	else if (key == ESCAPE)
		dt->game_state = 2;
}

int	deal_key(int key, t_data *dt)
{
	if (dt->game_state == 1)
	{
		if (dt->game_step == 0 || dt->game_step > 1)
			key_play(key, dt);
		else if (dt->game_step == 1)
			key_dialogue(key, dt);
	}
	else if (dt->game_state == 5 || dt->game_state == 4)
	{
		if (key == ESCAPE)
			quit(dt);
	}
	else
		key_menu(key, dt);
	return (key);
}

int	reset_key(int key, t_data *dt)
{
	if (key == DIR_UP)
		dt->player.k_up = 0;
	else if (key == DIR_DOWN)
		dt->player.k_down = 0;
	else if (key == STEP_LEFT)
		dt->player.k_left = 0;
	else if (key == STEP_RIGHT)
		dt->player.k_right = 0;
	else if (key == DIR_LEFT)
		dt->player.k_lstep = 0;
	else if (key == DIR_RIGHT)
		dt->player.k_rstep = 0;
	else if (key == SPACE)
	{
		dt->player.attack = 0;
		dt->sc.last_state_space = 0;
	}
	else if (key == SHIFT)
		dt->player.run = 0;
	return (key);
}
