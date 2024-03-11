/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../includes/cube3d.h"

typedef struct s_xwindow
{
	Window			pr;
	Window			p;
	Window			*children;
	Window			*found;
	unsigned int	nc;
	int				i;
	char			*window_name;
}				t_xwindow;

typedef struct s_sounds
{
	SDL_AudioSpec		audiospec;
	SDL_AudioDeviceID	audiodevice;
	SDL_AudioSpec		loadedaudiospec;
	Uint8				*audiodata[20];
	Uint32				audiolenght[20];
	int					chainsaw_state;
	int					sound_playing;
}				t_sounds;

typedef struct s_mouse
{
	int				rootx;
	int				rooty;
	int				winx;
	int				winy;
	unsigned int	mask;
	Window			child_window;
}				t_mouse;

typedef struct s_imgd
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_imgd;

typedef struct s_alphabet
{
	int		x;
	int		y;
	char	*str;
	int		dec_array;
	int		nb_char_l1;
	int		nb_char_l2;
	int		writting;
}				t_alphabet;

typedef struct s_move
{
	int	ipx;
	int	ipy;
	int	new_ipx;
	int	new_ipy;
}				t_move;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_flood
{
	t_point	size;
	int		row;
	int		col;
}				t_flood;

typedef struct s_linedraw
{
	int		steps;
	float	xinc;
	float	yinc;
	float	x;
	float	y;
	int		j;
	int		i;
}				t_linedraw;

typedef struct s_text_load
{
	int	fd;
	int	i;
	int	size;
}				t_text_load;

typedef struct s_player
{
	float	px;
	float	py;
	float	pdx;
	float	pdy;
	float	pa;
	float	vangle;
	float	next_px;
	float	next_py;
	int		start_pos_x;
	int		start_pos_y;
	float	start_angle;
	int		k_up;
	int		k_down;
	int		k_left;
	int		k_right;
	int		k_lstep;
	int		k_rstep;
	float	speed;
	int		life;
	int		moving;
	int		cur_weapon;
	int		attack;
	int		damaged;
	int		ammo;
	int		run;
	int		blocked_dir[4];
}				t_player;

typedef struct s_draw
{
	float	x;
	float	y;
	int		w;
	int		h;
	float	startx;
	float	starty;
	float	endx;
	float	endy;
	int		size;
	int		color;
	int		line_width;
	int		shade;
}				t_draw;

typedef struct s_maps
{
	size_t	h;
	size_t	w;
	char	**main;
	char	*path;
	char	**ai;
	int		map_malloc;
	int		ai_malloc;
	char	*no_text;
	char	*so_text;
	char	*we_text;
	char	*ea_text;
	int		player_startx;
	int		player_starty;
	int		params[7];
	int		doors_count;
	int		doors_state[20];
	int		doors_x[20];
	int		doors_y[20];
}				t_maps;

typedef struct s_minimap
{
	int	w;
	int	h;
	int	s;
	int	sizebox;
	int	px;
	int	py;
	int	uisize;
	int	uix;
	int	uiy;
	int	uih;
}				t_minimap;

typedef struct s_sprites_order
{
	int		i;
	int		j;
	int		indmax;
	float	max;
	int		ind;

}				t_sprites_order;

typedef struct s_sprites
{
	float	x[30];
	float	y[30];
	int		states[30];
	int		type[30];
	int		w[30];
	int		h[30];
	int		sscale[30];
	int		life[30];
	int		damaged[30];
	float	destx[30];
	float	desty[30];
	int		active[30];
	int		order[30];
	float	dist[30];
	float	sx;
	float	sy;
	float	sz;
	float	cos;
	float	sin;
	float	a;
	float	b;
	int		scale;
	float	tx;
	float	ty;
	float	tx_step;
	float	ty_step;
	int		px;
	int		py;
	int		pix;
	int		**text;
	float	textw;
	float	texth;
}				t_sprites;

typedef struct s_textures
{
	int		nb_walls;
	int		nb_floors;
	int		nb_ceils;
	int		**walls;
	int		**floor;
	int		**ceil;
	int		size_walls[10];
	int		floor_size[10];
	int		ceil_size[10];
	char	*wall_path[10];
	char	*floor_path[10];
	char	*ceil_path[10];
	char	*floor_color;
	char	*ceil_color;
}				t_textures;

typedef struct s_ui
{
	clock_t		start_time;
	clock_t		spriteclock;
	int			sprite_face;
	int			key;
}				t_ui;

typedef struct s_weapons
{
	int	i;
	int	j;
	int	hand_w;
	int	hand_h;
	int	pix;
	int	lhandy;
	int	rhandy;
}				t_weapons;

typedef struct s_main_menu
{
	int		loading_bar_w;
	int		loading_bar_h;
	int		loading_bar_x;
	int		loading_bar_y;
	int		select;
	int		anim_state;
}				t_main_menu;

typedef struct s_triggers
{
	int		sb;
	int		trig_dist;
}				t_triggers;

typedef struct s_scenario
{
	int		dialogue_step;
	int		last_state_space;
	int		transition_timing[20];
	int		transition_step;
	int		transition_state;
	clock_t	transition_start;
}				t_scenario;

typedef struct s_raycast
{
	int		r;
	int		rmax;
	float	dr;
	int		mx;
	int		my;
	int		mp;
	int		dof;
	float	ca;
	float	rx;
	float	ry;
	float	hx;
	float	hy;
	float	vx;
	float	vy;
	float	ra;
	float	xo;
	float	yo;
	float	tx;
	float	ty;
	float	tx_step;
	float	ty_step;
	float	atan;
	float	ntan;
	int		lineh;
	float	disth;
	float	distv;
	float	dist;
	int		wtypeh;
	int		wtypev;
	int		wtype;
	int		worient;
	float	deg;
	float	rafix;
	int		depth[1280];
	int		night;
}				t_raycast;

typedef struct s_data
{
	double		elapsedtime;
	void		*mlx;
	void		*win;
	Display		*dpy;
	Window		root_window;
	Screen		*screen;
	int			screen_w;
	int			screen_h;
	t_main_menu	menu;
	t_imgd		img;
	t_player	player;
	t_raycast	rays;
	t_draw		draw;
	t_maps		maps;
	t_minimap	mima;
	t_sprites	sp;
	t_textures	tx;
	t_ui		ui;
	t_triggers	tr;
	t_scenario	sc;
	t_alphabet	al;
	t_sounds	sd;
	long long	frame_nb;
	int			img_exists;
	int			draw_color;
	int			wall_color;
	int			err;
	int			ui_h;
	int			win_h;
	float		var;
	float		var2;
	int			game_state;
	int			game_step;
	int			dev;
	int			mousehide;
	int			god;
	int			difficulty;
	int			disable_xwin;
}				t_data;

#endif
