/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	get_text_params(t_data *dt, int fd, int n)
{
	char	*line;
	char	**params;

	line = get_next_line(fd);
	free(line);
	line = get_next_line(fd);
	free(line);
	line = get_next_line(fd);
	params = ft_split(line, ' ');
	dt->tx.size_walls[n] = ft_atoi(params[0]);
	if (params[0])
		free(params[0]);
	if (params[1])
		free(params[1]);
	free(params);
	free(line);
	line = get_next_line(fd);
	free(line);
	printf("text %d size: %d\n", n, dt->tx.size_walls[n]);
}

int	load_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		printf("error: texture file '%s' not found\n", path);
	return (fd);
}

void	read_text_file3(t_data *dt, int **tb, t_text_load *tl)
{
	char	*line;
	int		i;
	int		max;

	i = 0;
	line = get_next_line(tl->fd);
	max = tl->size * tl->size * 3;
	while (i < max)
	{
		tb[tl->i][i] = ft_atoi(line);
		free(line);
		line = get_next_line(tl->fd);
		if (i % (max / 10) == 0 && i > 0)
			update_loading(dt, &dt->menu, 20 + tl->i * 20
				+ (int)((float)i / max * 10) *2);
		i++;
	}
}

int	load_textures(t_data *dt, t_textures *tx)
{
	t_text_load	tl;

	printf(">> LOADING TEXTURES\n");
	tl.i = -1;
	while (++tl.i < 4)
	{
		printf("Loading wall texture '%s' ...\n", tx->wall_path[tl.i]);
		tl.fd = load_file(tx->wall_path[tl.i]);
		if (tl.fd == -1)
			quit(dt);
		get_text_params(dt, tl.fd, tl.i);
		tx->walls[tl.i] = malloc(sizeof(int)
				* (tx->size_walls[tl.i] * tx->size_walls[tl.i] * 3));
		tl.size = tx->size_walls[tl.i];
		read_text_file3(dt, tx->walls, &tl);
		close(tl.fd);
		update_loading(dt, &dt->menu, 20 + (tl.i + 1) * 20);
		printf("...done !\n");
	}
	return (0);
}
