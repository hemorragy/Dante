/*
** depth.c for depth in /home/antoin_g/rendu/C_prog_elem/dante
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Wed Apr 27 18:41:00 2016 Loïs
** Last update Sun May 22 17:27:19 2016 Loïs
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "functions.h"
#include "defines.h"

static int	**creat_tab(const t_map *map)
{
  int		**tab;
  register int	idx;
  register int	id;
  register int	i;

  tab = xmalloc(sizeof(int *) * (map->height + 1));
  i = 0;
  id = 0;
  while (map->map[i])
    {
      tab[id] = xmalloc(sizeof(int) * (map->width));
      idx = 0;
      while (map->map[i] && map->map[i] != '\n')
	{
	  tab[id][idx] = (map->map[i] == 'X') ? WALL : UNDEF;
	  ++i;
	  ++idx;
	}
      ++id;
      i = (map->map[i]) ? i + 1 : i;
    }
  tab[id] = NULL;
  return (tab);
}

static void	line_parsing(t_map *map)
{
  register int	i;

  map->width = 0;
  map->height = 0;
  i = 0;
  while (map->map[i])
    {
      if (map->map[i] != 'X' && map->map[i] != '*' && map->map[i] != '\n')
	my_error(MAZE_ERROR_CHAR);
      if (map->map[i] == '\n')
	{
	  ++map->height;
	  if (!map->width)
	    map->width = i;
	  else if (i % (map->height * map->width + map->height - 1) != 0)
	    my_error(MAZE_ERROR_FORM);
	}
      ++i;
    }
  if (!map->width)
    map->width = i;
  ++map->height;
  if (map->width > 0 && i % (map->height * map->width + map->height - 1) != 0)
    my_error(MAZE_ERROR_FORM);
}

static void	recup_map(const char *file, t_map *map)
{
  struct stat	detail;
  int		fd;
  int		end;

  if ((fd = open(file, O_RDONLY)) == -1)
    my_error(OPEN_ERROR);
  if (stat(file, &detail))
    my_error(STAT_ERROR);
  map->map = xmalloc(sizeof(char) * (detail.st_size + 1));
  if ((end = read(fd, map->map, detail.st_size)) == -1)
    my_error(READ_ERROR);
  map->map[end] = 0;
  line_parsing(map);
  (void)close(fd);
}

int		main(int ac, char **av)
{
  t_map		map;
  int		**tab;

  if (ac != 2)
    my_error(USAGE);
  recup_map(av[1], &map);
  tab = creat_tab(&map);
  if (!map.width)
    return (1);
  if (!recheck_map(tab, &map))
    go_deeper(map.width - 1, map.height - 1, tab, &map);
  set_path((const int **)tab, &map);
  if (map.map[0] == 'o')
    {
      my_putstr(map.map);
      my_putstr("\n");
    }
  else
    my_putstr(NO_PATH);
  free_maps(&map, tab);
  return (0);
}
