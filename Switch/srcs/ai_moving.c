/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_moving.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include <stdlib.h>

void	alloc_and_copy(char **copie, char **source, int i)
{
	if (source[i] != NULL)
	{
		copie[i] = (char *)malloc(strlen(source[i]) + 1);
		if (copie[i] == NULL)
		{
			fprintf(stderr, "Erreur d'allocation mémoire\n");
			exit(1);
		}
		strcpy(copie[i], source[i]);
	}
	else
		copie[i] = NULL;
}

char	**copier_tableau_chaines(char **source, int taille)
{
	char	**copie;
	int		i;

	if (source == NULL || taille <= 0)
		return (NULL);
	copie = (char **)malloc((taille + 1) * sizeof(char *));
	if (copie == NULL)
	{
		fprintf(stderr, "Erreur d'allocation mémoire\n");
		exit(1);
	}
	i = -1;
	while (++i < taille)
		alloc_and_copy(copie, source, i);
	copie[taille] = NULL;
	return (copie);
}

void	find_dest(t_data *dt, t_sprites *s, t_maps *m, int i)
{
	int	case_x;
	int	case_y;

	case_x = (int)(s->x[i] / 15) + 1;
	case_y = (int)(s->y[i] / 15) + 1;
	if (m->ai[case_y - 1][case_x] < m->ai[case_y][case_x] && m->ai[case_y
		- 1][case_x] >= 'a' && test_empty_case(dt, case_x * 15.0, case_y
		* 15.0 - 22.0, i))
		s->desty[i] = case_y * 15.0 - 22.0;
	else if (m->ai[case_y + 1][case_x] < m->ai[case_y][case_x] && m->ai[case_y
		+ 1][case_x] >= 'a' && test_empty_case(dt, case_x * 15.0, case_y
		* 15.0 + 7.0, i))
		s->desty[i] = case_y * 15.0 + 7.0;
	else if (m->ai[case_y][case_x - 1] < m->ai[case_y][case_x]
		&& m->ai[case_y][case_x - 1] >= 'a' && test_empty_case(dt, case_x
		* 15.0 - 22.0, case_y * 15.0, i))
		s->destx[i] = case_x * 15.0 - 22.0;
	else if (m->ai[case_y][case_x + 1] < m->ai[case_y][case_x]
		&& m->ai[case_y][case_x + 1] >= 'a' && test_empty_case(dt, case_x
		* 15.0 + 7.0, case_y * 15.0, i))
		s->destx[i] = case_x * 15.0 + 7.0;
}

void	move_sprite(t_data *dt, int i)
{
	float	speed;
	int		decx;
	int		decy;

	decx = 1;
	decy = 1;
	speed = PLAYER_SPEED * (0.6 - (2 - dt->difficulty) * 0.1);
	if (dt->sp.x[i] < dt->sp.destx[i] && dt->maps.main[(int)(dt->sp.y[i] / 15)
		+ decy][(int)((dt->sp.x[i] + speed) / 15) + decx] == '0')
		dt->sp.x[i] += speed;
	if (dt->sp.x[i] > dt->sp.destx[i] && dt->maps.main[(int)(dt->sp.y[i] / 15)
		+ decy][(int)((dt->sp.x[i] - speed) / 15) + decx] == '0')
		dt->sp.x[i] -= speed;
	if (dt->sp.y[i] < dt->sp.desty[i] && dt->maps.main[(int)((dt->sp.y[i]
				+ speed) / 15) + decy][(int)(dt->sp.x[i] / 15) + decx] == '0')
		dt->sp.y[i] += speed;
	if (dt->sp.y[i] > dt->sp.desty[i] && dt->maps.main[(int)((dt->sp.y[i]
				- speed) / 15) + decy][(int)(dt->sp.x[i] / 15) + decx] == '0')
		dt->sp.y[i] -= speed;
}

void	manage_ai(t_data *dt)
{
	t_point	size;
	int		i;

	size.x = dt->maps.h;
	size.y = dt->maps.w;
	flood_map2(dt, dt->maps.main, size);
	i = 0;
	while (i < 30)
	{
		if ((dt->sp.type[i] == 2 || dt->sp.type[i] == 3) && dt->sp.active[i])
		{
			if (dt->maps.ai[(int)(dt->sp.y[i] / 15) + 1][(int)(dt->sp.x[i] / 15)
				+ 1] <= 'k' && dt->maps.ai[(int)(dt->sp.y[i] / 15)
				+ 1][(int)(dt->sp.x[i] / 15) + 1] >= 'a')
				find_dest(dt, &dt->sp, &dt->maps, i);
			move_sprite(dt, i);
		}
		i++;
	}
	free2d(dt->maps.ai);
	dt->maps.ai_malloc = 0;
}
