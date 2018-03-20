/*
** depth.c for depth in /home/antoin_g/rendu/C_prog_elem/dante/profondeur
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Thu Apr 28 03:29:17 2016 Loïs
** Last update Sun May 22 16:35:07 2016 Loïs
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
			       const t_chain *tmp, t_utils *new)
{
  if (tmp->x > 0 && tab[tmp->y][tmp->x - 1] == UNDEF)
    {
      tab[tmp->y][tmp->x - 1] = tab[tmp->y][tmp->x] + 1;
      add_one(tmp->x - 1, tmp->y, new);
    }
  if (tmp->x < map->width - 1 && tab[tmp->y][tmp->x + 1] == UNDEF)
    {
      tab[tmp->y][tmp->x + 1] = tab[tmp->y][tmp->x] + 1;
      add_one(tmp->x + 1, tmp->y, new);
    }
  if (tmp->y > 0 && tab[tmp->y - 1][tmp->x] == UNDEF)
    {
      tab[tmp->y - 1][tmp->x] = tab[tmp->y][tmp->x] + 1;
      add_one(tmp->x, tmp->y - 1, new);
    }
  if (tmp->y < map->height - 1 && tab[tmp->y + 1][tmp->x] == UNDEF)
    {
      tab[tmp->y + 1][tmp->x] = tab[tmp->y][tmp->x] + 1;
      add_one(tmp->x, tmp->y + 1, new);
    }
}

static void	resolve_it(t_utils utils, int **tab, const t_map *map)
{
  int		check;
  t_chain	*tmp;
  t_utils	new;

  check = 0;
  while (check == 0)
    {
      tmp = utils.first;
      new.first = NULL;
      while (tmp)
	{
	  check_all_sens(tab, map, tmp, &new);
	  check = (tmp->x > 0 && tab[tmp->y][tmp->x - 1] == START) ? 1 : check;
	  check = (tmp->y > 0 && tab[tmp->y - 1][tmp->x] == START) ? 1 : check;
	  check = (tmp->x < map->width - 1 &&
		   tab[tmp->y][tmp->x + 1] == START) ? 1 : check;
	  check = (tmp->y < map->height - 1 &&
		   tab[tmp->y + 1][tmp->x] == START) ? 1 : check;
	  tmp = tmp->next;
	}
      free_chain(utils.first);
      utils.first = new.first;
      check = (utils.first == NULL) ? 1 : check;
    }
  free_chain(utils.first);
}

void		go_deeper(int x, int y, int **tab, const t_map *map)
{
  t_utils	utils;

  utils.first = NULL;
  if (map->first->str[0] == 'X' ||
      map->last->str[my_strlen(map->last->str) - 1] == 'X')
    return ;
  add_one(x, y, &utils);
  resolve_it(utils, tab, map);
}
