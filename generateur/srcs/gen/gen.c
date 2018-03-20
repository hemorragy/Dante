/*
** gen.c for gen in /home/eddy/Rendu/dante/generateur/srcs/gen
**
** Made by Eddy Chouikha
** Login   <eddy@ubuntu>
**
** Started on  Wed May 11 19:05:11 2016 Eddy Chouikha
** Last update Sun May 22 00:50:12 2016 Eddy Chouikha
*/

#include <stdlib.h>
#include "defines.h"
#include "functions.h"

static void	get_rand_move(bool *moves)
{
  int	rnd;
  int	idx;
  int	moves_range;

  idx = 0;
  moves_range = moves[L] + moves[T] + moves[R] + moves[B];
  rnd = rand() % moves_range;
  if (moves_range != 1)
    {
      while (idx < 4)
	{
	  if (moves[idx] == 1 && rnd != 0)
	    {
	    moves[idx] = 0;
	    rnd--;
	    }
	  ++idx;
	}
    }
}

static void	get_prev(t_maze *maze, int *idx)
{
  if (maze->buffer[*idx] == 'L')
    {
      (*idx)++;
      (maze->pos.x)++;
    }
  else if (maze->buffer[*idx] == 'T')
    {
      (*idx) += (maze->w + 1);
      (maze->pos.y)++;
    }
  else if (maze->buffer[*idx] == 'R')
    {
      (*idx)--;
      (maze->pos.x)--;
    }
  else if (maze->buffer[*idx] == 'B')
    {
      (*idx) -= (maze->w + 1);
      (maze->pos.y)--;
    }
}

static void	set_move(t_maze *maze, int *idx, bool *moves)
{
  if (moves[L])
    {
      (*idx)--;
      (maze->pos.x)--;
      maze->buffer[*idx] = 'L';
    }
  else if (moves[T])
    {
      (*idx) -= (maze->w + 1);
      (maze->pos.y)--;
      maze->buffer[*idx] = 'T';
    }
  else if (moves[R])
    {
      (*idx)++;
      (maze->pos.x)++;
      maze->buffer[*idx] = 'R';
    }
  else if (moves[B])
    {
      (*idx) += (maze->w + 1);
      (maze->pos.y)++;
      maze->buffer[*idx] = 'B';
    }
}

static bool	is_exit_found(t_maze *maze, int *idx)
{
  if ((maze->pos.x == maze->w - 2 && maze->pos.y == maze->h - 1) ||
      (maze->pos.x == maze->w - 1 && maze->pos.y == maze->h - 2))
    {
      get_prev(maze, idx);
      return (TRUE);
    }
  return (FALSE);
}

void	gen_maze(t_maze *maze)
{
  int		idx;
  int		nb_mov;
  bool		exit_found;
  bool		moves[4];

  idx = 0;
  nb_mov = 0;
  exit_found = 0;
  while ((nb_mov < maze->w * maze->h * 0.44) || (!(exit_found)))
    {
      if (!exit_found)
	exit_found = is_exit_found(maze, &idx);
      get_neighbours(maze, &idx, moves);
      if (moves[L] || moves[T] || moves[R] || moves[B])
	{
	  ++nb_mov;
	  get_rand_move(moves);
	  set_move(maze, &idx, moves);
	}
      else
	get_prev(maze, &idx);
      if (idx == 0 && exit_found)
	nb_mov = maze->w * maze->h;
    }
}
