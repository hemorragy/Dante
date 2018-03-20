/*
** xmalloc.c for xmalloc in /home/antoin_g/rendu/C_prog_elem/dante/profondeur
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Wed Apr 27 19:39:29 2016 Loïs
** Last update Wed Apr 27 19:45:19 2016 Loïs
*/

#include "functions.h"
#include "defines.h"

void	*xmalloc(size_t size)
{
  void	*new;

  if (!(new = malloc(size)))
    my_error(MALLOC_ERROR);
  return (new);
}
