/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_txt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../includes/alphabet.h"

void	ft_put_one_letter(t_data *dt, t_alphabet *al, int decx)
{
	int	pix;
	int	x;
	int	y;

	y = -1;
	while (++y < 26)
	{
		x = -1;
		while (++x < 20)
		{
			pix = (x + 20 * (y + 1)) * 3 + (20 * 27 * 3) * al->dec_array;
			dt->draw.color = trgb(0, courrier[pix],
					courrier[pix + 1], courrier[pix + 2]);
			if (dt->draw.color != 0x00FF00FF)
				ft_put_pixel(&dt->img, al->x + decx * 18 + x,
					al->y + y, dt->draw.color);
		}
	}
}

void	ft_put_text(t_data *dt, t_alphabet *al, int nb_char)
{
	int		i;

	i = -1;
	while (al->str[++i] && i < nb_char)
	{
		if (al->str[i] >= 'a' && al->str[i] <= 'z')
			al->dec_array = al->str[i] - 'a';
		else if (al->str[i] >= 'A' && al->str[i] <= 'Z')
			al->dec_array = al->str[i] - 'A' + 26;
		else if (al->str[i] == '\'')
			al->dec_array = 52;
		else if (al->str[i] == '.')
			al->dec_array = 53;
		else if (al->str[i] == ',')
			al->dec_array = 54;
		else if (al->str[i] == '!')
			al->dec_array = 55;
		else
			continue ;
		ft_put_one_letter(dt, al, i);
	}
}

static void	choose_cat_text(t_data *dt)
{
	dt->al.str = cat_text_line1(dt->sc.dialogue_step);
	if (dt->al.nb_char_l1 <= (int)ft_strlen(dt->al.str)
		&& dt->frame_nb % 1 == 0)
		dt->al.nb_char_l1++;
	dt->al.x = 40;
	dt->al.y = dt->draw.y + 17;
	ft_put_text(dt, &dt->al, dt->al.nb_char_l1);
	if (dt->al.nb_char_l1 >= (int)ft_strlen(dt->al.str))
	{
		dt->al.y += 35;
		dt->al.str = cat_text_line2(dt->sc.dialogue_step);
		if (dt->al.nb_char_l2 <= (int)ft_strlen(dt->al.str)
			&& dt->frame_nb % 1 == 0)
			dt->al.nb_char_l2++;
		ft_put_text(dt, &dt->al, dt->al.nb_char_l2);
		if (dt->al.nb_char_l2 >= (int)ft_strlen(dt->al.str))
		{
			dt->al.writting = 0;
			if (dt->sc.dialogue_step == 8)
				dt->sc.transition_state = 1;
		}
	}
}

void	ft_cat_speak(t_data *dt)
{
	if (dt->sc.dialogue_step >= 12)
	{
		dt->game_step = 2;
		dt->maps.doors_state[0] = 1;
		dt->maps.doors_state[4] = 1;
		printf("Doors 1 & 4 unlocked\n");
		return ;
	}
	draw_txt_back(dt);
	choose_cat_text(dt);
	if (dt->sc.transition_state == 1 && dt->sd.sound_playing == 0)
	{
		dt->sd.sound_playing = 1;
		play_audio(dt, 6);
	}
	if (dt->frame_nb / 25 % 2)
		draw_space_button(dt);
}
