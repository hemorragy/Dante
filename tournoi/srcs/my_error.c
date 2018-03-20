/*
** my_error.c for my_error in /home/antoin_g/rendu/C_prog_elem/dante/profondeur
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Wed Apr 27 19:45:24 2016 Loïs
** Last update Mon May  9 14:50:34 2016 Loïs
*/

#include <unistd.h>
#include "functions.h"

void	my_error(const char *str)
{
  int	i;

  i = write(2, str, my_strlen(str));
  (void)i;
  exit(EXIT_FAILURE);
}
