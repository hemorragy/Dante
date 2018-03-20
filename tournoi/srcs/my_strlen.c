/*
** my_strlen.c for my_strlen in /home/antoin_g/rendu/C_prog_elem/dante/profondeur
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Wed Apr 27 19:48:42 2016 Loïs
** Last update Wed Apr 27 19:49:30 2016 Loïs
*/

int		my_strlen(const char *str)
{
  register int	i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}
