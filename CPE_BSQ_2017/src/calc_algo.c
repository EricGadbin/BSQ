/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** algo
*/

#include "main.h"

int firstline(maps_t *tabs)
{
	int i = 0;
	while (tabs->map[i] != '\n') {
		if (tabs->map[i] == '.')
			tabs->nbmap[i] = 1;
		else
			tabs->nbmap[i] = 0;
		i++;
	}
	return (0);
}

int firstcol(maps_t *tabs)
{
	int i = 0;
	while (tabs->map[i] != '\0') {
		if (tabs->map[i] == '\n')
			tabs->map[i + 1] == '.' ? tabs->nbmap[i + 1] = 1 :
			(tabs->nbmap[i + 1] = 0);
		i++;
	}
	return (0);
}

int calc(maps_t *tabs)
{
	if (tabs->map[tabs->j] == '.') {
		if (tabs->nbmap[tabs->j - 1] ==
		tabs->nbmap[tabs->j - tabs->i - 1] && tabs->nbmap[tabs->j - 1]
		== tabs->nbmap[tabs->j - tabs->i])
			tabs->value = tabs->nbmap[tabs->j - 1];
		else {
			tabs->value = tabs->nbmap[tabs->j - 1];
			tabs->value = (tabs->value >
			tabs->nbmap[tabs->j - tabs->i]) ?
			tabs->nbmap[tabs->j - tabs->i] : tabs->value;
			tabs->value = (tabs->value >
			tabs->nbmap[tabs->j - tabs->i - 1]) ?
			tabs->nbmap[tabs->j - tabs->i -1] : tabs->value;
		}
		tabs->value += 1;
	}
	return (0);
}

int algo(maps_t *tabs)
{
	int a = 0;
	int b = 0;

	for (tabs->i = 0; tabs->map[tabs->i] != '\n'; tabs->i++);
	tabs->i += 1;
	b = tabs->i;
	tabs->j = 0;
	while (tabs->map[tabs->j] != '\0') {
		if (tabs->map[tabs->j -1] != '\n' && tabs->j >= b) {
			tabs->value = 0;
			calc(tabs);
			tabs->nbmap[tabs->j] = tabs->value;
		}
		if  (a < tabs->nbmap[tabs->j]) {
			a = tabs->nbmap[tabs->j];
			tabs->b = tabs->j;
		}
		tabs->j++;
	}
	cases(tabs);
	return (0);
}

int cases(maps_t *tabs)
{
	int c = tabs->nbmap[tabs->b];
	int d = c;
	int f = tabs->b;
	int e = c;
	int g = 0;

	while (e != 0) {
		while (c != 0) {
			tabs->map[f] = 'x';
			f--;
			c--;
			g++;
		}
		f -= tabs->i -g;
		e--;
		c = d;
		g = 0;
	}
	return (0);
}
