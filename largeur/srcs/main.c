/*
** depth.c for depth in /home/antoin_g/rendu/C_prog_elem/dante
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Wed Apr 27 18:41:00 2016 Loïs
** Last update Sun May 22 17:17:49 2016 Loïs
*/

#include <fcntl.h>
#include <unistd.h>
#include "functions.h"
#include "defines.h"

static void	print_map(const t_map *map, const int **path)
{
  char		**tab;
  int		i;

  tab = create_map(map);
  set_path(path, tab, map);
  i = 0;
  if (tab[0][0] == 'o')
    while (tab[i])
      {
	my_putstr(tab[i]);
	my_putstr("\n");
	free(tab[i]);
	++i;
      }
  else
    my_putstr(NO_PATH);
  free(tab);
}

static void	line_parsing(const t_map *map)
{
  register int	i;

  i = 0;
  while (map->last->str[i])
    {
      if (map->last->str[i] != 'X' && map->last->str[i] != '*')
	my_error(MAZE_ERROR_CHAR);
      ++i;
    }
  if (i != map->width)
    my_error(MAZE_ERROR_FORM);
}

static void	stock_map(t_map *map, char *str, int *test)
{
  t_list	*new;

  new = xmalloc(sizeof(t_list));
  new->str = str;
  new->next = NULL;
  if (*test == 0)
    {
      *test = 1;
      map->first = new;
      map->width = my_strlen(new->str);
    }
  else
    map->last->next = new;
  map->last = new;
  ++map->height;
}

static void	recup_map(const char *file, t_map *map)
{
  int		fd;
  int		test;
  char		*str;

  test = 0;
  if ((fd = open(file, O_RDONLY)) == -1)
    my_error(OPEN_ERROR);
  while ((str = get_next_line(fd)))
    {
      stock_map(map, str, &test);
      line_parsing(map);
    }
  (void)close(fd);
}

int		main(int ac, char **av)
{
  t_map		map;
  int		**tab;

  if (ac != 2)
    my_error(USAGE);
  map.height = 0;
  map.first = NULL;
  map.last = NULL;
  recup_map(av[1], &map);
  tab = creat_tab(&map);
  if (!recheck_map(tab, &map))
    go_deeper(map.width - 1, map.height - 1, tab, &map);
  print_map(&map, (const int **)tab);
  free_maps(&map, tab);
  return (0);
}
