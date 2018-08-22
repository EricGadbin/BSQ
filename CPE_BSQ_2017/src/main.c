/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** main
*/

#include <unistd.h>
#include <fcntl.h>
#include "main.h"

int main(int ac, char **argv)
{
	maps_t *tabs = malloc(sizeof(maps_t));
	char const *filepath = argv[1];
	int fd = open(filepath, O_RDONLY);
	int size = mallocmap(tabs, filepath, fd);

	if (ac != 2 || fd == -1 || size == -1) {
		free(tabs);
		return (84);
	}
	declare_variable(tabs);
	firstline(tabs);
	firstcol(tabs);
	algo(tabs);
	write(1, tabs->map, size);
	close(fd);
	free(tabs->nbmap);
	free(tabs);
	return (0);
}
