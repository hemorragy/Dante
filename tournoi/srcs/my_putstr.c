/*
** my_putstr.c for my_putstr in /home/antoin_g/rendu/C_prog_elem/dante/profondeur
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Thu Apr 28 02:25:03 2016 Loïs
** Last update Mon May  9 14:49:59 2016 Loïs
*/

#include <unistd.h>
#include "functions.h"

void	my_putstr(const char *str)
{
  int	i;

  i = write(1, str, my_strlen(str));
  (void)i;
}
