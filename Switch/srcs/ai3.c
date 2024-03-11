/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	count_size(long nb)
{
	size_t	size;

	size = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		size = 1;
	}
	if (nb == 0)
		size = 1;
	else
	{
		while (nb)
		{
			nb = nb / 10;
			size++;
		}
	}
	return (size);
}

void	flood_map2(t_data *dt, char **tab, t_point size)
{
	char	**tab2;
	int		test;
	int		n;

	n = 97;
	test = 1;
	tab2 = copier_tableau_chaines(tab, size.x + 2);
	dt->maps.ai_malloc = 1;
	tab2[(int)(dt->player.py / 15) + 1][(int)(dt->player.px / 15) + 1] = 'a';
	while (test && n <= 121)
	{
		test = remplir(dt, tab2, size, n);
		n++;
	}
	dt->maps.ai = tab2;
}
