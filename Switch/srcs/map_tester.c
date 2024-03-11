/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	fill(char **tab, t_flood f, int *err)
{
	if (f.row < 0 || f.col < 0 || f.row >= f.size.y + 2
		|| f.col >= f.size.x + 2)
		return ;
	if (tab[f.row][f.col] == '#')
	{
		*err = 1;
		return ;
	}
	if (tab[f.row][f.col] == '@' || !ft_strchr("0NSEWDL ", tab[f.row][f.col]))
		return ;
	tab[f.row][f.col] = '@';
	f.row = f.row - 1;
	fill(tab, f, err);
	f.row = f.row + 2;
	fill(tab, f, err);
	f.row = f.row - 1;
	f.col = f.col - 1;
	fill(tab, f, err);
	f.col = f.col + 2;
	fill(tab, f, err);
}

int	flood_map(char **tab, t_point size, t_point begin)
{
	int		err;
	t_flood	f;

	err = 0;
	f.col = begin.x;
	f.row = begin.y;
	f.size = size;
	fill(tab, f, &err);
	if (err == 1)
		return (1);
	else
		return (0);
}

int	is_valid_map(char **map, int rows)
{
	char	*line;
	int		nb_player;

	nb_player = 0;
	while (rows--)
	{
		line = *map++;
		while (*line)
		{
			if (!ft_strchr(" 0123456789NSEWDLF", *line))
				return (printf("Error: SYMBOL: %c at row %d\n\n", *line, rows));
			if (*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
				nb_player++;
			if (*line == 'N' || *line == 'S' || *line == 'E'
				|| *line == 'W' || *line == ' ')
				*line = '0';
			if (*line == 'D' || *line == 'L')
				*line = '5';
			line++;
		}
	}
	if (nb_player != 1)
		return (printf("Error: None or more than one entry point detected\n"));
	return (0);
}

char	**remap(char **map, int i, int j, int k)
{
	char	**newmap;
	int		width;
	int		height;

	height = heightofmap(map);
	width = widthofmap(map, height);
	newmap = malloc(sizeof(char *) * (height + 3));
	while (i < height + 2)
		newmap[i++] = malloc((width + 3));
	newmap[i] = NULL;
	i = 0;
	while (j < width + 2)
		newmap[i][j++] = '#';
	newmap[i][j] = '\0';
	j = 0;
	i++;
	joinmap(map, newmap, &i, &k);
	while (j < width + 2)
		newmap[i][j++] = '#';
	newmap[i][j] = '\0';
	newmap[i + 1] = NULL;
	return (newmap);
}

int	check_map_is_closed(t_data *dt, char **map, int err)
{
	char	**newmap;
	int		height;
	int		width;
	t_point	size;
	t_point	begin;

	newmap = remap(map, 0, 0, 0);
	height = heightofmap(newmap);
	width = widthofmap(newmap, height);
	begin.x = dt->player.start_pos_x + 2;
	begin.y = dt->player.start_pos_y + 1;
	size.x = width;
	size.y = height;
	err = flood_map(newmap, size, begin);
	free2d(newmap);
	begin.x = 12;
	begin.y = 17;
	size.x = dt->maps.h;
	size.y = dt->maps.w;
	if (err == 1)
		return (1);
	return (0);
}
