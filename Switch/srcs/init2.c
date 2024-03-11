/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static void	xfree_win(char *a, Window *b)
{
	XFree(a);
	XFree(b);
}

Window	*findchild(t_data *dt, Window p, char *name, Window *parent_win)
{
	t_xwindow	w;

	w.window_name = NULL;
	if (XQueryTree(dt->dpy, p, &dt->root_window, &w.pr, &w.children, &w.nc))
	{
		w.i = -1;
		while (++w.i < (int)w.nc)
		{
			XFetchName(dt->dpy, w.children[w.i], &w.window_name);
			if (w.window_name != NULL && strcmp(w.window_name, name) == 0)
			{
				XFree(w.window_name);
				*parent_win = p;
				return (&(w.children[w.i]));
			}
			w.found = findchild(dt, w.children[w.i], name, parent_win);
			if (w.found != None)
				xfree_win(w.window_name, w.children);
			if (w.found != None)
				return (w.found);
			XFree(w.window_name);
		}
		XFree(w.children);
	}
	return (None);
}

static void	center_win(t_data *dt, Window w)
{
	int	ret;

	ret = XMoveWindow(dt->dpy, w, dt->screen_w / 2 - WIN_WIDTH / 2,
			dt->screen_h / 2 - WIN_HEIGHT / 2);
	printf("Move window = %d\n", ret);
}

void	init_window(t_data *dt)
{
	t_xwindow		w;
	Window			*child_window;

	w.p = None;
	w.children = NULL;
	child_window = NULL;
	child_window = findchild(dt, dt->root_window,
			"Cube3D", &w.p);
	if (child_window != None)
	{
		printf("Parent window has XID 0x%lx\n", w.p);
		if (XQueryTree(dt->dpy, w.p, &dt->root_window,
				&(w.pr), &(w.children), &(w.nc)))
		{
			printf("Found child window with XID 0x%lx\n", w.children[0]);
			center_win(dt, w.children[0]);
			center_win(dt, w.p);
		}
		if (w.children)
			XFree(w.children);
		if (child_window)
			XFree(child_window);
	}
	XFlush(dt->dpy);
}
