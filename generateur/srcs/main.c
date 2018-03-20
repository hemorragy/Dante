/*
** main.c for main in /home/eddy/Rendu/dante/generateur/srcs
**
** Made by Eddy Chouikha
** Login   <eddy@ubuntu>
**
** Started on  Wed May 11 15:24:27 2016 Eddy Chouikha
** Last update Sun May 22 01:04:20 2016 Eddy Chouikha
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "defines.h"
#include "functions.h"

static void	prep_maze(t_maze *maze)
{
  register int	idx;

  idx = 0;
  while (maze->buffer[idx])
    {
      if (maze->buffer[idx] != '\n' && maze->buffer[idx] != 'X')
	maze->buffer[idx] = '*';
      ++idx;
    }
  maze->buffer[(maze->w + 1) * maze->h - 2] = '*';
}

static int	init_maze(t_maze *maze, char **av)
{
  int		idx;

  maze->pos.x = 0;
  maze->pos.y = 0;
  maze->perf = 0;
  maze->w = my_getnbr(av[1]);
  maze->h = my_getnbr(av[2]);
  if (av[3] && (!strcmp(av[3], "parfait")))
    maze->perf = 1;
  else if (av[3])
    return (my_error(USAGE));
  if (maze->w < W_MIN || maze->h < H_MIN)
    return (my_error(INVALID_SIZE));
  if (!(maze->buffer = malloc(sizeof(char) * (((maze->w + 1) * maze->h)))))
    return (my_error(MALLOC_FAILED));
  maze->buffer = memset(maze->buffer, 'X', (maze->w + 1) * maze->h);
  idx = maze->w;
  maze->buffer[0] = '*';
  while (idx <= ((maze->w + 1) * (maze->h - 1)))
    {
      maze->buffer[idx] = '\n';
      idx += (maze->w + 1);
    }
  maze->buffer[((maze->w + 1) * maze->h) - 1] = '\0';
  return (TRUE);
}

static int	check_args(int ac, char **av)
{
  if (ac < MIN_ARGS || ac > MAX_ARGS)
    return (my_error(USAGE));
  if ((my_strisnum(av[1]) != 1) || (my_strisnum(av[2]) != 1))
    return (my_error(INVALID_TYPE));
  return (TRUE);
}

int		main(int ac, char **av)
{
  t_maze	maze;

  srand(time(NULL));
  if ((!check_args(ac, av)) || (!(init_maze(&maze, av))))
    return (EXIT_FAILURE);
  gen_maze(&maze);
  prep_maze(&maze);
  printf("%s", maze.buffer);
  free(maze.buffer);
  return (EXIT_SUCCESS);
}
