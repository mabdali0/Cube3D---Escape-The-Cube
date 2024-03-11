/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenario_transitions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	transition_update(t_data *dt, t_scenario *sc)
{
	if (sc->transition_start == 0)
		sc->transition_start = clock();
	if (clock() - sc->transition_start
		> (long)sc->transition_timing[sc->transition_step] * 1000)
	{
		sc->transition_step++;
		sc->transition_start = clock();
	}
	if (sc->transition_step >= 18)
	{
		sc->transition_step = 18;
		sc->transition_state = 2;
	}
	if (sc->transition_step % 2 == 0)
		dt->rays.night = 1;
	else
		dt->rays.night = 0;
}
