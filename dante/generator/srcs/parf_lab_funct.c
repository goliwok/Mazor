/*
** parf_lab_funct.c for parf_lab_funct in /fumery_h/rendu/dante/perfect/srcs
**
** Made by henry fumery
** fumery_h   <henry.fumery@epitech.eu>
**
** Started on  Sat May 21 17:35:33 2016 henry fumery
** Last update Sat May 21 17:35:33 2016 henry fumery
*/

#include	<time.h>
#include	<stdlib.h>
#include	"../my.h"

t_map	*change_pos(t_map *my_map, int nb)
{
  if (nb == 1)
    {
      my_map->map[my_map->y][my_map->x-1] = '*';
      my_map->x -= 2;
    }
  else if (nb == 2)
    {
      my_map->map[my_map->y-1][my_map->x] = '*';
      my_map->y -= 2;
    }
  else if (nb == 3)
    {
      my_map->map[my_map->y][my_map->x+1] = '*';
      my_map->x += 2;
    }
  else
    {
      my_map->map[my_map->y+1][my_map->x] = '*';
      my_map->y += 2;
    }
  my_map->seen[my_map->y][my_map->x] = 1;
  return (my_map);
}

t_map	*make_intra_lab(t_map *my_map, int larg, int haut)
{
  int	nb_rand;
  int	dir;
  int	cmp;

  cmp = 0;
  my_map->x = 1;
  my_map->y = 1;
  srand(time(NULL));
  my_map->seen[my_map->y][my_map->x] = 1;
  my_map->cmp_lab = (larg * haut);
  while (cmp != my_map->cmp_lab-1)
    {
      nb_rand = rand()%4+1;
      dir = check_pos(nb_rand, my_map);
      my_map = save(my_map);
      while (dir == 0)
	{
	  nb_rand = rand()%4+1;
	  dir = check_pos(nb_rand, my_map);
	}
      my_map = change_pos(my_map, dir);
      cmp++;
    }
  return(my_map);
}

void	lab_stand_perfect(int larg, int haut)
{
  t_map		*my_map;
  int		map_larg;
  int		map_haut;

  map_larg = (larg * 2) + 1;
  map_haut = (haut * 2) + 1;
  my_map = NULL;
  my_map = alloc_all(my_map, larg, haut);
  my_map->gen->y = 0;
  my_map->gen->x = 0;
  my_map = make_lab(my_map, map_larg, map_haut);
  my_map = init_lab(my_map, map_larg, map_haut);
  my_map = make_intra_lab(my_map, larg, haut);
  print_lab(my_map, larg, haut);
  free_all(my_map, larg, haut);
}
