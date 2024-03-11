/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cube3d.h"

char	*cat_text_line1_bis(int ind)
{
	if (ind == 5)
		return ("Mais rappelle toi, jeune aventurier, que la vraie force");
	else if (ind == 6)
		return ("la defense, mais la veritable magie reside dans ta");
	else if (ind == 7)
		return ("Le chat magicien regarde le joueur \
avec une expression grave,");
	else if (ind == 8)
		return ("Je vais ouvrir plusieurs acces pour toi dans ce labyrinthe,");
	else if (ind == 9)
		return ("En te faisant avancer, j'ai \
involontairement libere des forces");
	else if (ind == 10)
		return ("Sois prudent, car chaque porte que tu ouvres peut avoir des");
	else if (ind == 11)
		return ("Ton destin est entre tes mains, aventurier, et les");
	return ("\0");
}

char	*cat_text_line1(int ind)
{
	if (ind == 0)
		return ("Ah, voyageur intrepide, bienvenue \
dans ce labyrinthe enigmatique,");
	else if (ind == 1)
		return ("Je suis le Gardien des Secrets, le Chat Magicien, et");
	else if (ind == 2)
		return ("Dans la partie nord de ce labyrinthe, le jardinier du parc,");
	else if (ind == 3)
		return ("derriere lui des outils qui pourraient te permettre de");
	else if (ind == 4)
		return ("Cherche bien, car ces outils \
pourraient etre la cle de ta survie");
	else if (ind > 4 && ind < 12)
		return (cat_text_line1_bis(ind));
	return ("\0");
}

char	*cat_text_line2_bis(int ind)
{
	if (ind == 5)
		return ("reside en toi. Les armes peuvent t'accorder le pouvoir de");
	else if (ind == 6)
		return ("determination, ta ruse et ton courage.");
	else if (ind == 7)
		return ("sachant que le joueur ne reviendra pas le voir...");
	else if (ind == 8)
		return ("cependant, je ne detiens pas la cle de la sortie.");
	else if (ind == 9)
		return ("malefiques qui errent maintenant \
dans les ombres de ce dedale.");
	else if (ind == 10)
		return ("consequences inattendues.");
	else if (ind == 11)
		return ("epreuves a venir seront plus redoutables que jamais...");
	return ("\0");
}

char	*cat_text_line2(int ind)
{
	if (ind == 0)
		return ("ou chaque pas peut te conduire \
vers la gloire ou la destruction.");
	else if (ind == 1)
		return ("je sens que tu as besoin d'aide dans cette quete perilleuse.");
	else if (ind == 2)
		return ("un homme discret et plein de sagesse, a peut etre laisse");
	else if (ind == 3)
		return ("te defendre contre les creatures malefiques qui rodent ici.");
	else if (ind == 4)
		return ("...");
	else if (ind > 4 && ind < 12)
		return (cat_text_line2_bis(ind));
	return ("\0");
}
