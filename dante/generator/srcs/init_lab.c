/*
** init_lab.c for init_lab in /fumery_h/rendu/dante/generateur/srcs
**
** Made by henry fumery
** fumery_h   <henry.fumery@epitech.eu>
**
** Started on  Sun May 22 17:14:38 2016 henry fumery
** Last update Sun May 22 17:14:38 2016 henry fumery
*/

#include	"../my.h"

t_map	*make_lab(t_map *my_map, int larg, int haut)
{
  int	x_cel;
  int	y_cel;

  my_map->cmp_save = 0;
  y_cel = 1;
  while (y_cel != haut+1)
    {
      x_cel = 1;
      my_map->gen->x = 0;
      while (x_cel != larg+1)
	{
	  if (x_cel%2 != 1 && y_cel%2 != 1)
	    my_map->map[my_map->gen->y][my_map->gen->x] = '*';
	  else
	    my_map->map[my_map->gen->y][my_map->gen->x] = 'X';
	  my_map->gen->x++;
	  x_cel++;
	}
      my_map->gen->y++;
      y_cel++;
    }
  return (my_map);
}

t_map	*init_lab(t_map *my_map, int larg, int haut)
{
  int	x;
  int	y;
  int	cmp_x;
  int	cmp_y;

  cmp_y = 0;
  y = 0;
  while (y != haut)
    {
      x = 0;
      cmp_x = 0;
      while (x != larg)
	{
	  if (x == 0 || x == larg-1 || y == 0 || y == haut-1)
	    my_map->gen->status[y][x] = 1;
	  else if (my_map->map[y][x] == '*')
	    my_map->seen[cmp_y][cmp_x++] = 0;
	  else
	    my_map->gen->status[y][x] = 0;
	  x++;
	}
      cmp_y++;
      y++;
    }
  return (my_map);
}
