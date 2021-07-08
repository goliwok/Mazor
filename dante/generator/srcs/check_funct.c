/*
** check_funct.c for check_funct in /fumery_h/rendu/dante/generateur/srcs
**
** Made by henry fumery
** fumery_h   <henry.fumery@epitech.eu>
**
** Started on  Sun May 22 17:12:55 2016 henry fumery
** Last update Sun May 22 17:12:55 2016 henry fumery
*/

#include	"../my.h"

int	check_nb_pos(t_map *my_map)
{
  int	x;
  int	y;
  int	cmp;

  x = my_map->x;
  y = my_map->y;
  cmp = 0;
  if (my_map->gen->status[y][x-1] == 0 && my_map->seen[y][x-2] == 0)
    cmp++;
  if (my_map->gen->status[y-1][x] == 0 && my_map->seen[y-2][x] == 0)
    cmp++;
  if (my_map->gen->status[y][x+1] == 0 && my_map->seen[y][x+2] == 0)
    cmp++;
  if (my_map->gen->status[y+1][x] == 0 && my_map->seen[y+2][x] == 0)
    cmp++;
  return (cmp);
}

int	check_pos(int nb, t_map *my_map)
{
  int	x;
  int	y;

  x = my_map->x;
  y = my_map->y;
  if (nb == 1)
    {
      if (my_map->gen->status[y][x-1] == 0 && my_map->seen[y][x-2] == 0)
	return (1);
    }
  else if (nb == 2)
    {
      if (my_map->gen->status[y-1][x] == 0 && my_map->seen[y-2][x] == 0)
	return (2);
    }
  else if (nb == 3)
    {
      if (my_map->gen->status[y][x+1] == 0 && my_map->seen[y][x+2] == 0)
	return (3);
    }
  else
    if (my_map->gen->status[y+1][x] == 0 && my_map->seen[y+2][x] == 0)
    return (4);
  return (0);
}

int	check_wall(t_map *my_map, int x, int y)
{
  if (my_map->gen->status[y][x] == 0 && x != my_map->x)
    {
      if (my_map->map[y][x] == 'X' && my_map->map[y+1][x] == 'X'
      && my_map->map[y-1][x] == 'X')
      return (1);
    }
  else if (my_map->gen->status[y][x] == 0 && y != my_map->y)
    {
      if (my_map->map[y][x] == 'X' && my_map->map[y][x+1] == 'X'
      && my_map->map[y][x-1] == 'X')
      return (1);
    }
  return(0);
}

int	check_pos_im(int nb, t_map *my_map, int x, int y)
{
  if (nb == 1)
    {
      if (check_wall(my_map, x-1, y) == 1 && my_map->map[y][x-2] == '*')
	return (1);
    }
  else if (nb == 2)
    {
      if (check_wall(my_map, x, y-1) == 1 && my_map->map[y-2][x] == '*')
	return (2);
    }
  else if (nb == 3)
    {
      if (check_wall(my_map, x+1, y) == 1 && my_map->map[y][x+2] == '*')
	return (3);
    }
  else
    if (check_wall(my_map, x, y+1) == 1 && my_map->map[y+2][x] == '*')
    return (4);
  return (0);
}
