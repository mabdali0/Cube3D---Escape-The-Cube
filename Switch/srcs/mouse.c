/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	manage_mouse(t_data *dt)
{
	t_mouse	m;

	m.rootx = 0;
	m.rooty = 0;
	m.winx = 0;
	m.winy = 0;
	m.mask = 0;
	if (XQueryPointer(dt->dpy, dt->root_window, &dt->root_window,
			&m.child_window, &m.rootx, &m.rooty, &m.winx, &m.winy, &m.mask))
	{
		dt->player.pa -= (dt->screen_w / 2 - m.rootx) * 0.004;
		dt->player.vangle += (dt->screen_h / 2 - m.rooty) * 0.5;
	}
	if (dt->player.vangle > 200)
		dt->player.vangle = 200;
	if (dt->player.vangle < -200)
		dt->player.vangle = -200;
	XSelectInput(dt->dpy, dt->root_window, KeyReleaseMask);
	XWarpPointer(dt->dpy, None, dt->root_window, 0, 0, 0, 0,
		dt->screen_w / 2, dt->screen_h / 2);
	XFlush(dt->dpy);
}

int	mouse_button_press(int button, int x, int y, t_data *dt)
{
	(void)x;
	(void)y;
	if (button == 1 && dt->player.ammo > 0)
		dt->player.attack = 1;
	return (0);
}

int	mouse_button_released(int button, int x, int y, t_data *dt)
{
	(void)x;
	(void)y;
	if (button == 1)
		dt->player.attack = 0;
	return (0);
}
