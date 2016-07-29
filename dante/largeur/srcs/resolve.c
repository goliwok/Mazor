/*
** resolve.c for resolve in mery_h/test/dante/tournoi/srcs
**
** Made by Henry Fumery
** Login   <fumery_h@epitech.eu>
**
** Started on  Mon May 16 22:22:55 2016 Henry Fumery
** Last update Mon May 16 22:22:55 2016 Henry Fumery
*/

#include	<time.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"../my_r.h"

void	print_labr(t_map *my_map, int larg, int haut)
{
  int	i;
  int	j;

  j = 0;
  while (j != haut)
    {
      i = 0;
      while (i != larg)
	{
	  printf("%c", my_map->map[j][i]);
	  i++;
	}
      printf("\n");
      j++;
    }
}
t_map	*change_posr(t_map *my_map, int nb)
{
  if (nb == 1)
    my_map->x -= 1;
  else if (nb == 2)
    my_map->y -= 1;
  else if (nb == 3)
    my_map->x += 1;
  else
    my_map->y += 1;
  my_map->seen[my_map->y][my_map->x] = 1;
  return (my_map);
}

void	resolve_lab(t_map *my_map, int haut, int larg)
{
  int	nb_rand;
  int	dir;

  srand(time(NULL));
  my_map->x = 0;
  my_map->y = 0;
  my_map->seen[my_map->y][my_map->x] = 1;
  my_map->cmp_lab = (larg * haut);
  while ((my_map->x != larg-2 || my_map->y != larg-1)
    && (my_map->x != larg-1 || my_map->y != larg-2))
    {
      nb_rand = rand()%4+1;
      dir = check_posr(nb_rand, my_map, haut, larg);
      while (dir == 0)
	{
	  nb_rand = rand()%4+1;
	  dir = check_posr(nb_rand, my_map, haut, larg);
	}
      my_map = find_path(my_map, dir);
      my_map = change_posr(my_map, dir);
      my_map = saver(my_map, haut, larg, dir);
    }
  my_map = draw_path(my_map, larg, haut);
  free_all(my_map, haut, larg);
}

int	main(int ac, char **av)
{
  t_map		*my_map;
  char		*line;
  FILE		*fd;
  size_t	len;

  len = 0;
  line = NULL;
  if (ac == 2)
    {
      fd = fopen(av[1], "r");
      if (fd == NULL)
	exit(EXIT_FAILURE);
      my_map = get_content(line, fd, len, av[1]);
      my_map->cmp_save = 0;
      my_map->my_signal = 0;
      resolve_lab(my_map, my_map->y, my_map->x);
      if (line)
	free(line);
      fclose(fd);
      exit(EXIT_SUCCESS);
    }
  return (0);
}
