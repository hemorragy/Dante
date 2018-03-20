/*
** structs.h for structs in /home/eddy/Rendu/dante/generateur/include
**
** Made by Eddy Chouikha
** Login   <eddy@ubuntu>
**
** Started on  Wed May 11 15:31:17 2016 Eddy Chouikha
** Last update Sat May 21 23:57:39 2016 Eddy Chouikha
*/

#ifndef STRUCTS_H_
# define STRUCTS_H_

typedef struct		s_pos
{
  int			x;
  int			y;
}			t_pos;

typedef struct		s_maze
{
  char			*buffer;
  int			w;
  int			h;
  t_pos			pos;
  int			perf;
}			t_maze;

#endif /* !STRUCTS_H_ */
