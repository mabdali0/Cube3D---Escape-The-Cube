/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_steps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	manage_game_steps(t_data *dt)
{
	if (dt->game_step == 1)
	{
		ft_cat_speak(dt);
		if (dt->sc.transition_state == 1)
			transition_update(dt, &dt->sc);
	}
}
