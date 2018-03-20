/*
** my_getnbr.c for my_getnbr in /home/chouik_e/Rendu/xTODO/dante/mazes/generator/perfect/srcs/utils
**
** Made by Eddy Chouikha
** Login   <chouik_e@chouik-e-pc>
**
** Started on  Thu Apr 28 04:56:28 2016 Eddy Chouikha
** Last update Thu Apr 28 05:14:29 2016 Eddy Chouikha
*/

int	my_getnbr(const char *str)
{
  int	nbr;
  int	idx;

  idx = 1;
  if (str[0] != '-')
    nbr = str[0] - 48;
  else
    {
      nbr = str[1] - 48;
      idx++;
    }
  while (str[idx])
    {
      nbr = nbr * 10 + (str[idx] - 48);
      ++idx;
    }
  if (str[0] == '-')
    return (-nbr);
  return (nbr);
}
