/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_testerutils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	heightofmap(char **map)
{
	int	i;
	int	height;

	i = 0;
	height = 0;
	while (map[i++])
		height++;
	return (height);
}

int	widthofmap(char **map, int height)
{
	int	i;
	int	width;
	int	tmp_width;

	i = 0;
	width = 0;
	tmp_width = 0;
	while (i < height)
	{
		tmp_width = strlen(map[i]);
		if (tmp_width > width)
			width = tmp_width;
		i++;
	}
	return (width);
}

void	free2d(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	joinmap(char **map, char **newmap, int *i, int *k)
{
	int		height;
	char	*tmp;

	height = heightofmap(map);
	while (map[*k] && *k <= height + 1)
	{
		free(newmap[*i]);
		newmap[*i] = ft_strjoin("#", map[*k]);
		tmp = ft_strjoin(newmap[*i], "#");
		free(newmap[*i]);
		newmap[*i] = tmp;
		(*i)++;
		(*k)++;
	}
}
