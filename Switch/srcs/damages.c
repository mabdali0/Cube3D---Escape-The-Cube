/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damages.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	show_damages(t_data *dt)
{
	int	x;
	int	y;

	if (dt->player.damaged > 2 && dt->frame_nb % 2)
	{
		y = -1;
		while (++y < WIN_HEIGHT)
		{
			x = -1;
			while (++x < WIN_WIDTH)
				ft_put_pixel(&dt->img, x, y, 0x00550000);
		}
		dt->player.damaged--;
	}
}
