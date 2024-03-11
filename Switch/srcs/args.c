/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static void	print_help(void)
{
	printf("\n******  CUBE 3D HELP ******\n\n");
	printf("Availlable commands :\n");
	printf("> easy		sets game difficulty to nooby mode\n");
	printf("> medium	sets game difficulty for bad players\n");
	printf("> show		show the mouse cursor (removes leaks)\n");
	printf("> god		disable damages.. you should really \
start questioning yourself if you need this..\n\n");
	printf("> diswin	disable window management \
(if game crashes at start)\n");
	exit(0);
}

static void	checks2(t_data *dt, char *arg)
{
	if (!strcmp(arg, "dev"))
		dt->dev = 1;
	if (!strcmp(arg, "show"))
		dt->mousehide = 0;
	if (!strcmp(arg, "god"))
		dt->god = 1;
	if (!strcmp(arg, "diswin"))
		dt->disable_xwin = 1;
}

void	check_args(t_data *dt, int argc, char **argv)
{
	int		i;

	dt->dev = 0;
	dt->mousehide = 1;
	dt->difficulty = 2;
	dt->god = 0;
	dt->disable_xwin = 0;
	if (argc > 1)
	{
		i = 0;
		while (++i < argc)
		{
			checks2(dt, argv[i]);
			if (!strcmp(argv[i], "easy"))
				dt->difficulty = 0;
			if (!strcmp(argv[i], "medium"))
				dt->difficulty = 1;
			if (!strcmp(argv[i], "help"))
				print_help();
		}
	}
}
