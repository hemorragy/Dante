/*
** my_strlen.c for my_strlen in /home/eddy/Rendu/dante/generateur/srcs/utils
**
** Made by Eddy Chouikha
** Login   <eddy@ubuntu>
**
** Started on  Wed May 11 16:44:46 2016 Eddy Chouikha
** Last update Wed May 11 16:45:35 2016 Eddy Chouikha
*/

int		my_strlen(const char *str)
{
  register int	idx;

  idx = 0;
  while (str[idx])
    ++idx;
  return (idx);
}
