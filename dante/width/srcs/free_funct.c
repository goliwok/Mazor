/*
** free_funct.c for free_funct in /fumery_h/rendu/dante/generateur/srcs
**
** Made by henry fumery
** fumery_h   <henry.fumery@epitech.eu>
**
** Started on  Sun May 22 17:13:58 2016 henry fumery
** Last update Sun May 22 17:13:58 2016 henry fumery
*/

#include	<stdlib.h>
#include	"../resolver.h"

void	free_tab(void **map, int width, int height)
{
  for (int	i = 0; i != height; i++)
    free(map[i]);
  free(map);
}

void	free_struct(t_map *map, int width, int height)
{
  for (int i = 0; i != (width * height); i++)
    free(map->save[i]);
  free (map->save);
}

void	free_all(t_map	*map, int width, int height)
{
  free_tab((void*) map->map, width, height + 1);
  free_tab((void*) map->seen, width, height + 1);
  free_struct(map, width + 1, height);
  free(map);
}
