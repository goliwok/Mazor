/*
** dante_lab.c for dante_lab in /fumery_h/rendu/dante/generateur/srcs
**
** Made by henry fumery
** fumery_h   <henry.fumery@epitech.eu>
**
** Started on  Sun May 22 17:13:14 2016 henry fumery
** Last update Sun May 22 17:13:14 2016 henry fumery
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<time.h>
#include	<string.h>
#include	"../my.h"

void	print_lab(t_map *my_map, int larg, int haut)
{
  int	i;
  int	j;

  larg = (larg * 2);
  haut = (haut * 2);
  j = 1;
  while (j != haut)
    {
      i = 1;
      while (i != larg)
	{
	  printf("%c", my_map->map[j][i]);
	  i++;
	}
      printf("\n");
      j++;
    }
}

void	manage_lab(int larg, int haut, char* type)
{
  if (type == NULL)
    lab_stand_imperfect(larg, haut);
  else if (strcmp("parfait", type) == 0)
    lab_stand_perfect(larg, haut);
  else if (strcmp("imparfait", type) == 0)
    lab_stand_imperfect(larg, haut);
  else
    printf("type of maze not found.\n");
}

int	main(int ac, char **av)
{
  int	haut;
  int	larg;

  if (ac == 3 || ac == 4)
    {
      haut = atoi(av[1]);
      larg = atoi(av[2]);
      if (haut >= 10000 || larg >= 10000)
	{
	  printf("size too big");
	  exit (-1);
	}
      if (haut > 0 && larg > 0)
	manage_lab(larg, haut, av[3]);
    }
  return 0;
}
