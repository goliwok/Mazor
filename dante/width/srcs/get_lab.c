/*
** get_lab.c for get_lab in /fumery_h/rendu/dante/profondeur/srcs
**
** Made by henry fumery
** fumery_h   <henry.fumery@epitech.eu>
**
** Started on  Sun May 22 18:16:30 2016 henry fumery
** Last update Sun May 22 18:16:30 2016 henry fumery
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"../resolver.h"

char	*get_char(char *get, char *put, int size)
{
  for (int x = 0; x != size; x++)
    get[x] = put[x];
  return (get);
}

t_map	*get_maze(t_map *map, FILE *fd, char *file_name, int width)
{
  ssize_t	read;
  size_t	len = 0;
  char		*line = NULL;
  int		cmp = 0;

  fd = fopen(file_name, "r");
  if (fd == NULL)
    exit(EXIT_FAILURE);
  while ((read = getline(&line, &len, fd)) != -1)
  {
    map->map[cmp] = get_char(map->map[cmp], line, width);
    cmp++;
  }
  if (line)
    free(line);
  fclose(fd);
  return (map);
}

t_map	*get_content(char *line, FILE *fd, size_t len, char *file_name)
{
  ssize_t	read;
  t_map		*map = NULL;
  int		width = 0;
  int		haut;

  while ((read = getline(&line, &len, fd)) != -1)
  {
    width++;
    haut = (int)read;
  }
  map = alloc_allr(map, width, haut);
  map->y = haut-1;
  map->x = width;
  map = get_maze(map, fd, file_name, width);
  free(line);
  return (map);
}
