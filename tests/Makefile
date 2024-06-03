##
## EPITECH PROJECT, 2023
## makefile
## File description:
## qwerfh
##

SRC =	../src/player1.c\
		../src/player2.c\
		../src/maps.c\
		../src/random_functions.c\
		../src/receive_attack.c\
		../src/transform_attack.c\
		../src/translate_attack.c\
		../src/my_map.c\
		../src/errors.c\

SNAME =	unit_tests

SRC2 = secured_tests.c

LDFLAGS = -I./include -L ../lib/my/ -lmy

TESTFLAGS = --coverage -lcriterion

unit_test:
	$(CC) -o $(SNAME) $(SRC) $(SRC2) $(TESTFLAGS) $(LDFLAGS)

tests_run:	unit_test
	./unit_tests
	gcovr -r ../ --exclude $(SRC2) --exclude ../src/main.c
	$(RM) $(SNAME)
	$(RM) *.gcno *.gcda

.PHONY: all clean fclean re unit_test tests_run
