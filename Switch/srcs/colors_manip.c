/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	ft_add_shade(int col, int shade)
{
	if (shade > 100)
		shade = 100;
	if (shade <= 0)
		return (0);
	return (trgb(get_t(col), get_r(col) * shade / 100,
			get_g(col) * shade / 100, get_b(col) * shade / 100));
}
