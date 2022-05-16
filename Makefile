##
## EPITECH PROJECT, 2021
## libmy Makefile
## File description:
## Makefile to build libmy.a
##

override CFLAGS += -fno-builtin -W -Wall -Wextra\
-Wno-discarded-qualifiers -Wno-ignored-qualifiers -Wno-missing-braces
override CPPFLAGS += -Iinclude -llist -lmy -lprinterr -lprintf\
-Llib -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

SRC	=	src/hud/components/buttons/utils/get_button.c	\
		src/hud/parser/components/button/big_values.c	\
		src/hud/parser/components/view/big_values.c	\
		src/hud/components/buttons/set/pos_size.c	\
		src/hud/parser/components/button/values.c	\
		src/hud/components/buttons/init/struct.c	\
		src/hud/components/buttons/render/draw.c	\
		src/hud/components/view/utils/get_view.c	\
		src/hud/parser/components/button/parse.c	\
		src/hud/components/buttons/set/border.c		\
		src/hud/parser/core/array_constructor.c		\
		src/hud/parser/components/view/values.c		\
		src/hud/components/view/set/pos_size.c		\
		src/hud/parser/utils/str_dup_from_to.c		\
		src/hud/parser/components/view/parse.c		\
		src/hud/components/view/init/struct.c		\
		src/hud/components/view/render/draw.c		\
		src/menus/actions/main_menus_action.c		\
		src/menus/actions/skill_tree_action.c		\
		src/draw/direction/spell_direction.c		\
		src/hud/components/view/set/border.c		\
		src/menus/actions/update_inventory.c		\
		src/menus/actions/inventory_action.c		\
		src/menus/actions/settings_actions.c		\
		src/draw/direction/boss_direction.c		\
		src/draw/animation/particle_anim.c		\
		src/hud/engine/utils/create_rect.c		\
		src/hud/parser/utils/check_elems.c		\
		src/hud/parser/utils/skip_balise.c		\
		src/menus/actions/slots_actions.c		\
		src/draw/animation/player_anim.c		\
		src/hud/engine/events/keyboard.c		\
		src/hud/engine/utils/draw_rect.c		\
		src/hud/parser/core/contructor.c		\
		src/menus/init/skill_tree_menu.c		\
		src/menus/actions/pause_action.c		\
		src/menus/actions/stats_action.c		\
		src/draw/animation/spell_anim.c			\
		src/draw/animation/sword_anim.c			\
		src/hud/parser/core/extractor.c			\
		src/draw/animation/boss_anim.c			\
		src/draw/animation/text_anim.c			\
		src/hud/engine/free/free_hud.c			\
		src/hud/parser/core/get_keys.c			\
		src/create/create_skill_tree.c			\
		src/draw/animation/npc_anim.c			\
		src/hud/engine/events/event.c			\
		src/hud/engine/events/click.c			\
		src/hud/engine/init/texture.c			\
		src/hud/engine/init/actions.c			\
		src/skill_tree/player_stats.c			\
		src/hud/engine/render/draw.c			\
		src/create/create_particle.c			\
		src/skill_tree/spell_stats.c			\
		src/draw/direction/player.c			\
		src/menus/init/pause_menu.c			\
		src/menus/init/stats_menu.c			\
		src/skill_tree/skill_tree.c			\
		src/hud/engine/init/text.c			\
		src/hud/engine/init/init.c			\
		src/menus/init/main_menu.c			\
		src/menus/init/inventory.c			\
		src/menus/init/dead_menu.c			\
		src/damage/player_damage.c			\
		src/create/create_player.c			\
		src/create/create_weapon.c			\
		src/menus/init/main_hud.c			\
		src/create/create_spell.c			\
		src/event/player_event.c			\
		src/damage/boss_damage.c			\
		src/create/create_boss.c			\
		src/create/create_list.c			\
		src/create/create_text.c			\
		src/music/create_music.c			\
		src/ending/player_died.c			\
		src/event/check_death.c				\
		src/event/spell_event.c				\
		src/create/create_all.c				\
		src/utils/nbr_to_str.c				\
		src/event/boss_fight.c				\
		src/event/hud_events.c				\
		src/event/text_event.c				\
		src/menus/init/init.c				\
		src/draw/draw_boss.c				\
		src/event/cutscene.c				\
		src/maps/collision.c				\
		src/draw/draw_npc.c				\
		src/menus/events.c				\
		src/check_errors.c				\
		src/event/game.c				\
		src/menus/draw.c				\
		src/menus/draw_main.c				\
		src/init/game.c					\
		src/free/game.c					\
		src/draw/game.c					\
		src/maps/maps.c					\
		src/draw/map.c					\
		src/maps/map.c					\
		src/rpg.c

OBJ = $(SRC:.c=.o)

TESTSRC = tests/test_make.c

MAINSRC = main.c

MAINOBJ = $(MAINSRC:.c=.o)

NAME = my_rpg

all: $(NAME)

$(NAME): $(OBJ) $(MAINOBJ)
				make  -C lib/list
				make  -C lib/my
				make  -C lib/printerr
				make  -C lib/printf
				gcc -o $(NAME) $(MAINOBJ) $(OBJ) $(CFLAGS) $(CPPFLAGS)

clean:
				rm -f $(OBJ) $(MAINOBJ)
				find . -type f -name '*.gcda' -delete
				find . -type f -name '*.gcno' -delete
				make clean -C lib/list
				make clean -C lib/my
				make clean -C lib/printerr
				make clean -C lib/printf


fclean: clean
				rm -f $(NAME)
				make fclean -C lib/list
				make fclean -C lib/my
				make fclean -C lib/printerr
				make fclean -C lib/printf

re: fclean all

tests_run:	CFLAGS += -lcriterion --coverage
tests_run: re $(TESTSRC)
				gcc -o unit_tests $(TESTSRC) $(SRC) $(CFLAGS) $(CPPFLAGS)
				./unit_tests

cover:
				gcovr --exclude tests
				gcovr --exclude tests --branches
				rm -f unit_tests*

debug: CFLAGS += -g
debug: CFLAGS:=$(filter-out -Wno-discarded-qualifiers,$(CFLAGS))
debug: CFLAGS:=$(filter-out -Wno-ignored-qualifiers,$(CFLAGS))
debug: CFLAGS:=$(filter-out -Wno-missing-braces,$(CFLAGS))
debug: re

fast:
				make -j

rfast:
				make fclean -j > /dev/null
				make -j > /dev/null

dfast:
				make fclean -j > /dev/null
				make debug -j > /dev/null


.PHONY: all re clean fclean tests_run cover fast rfast dfast debug
