/*
** save.c for save in /fumery_h/rendu/dante/generateur/srcs
**
** Made by henry fumery
** fumery_h   <henry.fumery@epitech.eu>
**
** Started on  Sun May 22 17:15:26 2016 henry fumery
** Last update Sun May 22 17:15:26 2016 henry fumery
*/

#include	"../my.h"

t_map	*save(t_map *my_map)
{
  if (check_nb_pos(my_map) > 1)
    {
      my_map->save[my_map->cmp_save]->x = my_map->x;
      my_map->save[my_map->cmp_save++]->y = my_map->y;
    }
  else if (check_nb_pos(my_map) == 0)
    {
      my_map->x = my_map->save[my_map->cmp_save-1]->x;
      my_map->y = my_map->save[my_map->cmp_save-1]->y;
    }
  if (check_nb_pos(my_map) == 0)
    {
      while (check_nb_pos(my_map) == 0)
	{
	  my_map->cmp_save--;
	  my_map->x = my_map->save[my_map->cmp_save-1]->x;
	  my_map->y = my_map->save[my_map->cmp_save-1]->y;
	}
    }
  return (my_map);
}
