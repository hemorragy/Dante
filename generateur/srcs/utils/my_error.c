/*
** my_error.c for my_error in /home/eddy/Rendu/dante/generateur/srcs
**
** Made by Eddy Chouikha
** Login   <eddy@ubuntu>
**
** Started on  Wed May 11 15:40:27 2016 Eddy Chouikha
** Last update Wed May 11 18:42:45 2016 Eddy Chouikha
*/

#include <unistd.h>
#include <stdlib.h>
#include "defines.h"
#include "functions.h"

int	my_error(const char *msg)
{
  (void)write(2, msg, my_strlen(msg));
  return (FALSE);
}
