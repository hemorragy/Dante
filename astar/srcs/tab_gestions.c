/*
** tab_gestions.c for tab_gestions in /home/antoin_g/rendu/C_prog_elem/dante/profondeur
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Thu Apr 28 01:58:21 2016 Loïs
** Last update Mon May  2 18:05:23 2016 Loïs
*/

#include "defines.h"
#include "functions.h"

void		free_maps(t_map *map, int **tab)
{
  t_list	*current;
  t_list	*tmp;
  int		i;

  i = 0;
  current = map->first;
  while (current)
    {
      tmp = current;
      current = current->next;
      free(tab[i]);
      free(tmp->str);
      free(tmp);
      ++i;
    }
  free(tab);
}

char		**create_map(const t_map *map)
{
  char		**tab;
  t_list	*tmp;
  int		i;

  tab = xmalloc(sizeof(char *) * (map->height + 1));
  tmp = map->first;
  i = 0;
  while (tmp)
    {
      tab[i] = my_strdup(tmp->str);
      tmp = tmp->next;
      ++i;
    }
  tab[i] = NULL;
  return (tab);
}

int	recheck_map(int	**tab, const t_map *map)
{
  if (tab[0][0] == WALL || tab[map->height - 1][map->width - 1] == WALL)
    return (1);
  tab[0][0] = START;
  tab[map->height - 1][map->width - 1] = END;
  return (0);
}

int		**creat_tab(const t_map *map)
{
  int		**tab;
  t_list	*tmp;
  register int	idx;
  int		i;

  tab = xmalloc(sizeof(int *) * (map->height + 1));
  tmp = map->first;
  i = 0;
  while (tmp)
    {
      tab[i] = xmalloc(sizeof(int) * map->width);
      idx = 0;
      while (tmp->str[idx])
	{
	  tab[i][idx] = (tmp->str[idx] == 'X') ? WALL : UNDEF;
	  ++idx;
	}
      tmp = tmp->next;
      ++i;
    }
  return (tab);
}
