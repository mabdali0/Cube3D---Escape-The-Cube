/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static void	sort_param(t_textures *tx, char *line)
{
	if (ft_strstr(line, "NO"))
		tx->wall_path[0] = ft_get_text_path(line);
	else if (ft_strstr(line, "SO"))
		tx->wall_path[2] = ft_get_text_path(line);
	else if (ft_strstr(line, "WE"))
		tx->wall_path[3] = ft_get_text_path(line);
	else if (ft_strstr(line, "EA"))
		tx->wall_path[1] = ft_get_text_path(line);
	else if (line[0] == 'F')
		tx->floor_color = ft_get_text_path(line);
	else if (line[0] == 'C')
		tx->ceil_color = ft_get_text_path(line);
}

static int	verif_params(t_maps *m, char *line)
{
	if (ft_strstr(line, "NO") && !m->params[0])
		m->params[0] = 1;
	else if (ft_strstr(line, "SO") && !m->params[1])
		m->params[1] = 1;
	else if (ft_strstr(line, "WE") && !m->params[2])
		m->params[2] = 1;
	else if (ft_strstr(line, "EA") && !m->params[3])
		m->params[3] = 1;
	else if (line[0] == 'F' && !m->params[4])
		m->params[4] = 1;
	else if (line[0] == 'C' && !m->params[5])
		m->params[5] = 1;
	else if (line[0] != '\n')
		return (1);
	return (0);
}

int	count_params(t_maps *m)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (m->params[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	read_params(t_data *dt, int fd)
{
	char	*line;
	int		i;
	int		end_params;

	end_params = 0;
	i = -1;
	while (++i < 7)
		dt->maps.params[i] = 0;
	line = get_next_line(fd);
	i = 0;
	while (line && !end_params)
	{
		end_params = verif_params(&dt->maps, line);
		if (!end_params)
			sort_param(&dt->tx, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (line)
		free(line);
	i--;
	if (!count_params(&dt->maps))
		return (-1);
	return (i);
}
