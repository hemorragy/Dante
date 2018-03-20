/*
** my_strisnum.c for my_strisnum in /home/eddy/Rendu/dante/generateur/srcs/utils
**
** Made by Eddy Chouikha
** Login   <eddy@ubuntu>
**
** Started on  Wed May 11 16:30:53 2016 Eddy Chouikha
** Last update Wed May 11 18:13:38 2016 Eddy Chouikha
*/

int	my_strisnum(const char *str)
{
  int	idx;

  idx = 0;
  if (str[idx] != '-')
    idx++;
  while (str[idx])
    {
      if (str[idx] < '0' || str[idx] > '9')
	return (0);
      ++idx;
    }
  return (1);
}
