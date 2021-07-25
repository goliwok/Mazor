/*
** mal_funct.c for mal_funct in /fumery_h/rendu/dante/profondeur/srcs
**
** Made by henry fumery
** fumery_h   <henry.fumery@epitech.eu>
**
** Started on  Sun May 22 17:15:57 2016 henry fumery
** Last update Sun May 22 17:15:57 2016 henry fumery
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"../resolver.h"

void	*my_mallocr(size_t size)
{
  void	*str = malloc(size);

  if (str == NULL)
  {
    write(1, "error with malloc\n", 18);
    exit (EXIT_FAILURE);
  }
  return (str);
}

char	**malloc_tabr(char **map, int width, int height)
{
  map = my_mallocr(sizeof(char*) * (height));
  for (int i = 0; i != height; i++)
    map[i] = my_mallocr(sizeof(char) * (width));
  return (map);
}

int   **mal_tab_intr(int **map, int width, int height)
{
  map = my_mallocr(sizeof(int*) * (height));
  for (int i = 0; i != height; i++)
  {
    map[i] = my_mallocr(sizeof(int) * (width));
    for (int j = 0; j != width; j++)
	    map[i][j] = 0;
  }
  return (map);
}

t_map   *malloc_structr(t_map *map, int width, int height)
{
  int	i = 0;

  map->save = my_mallocr(sizeof(t_save*) * (width * height));
  for (int i = 0; i != (width * height); i++)
    map->save[i] = my_mallocr(sizeof(t_save) + 2);
  return (map);
}

t_map	  *alloc_allr(t_map *map, int width, int height)
{
  map = my_mallocr(sizeof(t_map) * 4);
  map = malloc_structr(map, width, height);
  map->seen = mal_tab_intr(map->seen, width, height);
  map->map = malloc_tabr(map->map, width, height);
  return (map);
}
