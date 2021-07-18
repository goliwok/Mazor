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
#include	"../my_r.h"

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

char	**malloc_tabr(int larg, int haut, char **map)
{
  int	i = 0;

  map = my_mallocr(sizeof(char*) * (haut));
  while (i != haut)
  {
    map[i] = NULL;
    map[i] = my_mallocr(sizeof(char) * (larg));
    i++;
  }
  return (map);
}

int	**mal_tab_intr(int larg, int haut, int **map)
{
  int	i = 0;
  int	j;

  map = my_mallocr(sizeof(int*) * (haut));
  while (i != haut)
  {
    j = 0;
    map[i] = NULL;
    map[i] = my_mallocr(sizeof(int) * (larg));
    while (j != larg)
	  {
	    map[i][j] = 0;
	    j++;
	  }
    i++;
  }
  return (map);
}

t_map	*malloc_structr(t_map *map, int larg, int haut)
{
  int	i = 0;

  map->save = my_mallocr(sizeof(t_save*) * (larg*haut));
  while (i != (larg*haut))
  {
    map->save[i] = my_mallocr(sizeof(t_save) + 2);
    i++;
  }
  return (map);
}

t_map	*alloc_allr(t_map *map, int larg, int haut)
{
  map = my_mallocr(sizeof(t_map) * 4);
  map = malloc_structr(map, larg, haut);
  map->seen = mal_tab_intr(larg, haut, map->seen);
  map->map = malloc_tabr(larg, haut, map->map);
  return (map);
}
