/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	set_sprites_pos(t_sprites *sp)
{
	sp->x[0] = 37.0;
	sp->y[0] = 260.0;
	sp->x[1] = 347.0;
	sp->y[1] = 81.0;
	sp->x[2] = 321.0;
	sp->y[2] = 58.0;
	sp->x[3] = 471.0;
	sp->y[3] = 115.0;
	sp->x[4] = 467.0;
	sp->y[4] = 28.0;
	sp->x[5] = 425.0;
	sp->y[5] = 292.0;
	sp->x[6] = 474.0;
	sp->y[6] = 352.0;
	sp->x[7] = 380.0;
	sp->y[7] = 324.0;
	sp->x[8] = 309.0;
	sp->y[8] = 380.0;
	sp->x[9] = 307.0;
	sp->y[9] = 217.0;
	sp->x[10] = 215.0;
	sp->y[10] = 295.0;
	sp->x[11] = 280.0;
	sp->y[11] = 295.0;
}

void	set_sprites_pos2(t_sprites *sp)
{
	sp->x[12] = 280.0;
	sp->y[12] = 320.0;
	sp->x[13] = 200.0;
	sp->y[13] = 384.0;
	sp->x[14] = 201.0;
	sp->y[14] = 319.0;
	sp->x[15] = 31.0;
	sp->y[15] = 373.0;
	sp->x[16] = 173.0;
	sp->y[16] = 127.0;
	sp->x[17] = 412.0;
	sp->y[17] = 320.0;
	sp->x[18] = 386.0;
	sp->y[18] = 39.5;
	sp->x[19] = 411.0;
	sp->y[19] = 263.0;
	sp->x[20] = 443.0;
	sp->y[20] = 382.0;
	sp->x[21] = 283.0;
	sp->y[21] = 384.0;
	sp->x[22] = 412.0;
	sp->y[22] = 69.0;
	sp->x[23] = 307.0;
	sp->y[23] = 334.0;
}

void	set_sprites_type(t_sprites *sp)
{
	int	i;

	i = 0;
	while (++i < 15)
		sp->type[i] = 2;
	sp->type[0] = 1;
	sp->type[15] = 3;
	sp->type[16] = 4;
	sp->type[17] = 5;
	sp->type[18] = 6;
	sp->type[19] = 6;
	sp->type[20] = 6;
	sp->type[21] = 6;
	sp->type[22] = 7;
	sp->type[23] = 7;
	sp->type[24] = 7;
	sp->type[25] = 100;
	sp->type[26] = 100;
	sp->type[27] = 9;
	sp->type[28] = 11;
	sp->type[29] = 10;
	sp->x[24] = 174.0;
	sp->y[24] = 334.0;
	sp->x[27] = 37.0;
	sp->y[27] = 309.0;
}

// ****** TYPES *******
// 0: None
// 1: Cat
// 2: Ennemy
// 3: Boss
// 4: Weapon
// 5: Key
// 6: Health
// 7: Ammo
// 10: UI Hands
// 11: UI Chainsaw
// 9 STARGATE

void	init_sprites(t_sprites *sp)
{
	int	i;

	i = -1;
	while (++i < 30)
	{
		sp->states[i] = 0;
		sp->type[i] = 0;
		sp->life[i] = 100;
		sp->damaged[i] = 0;
		sp->active[i] = 0;
	}
	sp->life[15] = 300;
	set_sprites_type(sp);
	set_sprites_pos(sp);
	set_sprites_pos2(sp);
	set_sprites_params(sp, -1);
	i = -1;
	while (++i < 30)
	{
		if (sp->type[i] == 2 || sp->type[i] == 3)
		{
			sp->destx[i] = sp->x[i];
			sp->desty[i] = sp->y[i];
		}
	}
}

// POS
// Health:
// 386 39.5
// 411 263
// 443 382
// 283 384
//
// Ammos:
// 412 69
// 307 334
// 174 334
// Tronco: 173 127
// enn1: 347 81
// enn2: 321 58
// enn3: 471 115
// enn4: 467 28
// enn5: 425 292
// enn6: 474 352
// enn7: 380 324
// enn8: 309 380
// enn9: 307 217
// enn10: 215 295
// enn11: 280 295
// enn12: 280 320
// enn13: 200 384
// enn14: 201 319
// boss15: 31 373
// key: 412 320
