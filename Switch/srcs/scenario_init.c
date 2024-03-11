/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenario_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static void	init_transition_timing(t_scenario *sc)
{
	sc->transition_timing[0] = 100;
	sc->transition_timing[1] = 900;
	sc->transition_timing[2] = 100;
	sc->transition_timing[3] = 600;
	sc->transition_timing[4] = 100;
	sc->transition_timing[5] = 400;
	sc->transition_timing[6] = 100;
	sc->transition_timing[7] = 200;
	sc->transition_timing[8] = 100;
	sc->transition_timing[9] = 100;
	sc->transition_timing[10] = 50;
	sc->transition_timing[11] = 50;
	sc->transition_timing[12] = 50;
	sc->transition_timing[13] = 50;
	sc->transition_timing[14] = 20;
	sc->transition_timing[15] = 20;
	sc->transition_timing[16] = 10;
	sc->transition_timing[17] = 10;
	sc->transition_timing[18] = 10;
	sc->transition_timing[19] = 10;
}

void	init_scenario(t_data *dt, t_scenario *sc)
{
	sc->dialogue_step = 0;
	sc->last_state_space = 0;
	dt->al.nb_char_l1 = 0;
	dt->al.nb_char_l2 = 0;
	dt->al.writting = 0;
	sc->transition_step = 0;
	sc->transition_state = 0;
	sc->transition_start = 0;
	init_transition_timing(sc);
}

/*
Ah, voyageur intrepide, bienvenue dans ce labyrinthe enigmatique,
ou chaque pas peut te conduire vers la gloire ou la destruction.


Je suis le Gardien des Secrets, le Chat Magicien, et
je sens que tu as besoin d'aide dans cette quete perilleuse.


Dans la partie nord de ce labyrinthe, le jardinier du parc,
un homme discret et plein de sagesse, a peut etre laisse
derriere lui des outils qui pourraient te permettre de
te defendre contre les creatures malefiques qui rodent ici.

Cherche bien, car ces outils pourraient etre la cle de ta survie.


Mais rappelle toi, jeune aventurier, que la vraie force
reside en toi. Les armes peuvent t'accorder le pouvoir de
la defense, mais la veritable magie reside dans ta
determination, ta ruse et ton courage.

N'oublie jamais cela pendant ton periple a travers ce labyrinthe.

Le chat magicien regarde le joueur avec une expression grave,
sachant que le joueur ne reviendra pas le voir

Cependant, sache que je vais ouvrir plusieurs acces pour
toi dans ce labyrinthe, mais je ne detiens pas la cle de la sortie.
En te faisant avancer, j'ai involontairement libere des forces
malefiques qui errent maintenant dans les ombres de ce dedale.

Sois prudent, car chaque porte que tu ouvres peut avoir des
consequences inattendues.
Ton destin est entre tes mains, aventurier, et les
epreuves a venir seront plus redoutables que jamais.
*/
