/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

# include "../includes/cube3d.h"

//raycasting
void	draw_rays(t_data *dt);

//rays_utils
float	deg_to_rad(float deg);
float	rad_to_deg(float rad);
float	fixang(float a);
float	dist(float ax, float ay, float bx, float by);
int		floor_shade(t_data *dt, int y);

//rays_casts
void	horizontal_lines(t_data *dt, t_raycast *rc, t_player *p);
void	vertical_lines(t_data *dt, t_raycast *rc, t_player *p);

//ray_draw_walls
void	draw_wall(t_data *dt, t_draw *d, t_raycast *rc);

//ray_draw_walls2
void	put_wall_text(t_data *dt, t_raycast *rc, t_draw *d);

#endif
