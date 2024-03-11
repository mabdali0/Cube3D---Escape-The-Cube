CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror

CMAKE = cmake

SRC_DIR		:=	srcs
BUILD_DIR	:=	build
INCLUDES	:=	-I./includes
INC_SDL		:=	-ISDL2/build/include/SDL2/ -ISDL2/build/include-config-/SDL2

MLXFLAGS	:=	-lmlx -lX11 -lXext -lm -lz -pthread -lSDL2 -LSDL2/build -ldl -no-pie
MLXINC		:=	-L../mlx_linux -I../mlx_linux

NAME		:=	cube3d

SRCS		=	main.c			\
				ai_moving.c		\
				ai2.c			\
				ai3.c			\
				args.c			\
				audio.c			\
				audio_sdl.c		\
				cat_text.c		\
				colors.c		\
				colors_manip.c	\
				doors.c			\
				damages.c		\
				drawing.c		\
				drawing_lines.c	\
				drawing_elements.c	\
				draw_weapon.c	\
				draw_weap_utils.c	\
				draw_weap_chain.c	\
				draw_ui.c		\
				draw_ui2.c		\
				draw_ui3.c		\
				draw_txt.c		\
				draw_txt2.c		\
				exit.c			\
				ft_split.c		\
				game_steps.c	\
				get_next_line.c	\
				get_next_line_utils.c	\
				init.c			\
				init2.c			\
				init_sprites.c	\
				init_sprites2.c	\
				keys.c			\
				libft1.c		\
				load_textures.c	\
				map_reading.c	\
				map_read_params.c	\
				map_utils.c		\
				map_utils_2.c	\
				map_tester.c	\
				map_testerutils.c	\
				mouse.c			\
				moving.c		\
				moving_utils.c	\
				raycasting.c	\
				rays_casts.c	\
				rays_utils.c	\
				ray_draw_walls.c	\
				ray_draw_walls2.c	\
				rays_mobs.c		\
				scenario_init.c	\
				scenario_transitions.c	\
				sprites.c		\
				sprites_calculs.c	\
				sprites_order.c	\
				sprites_update.c	\
				start_screen.c	\
				start_screen_items.c	\
				triggers.c

OBJS := $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRCS))

cube: cubetxt $(BUILD_DIR) $(NAME)

$(NAME): $(OBJS) ./includes/cube3d.h
	@echo "Mixing everything together: "$@
	@$(CC) $(CFLAGS) $^ -o $@ $(MLXINC) $(MLXFLAGS) $(INCLUDES) $(INC_SDL)
	@echo CUBE 3D READY

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c ./includes/cube3d.h
	@echo Building: $@
	@$(CC) $(CFLAGS) -c $< -o $@ -O3 $(INCLUDES) $(INC_SDL)

$(BUILD_DIR):
	@echo Create build folder
	@mkdir -p $(BUILD_DIR)

all: mlx SDL fclean cube
	@echo ALL GOOD !

clean:
	@echo Cleaning old objects
	@rm -rf $(BUILD_DIR)

fclean: clean
	@echo Removing outdated program
	@rm -rf $(NAME)

re: fclean cube

mlx:
	@echo "\n\n___________________________________"
	@echo "|                                 |"
	@echo "|              MLX                |"
	@echo "|                                 |"
	@echo "-----------------------------------\n"
	$(MAKE) -C ../mlx_linux

SDL:
	@echo "\n\n___________________________________"
	@echo "|                                 |"
	@echo "|              SDL                |"
	@echo "|                                 |"
	@echo "-----------------------------------\n"
	@echo Cleaning SDL build directory
	@rm -rf SDL2/build
	@echo Create SDL build directory
	@mkdir -p SDL2/build
	@echo cmake SDL
	@$(CMAKE) -S SDL2 -B SDL2/build
	@echo Make SDL
	@$(MAKE) -C SDL2/build

cubetxt:
	@echo "\n\n___________________________________"
	@echo "|                                 |"
	@echo "|            CUBE 3D              |"
	@echo "|                                 |"
	@echo "-----------------------------------\n"

.PHONY: all clean fclean re mlx SDL cube cubetxt
