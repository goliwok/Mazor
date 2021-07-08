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
  int	x;

  x = 0;
  while (x != size)
  {
    get[x] = put[x];
    x++;
  }
  return (get);
}

t_map	*get_lab(t_map *my_map, FILE *fd, char *file_name, int larg)
{
  ssize_t	read;
  size_t	len;
  char		*line;
  int		cmp;

  cmp = 0;
  len = 0;
  line = NULL;
  fd = fopen(file_name, "r");
  if (fd == NULL)
    exit(EXIT_FAILURE);
  while ((read = getline(&line, &len, fd)) != -1)
  {
    my_map->map[cmp] = get_cara(my_map->map[cmp], line, larg);
    cmp++;
  }
  if (line)
    free(line);
  fclose(fd);
  return (my_map);
}

t_map	*get_content(char *line, FILE *fd, size_t len, char *file_name)
{
  ssize_t	read;
  t_map		*my_map;
  int		larg;
  int		haut;

  my_map = NULL;
  larg = 0;
  while ((read = getline(&line, &len, fd)) != -1)
  {
    larg++;
    haut = (int)read;
  }
  my_map = alloc_allr(my_map, larg, haut);
  my_map->y = haut-1;
  my_map->x = larg;
  my_map = get_lab(my_map, fd, file_name, larg);
  free(line);
  return (my_map);
}
