/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <time.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <pthread.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include "../../mlx_linux/mlx.h"
# include "../../mlx_linux/mlx_int.h"
# include "../SDL2/build/include/SDL2/SDL.h"

# include "../includes/defines.h"
# include "../includes/structs.h"
# include "../includes/rays.h"

//args
void	check_args(t_data *dt, int argc, char **argv);

//init
void	init_mlx(t_data *dt);
void	init_values(t_data *dt);

//init2
void	init_window(t_data *dt);

//init_sprites
void	init_sprites(t_sprites *sp);

//init_sprites2
void	set_sprites_params(t_sprites *sp, int i);

//scenario_init
char	*cat_text_line1(int ind);
char	*cat_text_line2(int ind);
void	init_scenario(t_data *dt, t_scenario *sc);

//scenario_transition
void	transition_update(t_data *dt, t_scenario *sc);

//ai_moving
void	manage_ai(t_data *dt);
char	**copier_tableau_chaines(char **source, int taille);

//ai2
int		test_empty_case(t_data *dt, float x, float y, int id);
int		min(int a, int b);
int		remplir(t_data *dt, char **tab, t_point size, int n);
int		fill_no_wall(char **tab, t_point coord, int dep, t_point size);
char	*itoa(int n);

//ai3
size_t	count_size(long nb);
void	flood_map2(t_data *dt, char **tab, t_point size);

//audio
void	play_audio(t_data *dt, int id);
void	manage_sounds(t_data *dt);

//audio_sdl
void	init_sdl(t_sounds *s);
void	destroy_sdl(t_sounds *s);

//game_steps
void	manage_game_steps(t_data *dt);

//start_screen
void	loading_scren(t_data *dt);
void	update_loading(t_data *dt, t_main_menu *mm, int loading);
void	main_menu(t_data *dt);
void	you_died(t_data *dt);
void	you_win(t_data *dt);

//start_screen_items
void	ft_draw_backgound(t_data *dt);
void	ft_draw_menu(t_data *dt, int *pic);
void	ft_draw_menu_kitty(t_data *dt);

//map_reading
int		load_map(t_data *dt);
int		open_map_and_get_to_line(t_data *dt, int map_line);

//map_read_params
int		read_params(t_data *dt, int fd);

//map_utils
void	ft_bzero_char(void *s, size_t n);
void	map_infos(t_data *dt, char c, int y, int x);
int		get_map_size(t_data *dt, int map_line);
void	init_player_pos_angle(t_data *dt, char c, int y, int x);

//map_utils_2
char	*ft_get_text_path(char *str);

//map_tester
int		check_map_is_closed(t_data *dt, char **map, int err);
int		heightofmap(char **map);
int		widthofmap(char **map, int height);
void	free2d(char **tab);
int		is_valid_map(char **map, int rows);
void	joinmap(char **map, char **newmap, int *i, int *k);

//exit
int		quit(t_data *dt);

//move_AI
char	*itoa(int n);
void	fill2(char **tab, t_flood f, int *err, int dep);
void	flood_map2(t_data *dt, char **tab, t_point size);

//rays_mobs
void	rays_mobs(t_data *dt);

// colors
int		trgb(unsigned int t, unsigned int r, unsigned int g, unsigned int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

//colors_manip
int		ft_add_shade(int col, int shade);

//load_textures
int		load_textures(t_data *dt, t_textures *tx);

//draw_txt
void	ft_put_text(t_data *dt, t_alphabet *al, int nb_char);
void	ft_cat_speak(t_data *dt);

//draw_txt2
void	draw_txt_back(t_data *dt);
void	draw_space_button(t_data *dt);

//drawing
void	ft_put_pixel(t_imgd *data, int x, int y, int color);
void	draw_square(t_imgd *img, t_draw *d);
void	draw_line(t_imgd *img, t_draw *draw);
void	draw_rect(t_imgd *img, t_draw *d);
void	draw_v_line(t_imgd *img, t_draw *d);

void	ft_put_pixel_res(t_imgd *img, int x, int y, int color);

//drawing_elements
void	draw_map(t_data *dt, t_minimap *mi);
void	draw_player(t_data *dt);

//draw_weapon
void	draw_weapon(t_data *dt, t_sprites *sp, t_draw *d);

//draw_weap_utils
void	is_player_moving(t_data *dt);
void	scale_pic(t_data *dt, t_draw *d, int scale);

//draw_weap_chain
void	draw_chainsaw_main(t_data *dt);

//draw_ui
void	draw_interface(t_data *dt, t_minimap *mi);

//draw_ui2
void	draw_minimap(t_data *dt, t_minimap *mi);
void	draw_image_ppm(t_data *dt, int w, int h, int *tab);

//draw_ui3
void	draw_key_fuel(t_data *dt, t_draw *d);

//keys
int		deal_key(int key, t_data *dt);
int		reset_key(int key, t_data *dt);

//mouse
void	manage_mouse(t_data *dt);
int		mouse_button_press(int button, int x, int y, t_data *dt);
int		mouse_button_released(int button, int x, int y, t_data *dt);

//moving
void	do_moves(t_data *dt, t_player *p);

//rays_mobs
void	rays_mobs(t_data *dt);

//moving_utils
void	fix_player_pos(t_player *p);
void	get_player_rot(t_player *p);
float	get_new_dir(t_player *p);

//doors
void	check_door(t_data *dt);

//sprites
void	draw_sprites(t_data *dt, t_sprites *s, t_draw *d);

//sprites_calculs
void	select_sprite_type(t_sprites *s, int id);
void	sets_init_values(t_data *dt, t_sprites *s, int id);

//sprites_order
void	order_sprites(t_data *dt, t_sprites *s);

//sprites_update
void	update_sprites(t_data *dt);

//damages
void	show_damages(t_data *dt);

//triggers
void	check_triggers(t_data *dt, t_player *p, t_sprites *s);
void	init_triggers(t_data *dt);

//get_next_line
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t nb, size_t size);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);

//libft1
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_strstr(const char *str, const char *to_find);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *str);

char	**ft_split(char const *s, char c);

#endif
