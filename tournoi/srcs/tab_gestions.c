/*
** tab_gestions.c for tab_gestions in /home/antoin_g/rendu/C_prog_elem/dante/profondeur
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Thu Apr 28 01:58:21 2016 Loïs
** Last update Fri May  6 05:05:43 2016 Loïs
*/

#include "defines.h"
#include "functions.h"

void	free_maps(t_map *map, int **tab)
{
  int	i;

  i = 0;
  while (i < map->height)
    {
      free(tab[i]);
      ++i;
    }
  free(tab);
  free(map->map);
}

int	recheck_map(int	**tab, const t_map *map)
{
  if (tab[0][0] == WALL || tab[map->height - 1][map->width - 1] == WALL)
    return (1);
  tab[0][0] = START;
  tab[map->height - 1][map->width - 1] = END;
  return (0);
}
