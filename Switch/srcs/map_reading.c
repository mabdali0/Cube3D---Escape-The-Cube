/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	open_map_and_get_to_line(t_data *dt, int map_line)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(dt->maps.path, O_RDONLY);
	if (fd < 1)
	{
		perror("Error: map file not found..");
		quit(dt);
	}
	i = -1;
	while (++i < map_line)
	{
		line = get_next_line(fd);
		free(line);
	}
	return (fd);
}

int	malloc_map(t_data *dt)
{
	size_t	i;

	dt->maps.main = (char **) malloc((dt->maps.h + 3) * sizeof(char *));
	if (!dt->maps.main)
		return (1);
	i = 0;
	while (i < dt->maps.h + 2)
	{
		dt->maps.main[i] = (char *) malloc((dt->maps.w + 3) * sizeof(char));
		if (!dt->maps.main[i])
			return (1);
		ft_bzero_char(dt->maps.main[i], dt->maps.w + 2);
		i++;
	}
	dt->maps.main[dt->maps.h + 2] = NULL;
	dt->maps.map_malloc = 1;
	return (0);
}

int	read_file(t_data *dt, int map_line)
{
	int		i;
	size_t	j;
	int		fd;
	char	*line;

	fd = open_map_and_get_to_line(dt, map_line);
	i = 0;
	line = get_next_line(fd);
	while (line && ++i)
	{
		j = -1;
		while (++j < dt->maps.w && line[j] != '\n')
		{
			if (ft_strchr("NESWDL", line[j]))
				map_infos(dt, line[j], i, j);
			dt->maps.main[i][j + 1] = line[j];
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}

int	comtinue_loading_map(t_data *dt, int map_line)
{
	if (malloc_map(dt) != 0)
	{
		printf("### MALLOC ERROR ###\n");
		quit(dt);
	}
	read_file(dt, map_line);
	printf("END READING MAP\n\n");
	printf(">> CHECKING MAP..\n");
	if (is_valid_map(dt->maps.main, dt->maps.h) != 0)
		exit (0);
	if (check_map_is_closed(dt, dt->maps.main, 0) != 0)
	{
		printf("Error: map is not closed.\n");
		exit(0);
	}
	printf("...OK !\n\n");
	return (0);
}

int	load_map(t_data *dt)
{
	int	fd;
	int	map_line;

	printf("# Loading map > %s\n", dt->maps.path);
	fd = open_map_and_get_to_line(dt, 0);
	map_line = read_params(dt, fd);
	close(fd);
	if (map_line == -1)
	{
		perror("ERROR: Missing or incorrect params in map file");
		quit(dt);
	}
	printf("Map start line: %d\n", map_line);
	dt->err = get_map_size(dt, map_line);
	if (dt->err)
	{
		printf("ERROR MAP > %d\n", dt->err);
		quit(dt);
	}
	comtinue_loading_map(dt, map_line);
	return (0);
}
