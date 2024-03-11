/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_casts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	horizontal_dir(t_data *dt, t_raycast *rc, t_player *p)
{
	rc->hx = p->px;
	rc->hy = p->py;
	rc->atan = -1 / tan(rc->ra);
	rc->disth = 10000000;
	if (rc->ra > PI)
	{
		rc->ry = (int)p->py / dt->mima.sizebox * dt->mima.sizebox - 0.0001;
		rc->rx = (p->py - rc->ry) * rc->atan + p->px;
		rc->yo = -dt->mima.sizebox;
		rc->xo = -rc->yo * rc->atan;
	}
	if (rc->ra < PI)
	{
		rc->ry = (int)p->py / dt->mima.sizebox
			* dt->mima.sizebox + dt->mima.sizebox;
		rc->rx = (p->py - rc->ry) * rc->atan + p->px;
		rc->yo = dt->mima.sizebox;
		rc->xo = -rc->yo * rc->atan;
	}
	if (rc->ra == 0 || rc->ra == PI)
	{
		rc->rx = p->px;
		rc->ry = p->py;
		rc->dof = 15;
	}
}

void	horizontal_lines(t_data *dt, t_raycast *rc, t_player *p)
{
	rc->dof = 0;
	horizontal_dir(dt, rc, p);
	while (rc->dof < 15)
	{
		rc->mx = (int)rc->rx / dt->mima.sizebox;
		rc->my = (int)rc->ry / dt->mima.sizebox;
		rc->mp = rc->my * dt->maps.w + rc->mx;
		if (rc->my < 0 || rc->mx < 0 || rc->my > (int)dt->maps.h
			|| rc->mx > (int)dt->maps.w)
			rc->dof = 15;
		else if (dt->maps.main[rc->my + 1][rc->mx + 1] != '0')
		{
			rc->wtypeh = dt->maps.main[rc->my + 1][rc->mx + 1] - '0';
			rc->dof = 15;
			rc->hx = rc->rx;
			rc->hy = rc->ry;
			rc->disth = dist(p->px, p->py, rc->rx, rc->ry);
		}
		else
		{
			rc->rx += rc->xo;
			rc->ry += rc->yo;
			rc->dof += 1;
		}
	}
}

void	vertical_dir(t_data *dt, t_raycast *rc, t_player *p)
{
	rc->vx = p->px;
	rc->vy = p->py;
	rc->ntan = -tan(rc->ra);
	rc->distv = 10000000.0;
	if (rc->ra > P2 && rc->ra < P3)
	{
		rc->rx = (int)p->px / dt->mima.sizebox * dt->mima.sizebox - 0.0001;
		rc->ry = (p->px - rc->rx) * rc->ntan + p->py;
		rc->xo = -dt->mima.sizebox;
		rc->yo = -rc->xo * rc->ntan;
	}
	if (rc->ra < P2 || rc->ra > P3)
	{
		rc->rx = (int)p->px / dt->mima.sizebox
			* dt->mima.sizebox + dt->mima.sizebox;
		rc->ry = (p->px - rc->rx) * rc->ntan + p->py;
		rc->xo = dt->mima.sizebox;
		rc->yo = -rc->xo * rc->ntan;
	}
	if (rc->ra == P2 || rc->ra == P3)
	{
		rc->rx = p->px;
		rc->ry = p->py;
		rc->dof = 15;
	}
}

void	vertical_lines(t_data *dt, t_raycast *rc, t_player *p)
{
	rc->dof = 0;
	vertical_dir(dt, rc, p);
	while (rc->dof < 15)
	{
		rc->mx = (int)rc->rx / dt->mima.sizebox;
		rc->my = (int)rc->ry / dt->mima.sizebox;
		rc->mp = rc->my * dt->maps.w + rc->mx;
		if (rc->my < 0 || rc->mx < 0 || rc->my > (int)dt->maps.h
			|| rc->mx > (int)dt->maps.w)
			rc->dof = 15;
		else if (dt->maps.main[rc->my + 1][rc->mx + 1] != '0')
		{
			rc->wtypev = dt->maps.main[rc->my + 1][rc->mx + 1] - '0';
			rc->dof = 15;
			rc->vx = rc->rx;
			rc->vy = rc->ry;
			rc->distv = dist(p->px, p->py, rc->rx, rc->ry);
		}
		else
		{
			rc->rx += rc->xo;
			rc->ry += rc->yo;
			rc->dof += 1;
		}
	}
}
