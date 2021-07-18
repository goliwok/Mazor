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
#include	"../my_r.h"

char	*get_cara(char *get, char *put, int size)
{
  int	x = 0;

  while (x != size)
  {
    get[x] = put[x];
    x++;
  }
  return (get);
}

t_map	*get_lab(t_map *map, FILE *fd, char *file_name, int larg)
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
    map->map[cmp] = get_cara(map->map[cmp], line, larg);
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
  int		larg = 0;
  int		haut;

  while ((read = getline(&line, &len, fd)) != -1)
  {
    larg++;
    haut = (int)read;
  }
  map = alloc_allr(map, larg, haut);
  map->y = haut-1;
  map->x = larg;
  map = get_lab(map, fd, file_name, larg);
  free(line);
  return (map);
}
