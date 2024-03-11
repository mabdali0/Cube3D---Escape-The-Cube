/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	free_map(t_data *dt)
{
	size_t	i;

	i = -1;
	while (++i < dt->maps.h + 2)
		free(dt->maps.main[i]);
	free(dt->maps.main);
}

void	free_walls(t_textures *t)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (t->walls[i])
			free(t->walls[i]);
	}
	free(t->walls);
}

int	quit(t_data *dt)
{
	if (dt->img_exists)
		mlx_destroy_image(dt->mlx, dt->img.img);
	mlx_destroy_window(dt->mlx, dt->win);
	mlx_destroy_display(dt->mlx);
	free(dt->mlx);
	if (dt->maps.map_malloc)
		free_map(dt);
	free(dt->tx.wall_path[0]);
	free(dt->tx.wall_path[1]);
	free(dt->tx.wall_path[2]);
	free(dt->tx.wall_path[3]);
	free(dt->tx.floor_color);
	free(dt->tx.ceil_color);
	free_walls(&dt->tx);
	if (dt->dpy)
		XCloseDisplay(dt->dpy);
	destroy_sdl(&dt->sd);
	exit(0);
	return (0);
}
