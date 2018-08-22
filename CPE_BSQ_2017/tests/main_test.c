/*
** EPITECH PROJECT, 2017
** Project BSQ Testing
** File description:
** Unit Testing Project BSQ
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

void main_redirect_stdout(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(BSQ, test1)
{
	int nb[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	maps_t *tabs = malloc(sizeof(maps_t));
	tabs->map = "...o..\n......";
	tabs->nbmap = nb;
	cr_assert_eq(firstline(tabs), 0);
}

Test(BSQ, test2)
{
	maps_t *tabs = malloc(sizeof(maps_t));
	tabs->map = "...o..";
	cr_assert_eq(firstcol(tabs), 0);
}

Test(BSQ, test3)
{
	cr_assert_eq(my_stat("./tests/stat"), 18);
}

Test(BSQ, test4)
{
	int nb[] = {1, 1, 1, 1};
	maps_t *tabs = malloc(sizeof(maps_t));
	tabs->nbmap = nb;
	tabs->map = "....";
	tabs->value = 0;
	tabs->j = 0;
	tabs->i = 0;
	cr_assert_eq(calc(tabs), 0);
}
