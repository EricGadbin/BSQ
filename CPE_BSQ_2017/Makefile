##
## EPITECH PROJECT, 2018
## Project BSQ
## File description:
## Build BSQ binary.
##

MAIN_SRC	=	src/main.c

SRC	=	src/calc_algo.c\
		src/create_maps.c

UT_SRC	=	tests/main_test.c

OBJ	=	$(MAIN_SRC:.c=.o) $(SRC:.c=.o)

UT_OBJ	=	$(SRC:.c=.o) $(UT_SRC:.c=.o)

CFLAGS	=	-Werror -Wextra -W -Wall -I ./include/

LDFLAGS	=

NAME	=	bsq

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(UT_OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f units
	rm -f *.html
	find . -name "*.gcda" -type f -delete
	find . -name "*.gcno" -type f -delete

re: fclean all

test_run:	CFLAGS += --coverage

test_run:	$(UT_OBJ)
		$(CC) -o units $(UT_OBJ) $(LDFLAGS) -lcriterion --coverage
		./units

cov:	test_run
	gcovr -r . --html -o coverage.html --html-details -e ".*tests/.*"
