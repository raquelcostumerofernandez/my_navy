##
## EPITECH PROJECT, 2023
## radar_mod
## File description:
## Makefile
##

SRC =	src/main.c\
		src/errors.c\
		src/maps.c\
		src/player1.c\
		src/player2.c\
		src/random_functions.c\
		src/transform_attack.c\
		src/translate_attack.c\
		src/receive_attack.c\
		src/my_map.c\
		src/touch_miss.c\

OBJ = $(SRC:.c=.o)

NAME =	libmy.a

SNAME =	my_navy

LDFLAGS = -I./include -L lib/my/ -lmy

# CFLAGS = -Wall -Werror -Wextra

all:	$(NAME) $(SNAME)

$(NAME):
	$(MAKE) -C lib/my/

$(SNAME): $(OBJ)
	gcc -g3 -o $(SNAME) $(SRC) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C lib/my/
	$(RM) lib/libmy.a lib/my/libmy.a
	clear

re: fclean all

unit_test:
	$(MAKE) unit_test -C tests

tests_run:
	$(MAKE) tests_run -C tests

.PHONY:	all clean fclean re unit_test tests_run
