/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** create_maps
*/

#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "main.h"

int *newmap(maps_t *tabs, int size)
{
	int i = 0;
	int *nbmap = malloc(sizeof(int) * size + 1);

	while (tabs->map[i] != '\0') {
		if (tabs->map[i] == '.')
			nbmap[i] = 1;
		if (tabs->map[i] == 'o')
			nbmap[i] = 0;
		i++;
	}
	nbmap[i] = '\0';
	return (nbmap);
}

int my_stat(char const *filepath)
{
	int size = 0;
	struct stat sb;

	stat(filepath, &sb);
	size = sb.st_size;
	if (size == -1)
		size = 0;
	return (size);
}
int mallocmap(maps_t *tabs, char const *filepath, int fd)
{
	char *map;
	int i = 0;
	int b = 0;
	int size = 0;

	size = my_stat(filepath);
	map = malloc(sizeof(char) * size +1);
	i = read(fd, (void *)map, size);
	if (i == -1)
		return (i);
	map[i]= '\0';
	while (*map != '\n') {
		map += 1;
		b++;
	}
	map += 1;
	tabs->map = map;
	tabs->nbmap = newmap(tabs, size);
	return (size -b -1);
}

void declare_variable(maps_t *tabs)
{
	tabs->i = 0;
	tabs->j = 0;
	tabs->b = 0;
	tabs->value = 0;
}
