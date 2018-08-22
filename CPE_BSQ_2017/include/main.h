/*
** EPITECH PROJECT, 2017
** Project BSQ
** File description:
** Header file
*/

#ifndef MAIN_H_
	#define MAIN_H_
	#include <stdlib.h>
	#include <stdio.h>

typedef struct maps_s {
	char *map;
	int *nbmap;
	int value;
	int j;
	int i;
	int b;
}maps_t;

	int algo(maps_t *);
	int firstcol(maps_t *);
	int firstline(maps_t *);
	int cases(maps_t *);
	int calc(maps_t *);
	void declare_variable(maps_t *);
	int mallocmap(maps_t *, char const *, int);
	int *newmap(maps_t *, int);
	int my_stat(char const *);
#endif
