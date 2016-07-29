/*
** save.c for resolve in fumery_h/test/dante/tournoi/srcs
**
** Made by Henry Fumery
** Login   <fumery_h@epitech.eu>
**
** Started on  Mon May 16 22:22:55 2016 Henry Fumery
** Last update Mon May 16 22:22:55 2016 Henry Fumery
*/

#include	"../my_r.h"

t_map	*saver(t_map *my_map, int haut, int larg, int dir)
{
  if (check_nb_posr(my_map, haut, larg) > 1)
    {
      my_map->my_signal = 1;
      my_map->save[my_map->cmp_save]->x = my_map->x;
      my_map->save[my_map->cmp_save++]->y = my_map->y;
    }
  else if (check_nb_posr(my_map, haut, larg) == 0)
    {
      my_map->my_signal = 2;
      my_map->x = my_map->save[my_map->cmp_save-1]->x;
      my_map->y = my_map->save[my_map->cmp_save-1]->y;
    }
  if (check_nb_posr(my_map, haut, larg) == 0)
    {
      while (check_nb_posr(my_map, haut, larg) == 0)
	{
	  my_map->cmp_save--;
	  my_map->x = my_map->save[my_map->cmp_save-1]->x;
	  my_map->y = my_map->save[my_map->cmp_save-1]->y;
	}
    }
  return (my_map);
}
