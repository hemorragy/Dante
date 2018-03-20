/*
** my_strcmp.c for my_strcmp in /home/eddy/Rendu/dante/generateur/srcs/utils
**
** Made by Eddy Chouikha
** Login   <eddy@ubuntu>
**
** Started on  Wed May 11 16:40:05 2016 Eddy Chouikha
** Last update Sun May 22 00:58:00 2016 Eddy Chouikha
*/

#include "defines.h"

int	my_strcmp(const char *s1, const char *s2)
{
  int	idx;

  idx = 0;
  while (s1[idx] && s2[idx])
    {
      if (s1[idx] != s2[idx])
	return (FALSE);
      ++idx;
    }
  if (s1[idx] || s2[idx])
    return (FALSE);
  return (TRUE);
}
