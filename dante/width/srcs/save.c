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

t_map	*saver(t_map *map, int haut, int larg, int dir)
{
  if (check_nb_posr(map, haut, larg) > 1)
  {
    map->my_signal = 1;
    map->save[map->cmp_save]->x = map->x;
    map->save[map->cmp_save++]->y = map->y;
  }
  else if (check_nb_posr(map, haut, larg) == 0)
  {
    map->my_signal = 2;
    map->x = map->save[map->cmp_save-1]->x;
    map->y = map->save[map->cmp_save-1]->y;
  }
  if (check_nb_posr(map, haut, larg) == 0)
  {
    while (check_nb_posr(map, haut, larg) == 0)
	  {
	    map->cmp_save--;
	    map->x = map->save[map->cmp_save-1]->x;
	    map->y = map->save[map->cmp_save-1]->y;
	  }
  }
  return (map);
}
