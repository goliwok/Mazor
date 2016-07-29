/*
** impa_lab_funct.c for impa_lab_funct in /fumery_h/rendu/dante/generateur/srcs
**
** Made by henry fumery
** fumery_h   <henry.fumery@epitech.eu>
**
** Started on  Sun May 22 17:14:23 2016 henry fumery
** Last update Sun May 22 17:14:23 2016 henry fumery
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"../my.h"

t_map	*change_wall(t_map *my_map, int y, int x, int val_change)
{
  if (val_change == 1 && my_map->seen[y][x-1] == 0)
    my_map->map[y][x-1] = '*';
  else if (val_change == 2 && my_map->seen[y-1][x] == 0)
    my_map->map[y-1][x] = '*';
  else if (val_change == 3 && my_map->seen[y][x+1] == 0)
    my_map->map[y][x+1] = '*';
  else if (my_map->seen[y+1][x] == 0)
    my_map->map[y+1][x] = '*';
  my_map->seen[y][x] = 1;
  return (my_map);
}

t_map	*manage_wall(t_map *my_map, int larg, int haut)
{
  int	rand_x;
  int	rand_y;
  int	random;
  int	val_change;

  rand_x = rand()%larg+1;
  rand_y = rand()%haut+1;
  while (my_map->map[rand_y][rand_x] != '*')
    {
      rand_x = rand()%larg+1;
      rand_y = rand()%haut+1;
    }
  random = rand()%4+1;
  val_change = check_pos_im(random, my_map, rand_x, rand_y);
  while (val_change == 0)
    {
      random = rand()%4+1;
      rand_x = rand()%larg+1;
      rand_y = rand()%haut+1;
      val_change = check_pos_im(random, my_map, rand_x, rand_y);
    }
  my_map = change_wall(my_map, rand_y, rand_x, val_change);
  return (my_map);
}

void	open_wall(t_map *my_map, int larg, int haut)
{
  int	nb;

  nb = 0;
  while (nb == 0)
    nb = rand()%larg;
  while (nb != 0)
    {
      my_map = manage_wall(my_map, larg, haut);
      if (my_map != NULL)
	{
	  nb--;
	}
    }
  print_lab(my_map, larg, haut);
}

void	lab_stand_imperfect(int larg, int haut)
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
  open_wall(my_map, larg, haut);
  free_all(my_map, larg, haut);
}
