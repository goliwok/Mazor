/*
** resolver.h for my in /fumery_h/rendu/dante/profondeur
**
** Made by henry fumery
** fumery_h   <henry.fumery@epitech.eu>
**
** Started on  Sun May 22 17:11:06 2016 henry fumery
** Last update Sun May 22 17:11:06 2016 henry fumery
*/
#include <unistd.h>
#include <stdio.h>

#ifndef _RESOLVER_H_
#define _RESOLVER_H_

typedef struct s_save
{
  int x;
  int y;
  int dir;
} t_save;

typedef struct s_map
{
  t_save  **save;
  char    **map;
  int     **seen;
  int     cmp_save;
  int     x;
  int     y;
  int     cmp_lab;
  int     my_signal;
} t_map;

int     check_posr(int nb, t_map *my_map, int haut, int larg);
t_map   *saver(t_map *my_map, int haut, int larg, int dir);
t_map   *get_content(char *line, FILE *fd, size_t len, char *file_name);
int 	  check_nb_posr(t_map *my_map, int haut, int larg);
t_map   *find_path(t_map  *my_map, int dir);
t_map   *alloc_allr(t_map *my_map, int larg, int haut);
t_map   *init_draw_path(t_map *my_map, int larg, int haut);
void	  print_maze(t_map *my_map, int larg, int haut);
t_map   *draw_path(t_map *my_map, int larg, int haut);
void    change_posr(t_map *my_map, int nb);
void    free_all(t_map  *my_map, int larg, int haut);

#endif /* _RESOLVER_H_ */