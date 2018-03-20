/*
** rewrite_path.c for rewrite_path in /home/antoin_g/rendu/C_prog_elem/dante/profondeur
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Fri Apr 29 14:41:56 2016 Loïs
** Last update Mon May  2 17:51:29 2016 Loïs
*/

#include "structs.h"

void	my_mx(t_pos *tmp, const t_pos *pos, const t_map *map, const int **path)
{
  (void)map;
  if (pos->x > 0 && (tmp->value < 0 || (tmp->value > path[pos->y][pos->x - 1]
				       && path[pos->y][pos->x - 1] >= 0)))
    {
      tmp->y = pos->y;
      tmp->x = pos->x - 1;
      tmp->value = path[pos->y][pos->x - 1];
    }
}

void	my_px(t_pos *tmp, const t_pos *pos, const t_map *map, const int **path)
{
  if (pos->x < map->width - 1
      && (tmp->value < 0 || (tmp->value > path[pos->y][pos->x + 1]
			    && path[pos->y][pos->x + 1] >= 0)))
    {
      tmp->y = pos->y;
      tmp->x = pos->x + 1;
      tmp->value = path[pos->y][pos->x + 1];
    }
}

void	my_my(t_pos *tmp, const t_pos *pos, const t_map *map, const int **path)
{
  (void)map;
  if (pos->y > 0 && (tmp->value < 0 || (tmp->value > path[pos->y - 1][pos->x]
				       && path[pos->y - 1][pos->x] >= 0)))
    {
      tmp->y = pos->y - 1;
      tmp->x = pos->x;
      tmp->value = path[pos->y - 1][pos->x];
    }
}

void	my_py(t_pos *tmp, const t_pos *pos, const t_map *map, const int **path)
{
  if (pos->y < map->height - 1
      && (tmp->value < 0 || (tmp->value > path[pos->y + 1][pos->x]
			    && path[pos->y + 1][pos->x] >= 0)))
    {
      tmp->x = pos->x;
      tmp->y = pos->y + 1;
      tmp->value = path[pos->y + 1][pos->x];
    }
}
