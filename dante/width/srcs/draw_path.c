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

t_map	*init_draw_path(t_map *my_map, int larg, int haut)
{
  int	i;
  int	j;

  i = 0;
  while (i != haut)
    {
      j = 0;
      while (j != larg)
	my_map->seen[i][j++] = 0;
      i++;
    }
  my_map->x = 0;
  my_map->y = 0;
  my_map->seen[my_map->y][my_map->x] = 1;
  my_map->cmp_lab = (larg * haut);
  return (my_map);
}

t_map	*draw_path(t_map *my_map, int larg, int haut)
{
  int	i;
  int	dir;
  int	nb_rand;

  i = 0;
  dir = 0;
  my_map = init_draw_path(my_map, larg, haut);
  srand(time(NULL));
  while (my_map->x != larg-1 || my_map->y != haut-1)
  {
    nb_rand = rand()%4+1;
    my_map->map[my_map->y][my_map->x] = 'O';
    if (check_nb_posr(my_map, haut, larg) > 1)
	    dir = my_map->save[i++]->dir;
    else
	  {
	    dir = check_posr(nb_rand, my_map, haut, larg);
	    while (dir == 0)
	      dir = check_posr(nb_rand = rand()%4+1, my_map, haut, larg);
	  }
    my_map = change_posr(my_map, dir);
  }
  my_map->map[haut-1][larg-1] = 'O';
  print_labr(my_map, larg, haut);
  return (my_map);
}

