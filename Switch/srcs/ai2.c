/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

char	*itoa(int n)
{
	size_t	size;
	long	nb;
	char	*str;
	int		is_negative;

	size = count_size((long) n);
	str = (char *) malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	nb = (long) n;
	is_negative = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		str[0] = '-';
		is_negative = 1;
	}
	str[size] = '\0';
	while (size > (size_t) is_negative)
	{
		str[size - 1] = nb % 10 + '0';
		nb = nb / 10;
		size--;
	}
	return (str);
}

int	fill_no_wall(char **tab, t_point coord, int dep, t_point size)
{
	if (coord.x < 0 || coord.y < 0)
		return (0);
	if (coord.x > size.x || coord.y > size.y)
		return (0);
	if (tab[coord.x][coord.y] == '1')
		return (0);
	if (tab[coord.x][coord.y] == 'x')
		return (0);
	else if (tab[coord.x][coord.y] == '0')
	{
		tab[coord.x][coord.y] = dep;
		return (1);
	}
	else if (tab[coord.x][coord.y] <= dep && tab[coord.x][coord.y] != '0')
		return (0);
	else if (tab[coord.x][coord.y] > dep)
	{
		tab[coord.x][coord.y] = dep;
		return (1);
	}
	else
		return (0);
}

int	call_fill(char **tab, int i, int n, t_point size)
{
	int		res;
	t_point	coord;
	int		j;

	res = 0;
	j = -1;
	while (++j < size.y)
	{
		if (tab[i][j] <= n && tab[i][j] >= 'a')
		{
			coord.y = j;
			coord.x = i - 1;
			res += fill_no_wall(tab, coord, n + 1, size);
			coord.x = i + 1;
			res += fill_no_wall(tab, coord, n + 1, size);
			coord.x = i;
			coord.y = j - 1;
			res += fill_no_wall(tab, coord, n + 1, size);
			coord.y = j + 1;
			res += fill_no_wall(tab, coord, n + 1, size);
		}
	}
	return (res);
}

int	remplir(t_data *dt, char **tab, t_point size, int n)
{
	int	res;
	int	i;

	(void)dt;
	res = 0;
	i = -1;
	while (++i < size.x)
	{
		res += call_fill(tab, i, n, size);
	}
	return (res);
}

int	test_empty_case(t_data *dt, float x, float y, int id)
{
	int	i;

	i = -1;
	while (++i < 30)
	{
		if (dt->sp.type[i] == 2 && i != id)
		{
			if ((x <= dt->sp.destx[i] + 8 && x >= dt->sp.destx[i] - 8
					&& y <= dt->sp.desty[i] + 8 && y >= dt->sp.desty[i] - 8))
				return (0);
		}
	}
	return (1);
}
