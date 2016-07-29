/*
** free_funct.c for free_funct in /fumery_h/rendu/dante/generateur/srcs
**
** Made by henry fumery
** fumery_h   <henry.fumery@epitech.eu>
**
** Started on  Sun May 22 17:13:58 2016 henry fumery
** Last update Sun May 22 17:13:58 2016 henry fumery
*/

#include	<stdlib.h>
#include	"../my.h"

void	free_tab(int larg, int haut, char **map)
{
  int	i;

  i = 0;
  while (i != haut)
    {
      free(map[i]);
      i++;
    }
  free(map);
}

void	free_tab_int(int larg, int haut, int **map)
{
  int	i;

  i = 0;
  while (i != haut)
    {
      free(map[i]);
      i++;
    }
  free(map);
}

void	free_struct(t_map *my_map, int larg, int haut)
{
  int	i;

  i = 0;
  while (i != (larg*haut))
    {
      free(my_map->save[i]);
      i++;
    }
  free (my_map->save);
}

void	free_all(t_map	*my_map, int larg, int haut)
  {
    int		map_larg;
    int		map_haut;

    map_larg = (larg * 2) + 1;
    map_haut = (haut * 2) + 1;
    free_tab(map_larg, map_haut, my_map->map);
    free_tab_int(map_larg, map_haut, my_map->gen->status);
    free_tab_int(map_larg, map_haut, my_map->seen);
    free_struct(my_map, larg, haut);
    free(my_map->gen);
    free(my_map);
  }
