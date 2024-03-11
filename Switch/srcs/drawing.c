/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_put_pixel(t_imgd *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_put_pixel_res(t_imgd *img, int x, int y, int color)
{
	char	*dst;
	int		i;
	int		j;

	i = -1;
	while (++i < DOWNSCALE)
	{
		j = -1;
		while (++j < DOWNSCALE)
		{
			dst = img->addr + (y * img->line_length + (i + x)
					* (img->bits_per_pixel / 8));
			*(unsigned int *)dst = color;
		}
	}
}

void	draw_square(t_imgd *img, t_draw *d)
{
	int	i;
	int	j;
	int	pixx;
	int	pixy;

	i = 0;
	while (i < d->size)
	{
		j = 0;
		while (j < d->size)
		{
			pixx = i + d->x - d->size / 2;
			pixy = j + d->y - d->size / 2;
			if (pixx >= 0 && pixx < WIN_WIDTH && pixy >= 0 && pixy < WIN_HEIGHT)
				ft_put_pixel(img, pixx, pixy, d->color);
			j++;
		}
		i++;
	}
}

void	draw_rect(t_imgd *img, t_draw *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->w)
	{
		j = 0;
		while (j < d->h)
		{
			if (d->x + i >= 0 && d->x + i < WIN_WIDTH && d->y
				+ j >= 0 && d->y + j < WIN_HEIGHT)
				ft_put_pixel(img, d->x + i, d->y + j, d->color);
			j++;
		}
		i++;
	}
}
