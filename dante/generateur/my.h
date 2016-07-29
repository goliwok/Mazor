/*
** my.h for my in mery_h/test/dante
**
** Made by Henry Fumery
** Login   <fumery_h@epitech.eu>
**
** Started on  Thu May 05 23:06:36 2016 Henry Fumery
** Last update Thu May 05 23:06:36 2016 Henry Fumery
*/

#include	<unistd.h>

#ifndef	_MY_H_
#define _MY_H_

typedef	struct s_save
  {
    int		x;
    int		y;
  }t_save;
typedef struct s_gen
  {
    int		x;
    int		y;
    int		**status;
  }t_gen;
typedef struct s_map
  {
    t_gen	*gen;
    t_save	**save;
    char	**map;
    int		**seen;
    int		cmp_save;
    int		x;
    int		y;
    int		cmp_lab;
  }t_map;

void 	*my_malloc(size_t size);
char	**malloc_tab(int larg, int haut, char **map);
int	**mal_tab_int(int larg, int haut, int **map);
void 	free_tab(int larg, int haut, char **map);
void 	free_tab_int(int larg, int haut, int **map);
void	free_all(t_map	*my_map, int map_larg, int map_haut);
int 	check_nb_pos(t_map *my_map);
int  	check_pos(int nb, t_map *my_map);
void 	lab_stand_perfect(int larg, int haut);
void	print_lab(t_map *my_map, int larg, int haut);
void	lab_stand_imperfect(int larg, int haut);
int	check_wall(t_map *my_map, int x, int y);
int	check_pos_im(int nb, t_map *my_map, int x, int y);
t_map	*manage_wall(t_map *my_map, int larg, int haut);
t_map	*save(t_map *my_map);
t_map	*change_pos(t_map *my_map, int nb);
t_map	*make_intra_lab(t_map *my_map, int larg, int haut);
t_map	*alloc_all(t_map *my_map, int larg, int haut);
t_map	*make_lab(t_map *my_map, int larg, int haut);
t_map	*init_lab(t_map *my_map, int larg, int haut);
t_map 	*malloc_struct(t_map *my_map, int larg, int haut);

#endif /* _MY_H_ */
