/*
** my_strdup.c for my_strdup in /home/antoin_g/rendu/C_prog_elem/dante/profondeur
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Thu Apr 28 05:24:45 2016 Loïs
** Last update Thu Apr 28 05:26:30 2016 Loïs
*/

#include "functions.h"

char	*my_strdup(const char *str)
{
  char	*new;
  int	i;

  i = 0;
  new = xmalloc(sizeof(char) * (my_strlen(str) + 1));
  while (str[i])
    {
      new[i] = str[i];
      ++i;
    }
  new[i] = 0;
  return (new);
}
