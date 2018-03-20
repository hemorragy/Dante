/*
** find_path.c for find_path in /home/antoin_g/rendu/C_prog_elem/dante/profondeur
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Mon May  2 15:36:51 2016 Loïs
** Last update Sun May 22 16:36:48 2016 Loïs
*/

#include "functions.h"
#include "defines.h"

static const t_rew	g_rew[] =
  {
    &my_mx,
    &my_px,
    &my_my,
    &my_py,
    NULL
  };

static void	set_new(t_pos *pos, const int **path,
			const t_map *map)
{
  t_pos		tmp;
  int		i;

  pos->value = -1;
  tmp.x = pos->x;
  tmp.y = pos->y;
  tmp.value = pos->value;
  i = 0;
  while (g_rew[i])
    {
      g_rew[i](&tmp, pos, map, path);
      ++i;
    }
  pos->x = tmp.x;
  pos->y = tmp.y;
  pos->value = tmp.value;
}

void		set_path(const int **path, t_map *map)
{
  t_pos		pos;

  pos.x = 0;
  pos.y = 0;
  pos.value = -1;
  if (map->map[0] == 'X' ||
      map->map[map->width * map->height + map->height - 1] == 'X')
    return ;
  while (path[pos.y][pos.x] != END)
    {
      map->map[pos.y * map->width + pos.x + pos.y] = 'o';
      set_new(&pos, path, map);
      if (path[pos.y][pos.x] < 0)
	{
	  map->map[0] = '*';
	  return ;
	}
    }
  map->map[map->width * map->height + map->height - 2] = 'o';
}
