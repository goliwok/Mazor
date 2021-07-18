/*
** draw_path.c for resolve in mery_h/test/dante/tournoi/srcs
**
** Made by Henry Fumery
** Login   <fumery_h@epitech.eu>
**
** Started on  Mon May 16 22:22:21 2016 Henry Fumery
** Last update Mon May 16 22:22:21 2016 Henry Fumery
*/

#include	<time.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"../my_r.h"

t_map	*init_draw_path(t_map *map, int larg, int haut)
{
  int	i = 0;
  int	j;

  while (i != haut)
  {
    j = 0;
    while (j != larg)
	    map->seen[i][j++] = 0;
    i++;
  }
  map->x = 0;
  map->y = 0;
  map->seen[map->y][map->x] = 1;
  map->cmp_lab = (larg * haut);
  return (map);
}

t_map	*draw_path(t_map *map, int larg, int haut)
{
  int	i = 0;
  int	dir = 0;
  int	nb_rand;

  map = init_draw_path(map, larg, haut);
  srand(time(NULL));
  while (map->x != larg - 1 || map->y != haut - 1)
  {
    nb_rand = rand() % 4 + 1;
    map->map[map->y][map->x] = 'O';
    if (check_nb_posr(map, haut, larg) > 1)
	    dir = map->save[i++]->dir;
    else
	  {
	    dir = check_posr(nb_rand, map, haut, larg);
	    while (dir == 0)
	      dir = check_posr(nb_rand = rand() % 4 + 1, map, haut, larg);
	  }
    change_posr(map, dir);
  }
  map->map[haut - 1][larg - 1] = 'O';
  print_maze(map, larg, haut);
  return (map);
}

