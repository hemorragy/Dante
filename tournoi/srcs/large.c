/*
** depth.c for depth in /home/antoin_g/rendu/C_prog_elem/dante/profondeur
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Thu Apr 28 03:29:17 2016 Loïs
** Last update Thu May 19 15:29:03 2016 Loïs
*/

#include "functions.h"
#include "defines.h"

static void	add_one(int x, int y, t_utils *utils)
{
  t_chain	*new;

  new = xmalloc(sizeof(t_chain));
  new->next = NULL;
  new->x = x;
  new->y = y;
  if (utils->first == NULL)
    utils->first = new;
  else
    utils->last->next = new;
  utils->last = new;
}

static void	free_chain(t_chain *first)
{
  t_chain	*tmp;

  while (first)
    {
      tmp = first;
      first = first->next;
      free(tmp);
    }
}

static void	check_all_sens(int **tab, const t_map *map,
			       t_utils *new, int value)
{
  if (new->first->y > 0 && tab[new->first->y - 1][new->first->x] == UNDEF)
    {
      tab[new->first->y - 1][new->first->x] = value;
      add_one(new->first->x, new->first->y - 1, new);
    }
  if (new->first->x > 0 && tab[new->first->y][new->first->x - 1] == UNDEF)
    {
      tab[new->first->y][new->first->x - 1] = value;
      add_one(new->first->x - 1, new->first->y, new);
    }
  if (new->first->x < map->width - 1
      && tab[new->first->y][new->first->x + 1] == UNDEF)
    {
      tab[new->first->y][new->first->x + 1] = value;
      add_one(new->first->x + 1, new->first->y, new);
    }
  if (new->first->y < map->height - 1
      && tab[new->first->y + 1][new->first->x] == UNDEF)
    {
      tab[new->first->y + 1][new->first->x] = value;
      add_one(new->first->x, new->first->y + 1, new);
    }
}

static void	resolve_it(t_utils utils, int **tab, const t_map *map)
{
  int		check;
  t_chain	*tmp;

  check = 0;
  while (check == 0)
    {
      tmp = utils.first;
      check_all_sens(tab, map, &utils, tab[tmp->y][tmp->x] + 1);
      if ((tmp->x > 0 && tab[tmp->y][tmp->x - 1] == START)
	  || (tmp->y > 0 && tab[tmp->y - 1][tmp->x] == START))
	check = 1;
      utils.first = utils.first->next;
      free(tmp);
      if (!utils.first)
	check = 1;
    }
  free_chain(utils.first);
}

void		go_deeper(int x, int y, int **tab, const t_map *map)
{
  t_utils	utils;

  utils.first = NULL;
  if (map->map[0] == 'X' ||
      map->map[map->width * map->height + map->height - 2] == 'X')
    return ;
  add_one(x, y, &utils);
  resolve_it(utils, tab, map);
}
