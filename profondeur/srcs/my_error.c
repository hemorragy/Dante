/*
** my_error.c for my_error in /home/antoin_g/rendu/C_prog_elem/dante/profondeur
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Wed Apr 27 19:45:24 2016 Loïs
** Last update Thu May  5 15:11:27 2016 Loïs
*/

#include <unistd.h>
#include "functions.h"

void	my_error(const char *str)
{
  (void)write(2, str, my_strlen(str));
  exit(EXIT_FAILURE);
}
