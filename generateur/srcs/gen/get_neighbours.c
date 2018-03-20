/*
** get_neighbours.c for get_neighbours in /home/eddy/Rendu/dante/generateur/srcs/gen
**
** Made by Eddy Chouikha
** Login   <eddy@ubuntu>
**
** Started on  Sun May 22 00:21:29 2016 Eddy Chouikha
** Last update Sun May 22 00:54:18 2016 Eddy Chouikha
*/

#include <stdlib.h>
#include <stdbool.h>
#include "defines.h"
#include "structs.h"

static void	get_basic_neighbours(t_maze *maze, int *idx, bool *moves)
{
  ((maze->pos.x != 0) && (maze->buffer[(*idx) - 1] == 'X')) ?
    (moves[L] = 1) : (moves[L] = 0);
  ((maze->pos.y != 0) && (maze->buffer[(*idx) - maze->w - 1] == 'X')) ?
    (moves[T] = 1) : (moves[T] = 0);
  ((maze->pos.x != maze->w - 1) && (maze->buffer[(*idx) + 1] == 'X')) ?
    (moves[R] = 1) : (moves[R] = 0);
  ((maze->pos.y != maze->h - 1) &&
   (maze->buffer[(*idx) + maze->w + 1] == 'X')) ?
    (moves[B] = 1) : (moves[B] = 0);
}

static void	get_imperf_neighbours(t_maze *maze, int *idx, bool *moves)
{
  get_basic_neighbours(maze, idx, moves);
  if (moves[L])
    ((maze->pos.x == 1 || maze->buffer[(*idx) - 2] == 'X') &&
     (maze->pos.y == 0 || maze->buffer[(*idx) - maze->w - 2] == 'X') &&
     (maze->pos.y == maze->h - 1 || maze->buffer[(*idx) + maze->w] == 'X')) ?
      (moves[L] = 1) : ((rand() % DENS == 0) ? (moves[L] = 1) : (moves[L] = 0));
  if (moves[T])
   ((maze->pos.x == 0 || maze->buffer[(*idx) - maze->w - 2] == 'X') &&
    (maze->pos.x == maze->w - 1 || maze->buffer[(*idx) - maze->w] == 'X') &&
    (maze->pos.y == 1 || maze->buffer[(*idx) - 2 * (maze->w + 1)] == 'X')) ?
    (moves[T] = 1) : ((rand() % DENS == 0) ? (moves[T] = 1) : (moves[T] = 0));
  if (moves[R])
   ((maze->pos.x == maze->w - 2 || maze->buffer[(*idx) + 2] == 'X') &&
    (maze->pos.y == 0 || maze->buffer[(*idx) - maze->w] == 'X') &&
    (maze->pos.y == maze->h - 1 ||
     maze->buffer[(*idx) + maze->w + 2] == 'X')) ?
    (moves[R] = 1) : ((rand() % DENS == 0) ? (moves[R] = 1) : (moves[R] = 0));
  if (moves[B])
   ((maze->pos.x == 0 || maze->buffer[(*idx) + maze->w] == 'X') &&
    (maze->pos.x == maze->w - 1 || maze->buffer[(*idx) + maze->w + 2] == 'X') &&
    (maze->pos.y == maze->h - 2 ||
     maze->buffer[(*idx) + 2 * (maze->w + 1)] == 'X')) ?
    (moves[B] = 1) : ((rand() % DENS == 0) ? (moves[B] = 1) : (moves[B] = 0));
}

static void	get_perf_neighbours(t_maze *maze, int *idx, bool *moves)
{
  ((maze->pos.x != 0) && (maze->buffer[(*idx) - 1] == 'X') &&
   ((maze->pos.x == 1 || maze->buffer[(*idx) - 2] == 'X') &&
    (maze->pos.y == 0 || maze->buffer[(*idx) - maze->w - 2] == 'X') &&
    (maze->pos.y == maze->h - 1 || maze->buffer[(*idx) + maze->w] == 'X'))) ?
    (moves[L] = 1) : (moves[L] = 0);
  ((maze->pos.y != 0) && (maze->buffer[(*idx) - maze->w - 1] == 'X') &&
   ((maze->pos.x == 0 || maze->buffer[(*idx) - maze->w - 2] == 'X') &&
    (maze->pos.x == maze->w - 1 || maze->buffer[(*idx) - maze->w] == 'X') &&
    (maze->pos.y == 1 || maze->buffer[(*idx) - 2 * (maze->w + 1)] == 'X'))) ?
    (moves[T] = 1) : (moves[T] = 0);
  ((maze->pos.x != maze->w - 1) && (maze->buffer[(*idx) + 1] == 'X') &&
   ((maze->pos.x == maze->w - 2 || maze->buffer[(*idx) + 2] == 'X') &&
    (maze->pos.y == 0 || maze->buffer[(*idx) - maze->w] == 'X') &&
    (maze->pos.y == maze->h - 1 ||
     maze->buffer[(*idx) + maze->w + 2] == 'X'))) ?
    (moves[R] = 1) : (moves[R] = 0);
  ((maze->pos.y != maze->h - 1) &&
   (maze->buffer[(*idx) + maze->w + 1] == 'X') &&
   ((maze->pos.x == 0 || maze->buffer[(*idx) + maze->w] == 'X') &&
    (maze->pos.x == maze->w - 1 || maze->buffer[(*idx) + maze->w + 2] == 'X') &&
    (maze->pos.y == maze->h - 2 ||
     maze->buffer[(*idx) + 2 * (maze->w + 1)] == 'X'))) ?
    (moves[B] = 1) : (moves[B] = 0);
}

void	get_neighbours(t_maze *maze, int *idx, bool *moves)
{
  if (maze->perf)
    get_perf_neighbours(maze, idx, moves);
  else
    get_imperf_neighbours(maze, idx, moves);
}
