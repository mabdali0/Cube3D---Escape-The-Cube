/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static void	init_arrays(t_player *p, t_sprites *s, t_sprites_order *o)
{
	int	i;

	i = -1;
	while (++i < 30)
	{
		s->order[i] = -1;
		if (s->type[i] < 10)
			s->dist[i] = dist(p->px, p->py, s->x[i], s->y[i]);
		else
			s->dist[i] = 0;
	}
	o->i = -1;
	o->max = 0;
	o->indmax = 0;
	o->ind = 0;
}

void	order_sprites(t_data *dt, t_sprites *s)
{
	t_sprites_order	o;

	init_arrays(&dt->player, s, &o);
	while (++o.i < 30)
	{
		if (s->type[o.i] < 10)
		{
			o.j = -1;
			o.max = 0;
			while (++o.j < 30)
			{
				if (s->type[o.j] < 10)
				{
					if (s->dist[o.j] > o.max)
					{
						o.max = s->dist[o.j];
						o.indmax = o.j;
					}
				}
			}
			s->order[o.ind] = o.indmax;
			s->dist[o.indmax] = 0;
			o.ind++;
		}
	}
}
