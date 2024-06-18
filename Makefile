##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for the My RPG project
##

NAME	=	my_rpg

CC	=	gcc -lc_graph_prog

MAKE	=	/usr/bin/make

SRC_DIR	=	./srcs

CONFIG	=	./srcs/config_files

GAME	= 	./srcs/game

PATHFINDING= 	./srcs/pathfinding

MAP	= 		./srcs/map

EVENTS	= 		./srcs/engine/events

ACTIONS	= 		./srcs/engine/actions

STAGE	= 		./srcs/engine/stage

SOUND	=		./srcs/engine/sound

SAVE	=		./srcs/engine/save

PARTICLE= 	./srcs/particles


LIB_DIR	=	./lib/my

UT_DIR	=	./tests

LIB_DIR	=	./lib/my

EXE	=	$(ACTIONS)/engine_actions_handler_fight.c\
		$(ACTIONS)/engine_actions_handler_gui.c\
		$(ACTIONS)/engine_actions_handler_panel.c\
		$(ACTIONS)/engine_actions_handler.c\
		$(ACTIONS)/engine_actions_trackbar.c\
		$(ACTIONS)/engine_actions.c\
		$(ACTIONS)/menu_action.c\
		$(ACTIONS)/action_custom.c\
		$(ACTIONS)/engine_init_ptr_func.c\
		$(ACTIONS)/engine_quest.c\
		$(ACTIONS)/handle_obj_for_quest.c\
		$(EVENTS)/engine_events_handler_mouse.c\
		$(EVENTS)/engine_events_point.c\
		$(EVENTS)/engine_events_handler.c\
		$(EVENTS)/engine_events.c\
		$(SOUND)/engine_sound.c\
		$(SAVE)/engine_save.c\
		$(STAGE)/engine_stage_draw.c\
		$(STAGE)/engine_stage_handler.c\
		$(STAGE)/handle_item.c\
		$(STAGE)/check_change_map.c\
		$(SRC_DIR)/engine/engine.c\
		$(GAME)/init_game.c\
		$(GAME)/handle_quest.c\
		$(PARTICLE)/create_particles.c\
		$(PARTICLE)/update_particles.c\
		$(SRC_DIR)/handlers/handle_tempo_display.c\
		$(SRC_DIR)/handlers/handle_click_mov.c\
		$(SRC_DIR)/handlers/handle_mov_player.c\
		$(MAP)/init_tile_map.c\
		$(MAP)/map_loading.c\
		$(MAP)/map_creation.c\
		$(CONFIG)/animation.c\
		$(CONFIG)/init_size_animation.c\
		$(CONFIG)/change_map.c\
		$(CONFIG)/button.c\
		$(CONFIG)/sprite.c\
		$(CONFIG)/init.c\
		$(CONFIG)/init_size_memory.c\
		$(CONFIG)/order.c\
		$(CONFIG)/item.c\
		$(CONFIG)/bag.c\
		$(CONFIG)/text.c\
		$(CONFIG)/players.c\
		$(SRC_DIR)/get.c\
		$(SRC_DIR)/window.c\
		$(SRC_DIR)/protec_empty_env.c\
		$(SRC_DIR)/main.c\
		$(SRC_DIR)/utils.c\
		$(SRC_DIR)/draw.c\
		$(PATHFINDING)/pathfinding.c\
		$(PATHFINDING)/finder.c\
		$(PATHFINDING)/draw_path.c\
		$(PATHFINDING)/check_next_position.c\
		$(SRC_DIR)/sprite_scale.c\
		$(SRC_DIR)/load_file.c\
		$(SRC_DIR)/move_bot.c\
		$(SRC_DIR)/check_attack.c\
		$(SRC_DIR)/start_anim.c\

OBJ	=	$(EXE:.c=.o)

UT 	=

UT2	=

RM	=	rm -f

CFLAGS	=	#-Wall -Wextra

CPPFLAGS=	-I./includes/

LDFLAGS	=	-L./lib/ -lmy

UT_FLAGS=	-lcriterion --coverage

INCLUDE	=	-I ./includes


all:		LIB $(NAME)

LIB:
		$(MAKE) -C $(LIB_DIR)

$(NAME):	LIB $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

tests_run:	LIB
		$(CC) $(INCLUDE) -o $(NAME) $(UT) $(UT2) -lcriterion -coverage  -L./lib/ -lmy
		./$(NAME)

clean:
		$(MAKE) clean -C $(LIB_DIR)
		$(RM) $(OBJ)

ut_clean:
		rm *gc*

fclean:		clean
		$(MAKE) fclean -C $(LIB_DIR)
		$(RM) $(NAME)

re:		fclean all

.PHONY:		re all fclean clean
