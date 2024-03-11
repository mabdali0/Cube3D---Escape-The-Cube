/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_bzero_char(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = '0';
		i++;
	}
	*(char *)(s + i) = '\0';
}

void	init_player_pos_angle(t_data *dt, char c, int y, int x)
{
	dt->player.start_pos_x = x;
	dt->player.start_pos_y = y;
	if (c == 'N')
		dt->player.start_angle = P3;
	else if (c == 'E')
		dt->player.start_angle = 0;
	else if (c == 'S')
		dt->player.start_angle = P2;
	else if (c == 'W')
		dt->player.start_angle = PI;
}

void	add_new_door(t_maps *m, char c, int x, int y)
{
	m->doors_x[m->doors_count] = x;
	m->doors_y[m->doors_count] = y;
	if (c == 'D')
		m->doors_state[m->doors_count] = 1;
	else if (c == 'L')
		m->doors_state[m->doors_count] = 2;
	m->doors_count++;
	if (c == 'D')
		printf("# Door at %d, %d, %s\n", x, y, "opened");
	else
		printf("# Door at %d, %d, %s\n", x, y, "locked");
}

void	map_infos(t_data *dt, char c, int y, int x)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		init_player_pos_angle(dt, c, y, x);
	if (c == 'D' || c == 'L')
		add_new_door(&dt->maps, c, x, y);
}

int	get_map_size(t_data *dt, int map_line)
{
	char	*line;
	size_t	line_len;
	int		fd;

	fd = open_map_and_get_to_line(dt, map_line);
	dt->maps.h = 1;
	dt->maps.w = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_len = ft_strlen(line);
		if (line[line_len - 1] == '\n')
			line[line_len - 1] = '\0';
		if (line_len > dt->maps.w)
			dt->maps.w = line_len;
		dt->maps.h++;
		free(line);
		line = get_next_line(fd);
	}
	dt->maps.h--;
	close(fd);
	return (0);
}
