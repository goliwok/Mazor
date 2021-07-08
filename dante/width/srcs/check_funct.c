/*
** check_funct.c for check_funct in /fumery_h/rendu/dante/profondeur/srcs
**
** Made by henry fumery
** fumery_h   <henry.fumery@epitech.eu>
**
** Started on  Sun May 22 19:44:23 2016 henry fumery
** Last update Sun May 22 19:44:23 2016 henry fumery
*/

#include	"../my_r.h"

t_map	*find_path(t_map *my_map, int dir)
{
  if (my_map->my_signal == 1)
  {
    my_map->save[my_map->cmp_save-1]->dir = dir;
    my_map->my_signal = 0;
  }
  else if (my_map->my_signal == 2)
  {
    my_map->save[my_map->cmp_save-1]->dir = dir;
    my_map->my_signal = 0;
  }
  return (my_map);
}

int	check_nb_posr(t_map *my_map, int haut, int larg)
{
  int	x;
  int	y;
  int	cmp;

  x = my_map->x;
  y = my_map->y;
  cmp = 0;
  if (x-1 >= 0 && my_map->seen[y][x-1] == 0 && my_map->map[y][x-1] != 'X')
    cmp++;
  if (y-1 >= 0 && my_map->seen[y-1][x] == 0 && my_map->map[y-1][x] != 'X')
    cmp++;
  if (x+1 <= larg-1 && my_map->seen[y][x+1] == 0 && my_map->map[y][x+1] != 'X')
    cmp++;
  if (y+1 <= haut-1 && my_map->seen[y+1][x] == 0 && my_map->map[y+1][x] != 'X')
    cmp++;
  return (cmp);
}

int	check_posr(int nb, t_map *my_map, int haut, int larg)
{
  int	x;
  int	y;

  x = my_map->x;
  y = my_map->y;
  if (nb == 1 && x-1 >= 0)
  {
    if (my_map->seen[y][x-1] == 0 && my_map->map[y][x-1] != 'X')
	    return (1);
  }
  else if (nb == 2 && y-1 >= 0)
  {
    if (my_map->seen[y-1][x] == 0 && my_map->map[y-1][x] != 'X')
	    return (2);
  }
  else if (nb == 3 && x+1 <= larg-1)
  {
    if (my_map->seen[y][x+1] == 0 && my_map->map[y][x+1] != 'X')
	    return (3);
  }
  else if (y+1 <= haut-1)
    if (my_map->seen[y+1][x] == 0 && my_map->map[y+1][x] != 'X')
      return (4);
  return (0);
}
