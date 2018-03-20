/*
** astar_tools.c for astar_tools in /home/antoin_g/rendu/C_prog_elem/dante/astar
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Thu May  5 19:43:41 2016 Loïs
** Last update Thu May  5 20:05:06 2016 Loïs
*/

#include "functions.h"
#include "defines.h"

int	check_next(int **tab, const t_map *map,
		   const t_chain *tmp, t_prio *prio)
{
  int	check;

  check = 0;
  check_all_sens(tab, map, tmp, prio);
  check = (tmp->x > 0 && tab[tmp->y][tmp->x - 1] == START) ? 1 : check;
  check = (tmp->y > 0 && tab[tmp->y - 1][tmp->x] == START) ? 1 : check;
  check = (tmp->x < map->width - 1 &&
	   tab[tmp->y][tmp->x + 1] == START) ? 1 : check;
  check = (tmp->y < map->height - 1 &&
	   tab[tmp->y + 1][tmp->x] == START) ? 1 : check;
  return (check);
}

int		go_back(t_prio *prio, int check, int **tab, const t_map *map)
{
  t_chain	*tmp;
  t_chain	*save;

  tmp = prio->back.first;
  while (!prio->prio.first && !check && tmp)
    {
      save = tmp;
      check = check_next(tab, map, tmp, prio);
      tmp = tmp->next;
      free(save);
      prio->back.first = tmp;
    }
  return (check);
}
