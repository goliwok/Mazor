/*
** mal_funct.c for mal_funct in /fumery_h/rendu/dante/generateur/srcs
**
** Made by henry fumery
** fumery_h   <henry.fumery@epitech.eu>
**
** Started on  Sun May 22 17:15:08 2016 henry fumery
** Last update Sun May 22 17:15:08 2016 henry fumery
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"../my.h"

void	*my_malloc(size_t size)
{
  void	*str;

  str = malloc(size);
  if (str == NULL)
    {
      write(1, "error with malloc\n", 18);
      exit (-1);
    }
  return (str);
}

char	**malloc_tab(int larg, int haut, char **map)
{
  int	i;

  i = 0;
  map = my_malloc(sizeof(char*) * (haut));
  while (i != haut)
    {
      map[i] = NULL;
      map[i] = my_malloc(sizeof(char) * (larg));
      i++;
    }
  return (map);
}

int	**mal_tab_int(int larg, int haut, int **map)
{
  int	i;
  int	j;

  i = 0;
  map = my_malloc(sizeof(int*) * (haut));
  while (i != haut)
    {
      j = 0;
      map[i] = NULL;
      map[i] = my_malloc(sizeof(int) * (larg));
      while (j != larg)
	{
	  map[i][j] = 0;
	  j++;
	}
      i++;
    }
  return (map);
}

t_map	*malloc_struct(t_map *my_map, int larg, int haut)
{
  int	i;

  i = 0;
  my_map->save = my_malloc(sizeof(t_save*) * (larg*haut));
  while (i != (larg*haut))
    {
      my_map->save[i] = my_malloc(sizeof(t_save) + 2);
      i++;
    }
  return (my_map);
}

t_map	*alloc_all(t_map *my_map, int larg, int haut)
{
  int	map_larg;
  int	map_haut;

  map_larg = (larg * 2) + 1;
  map_haut = (haut * 2) + 1;
  my_map = my_malloc(sizeof(t_map) * 4);
  my_map->gen = my_malloc(sizeof(t_gen) * 4);
  my_map = malloc_struct(my_map, larg, haut);
  my_map->gen->status = mal_tab_int(map_larg, map_haut, my_map->gen->status);
  my_map->seen = mal_tab_int(map_larg, map_haut, my_map->seen);
  my_map->map = malloc_tab(map_larg, map_haut, my_map->map);
  return (my_map);
}
