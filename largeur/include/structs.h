/*
** structs.h for structs in /home/chouik_e/Rendu/xTODO/dante/astar/include
**
** Made by Eddy Chouikha
** Login   <chouik_e@chouik-e-pc>
**
** Started on  Wed Apr 27 19:15:39 2016 Eddy Chouikha
** Last update Mon May  2 17:51:59 2016 Loïs
*/

#ifndef STRUCTS_H_
# define STRUCTS_H_

typedef struct		s_list
{
  char			*str;
  struct s_list		*next;
}			t_list;

typedef struct		s_map
{
  int			width;
  int			height;
  t_list		*first;
  t_list		*last;
}			t_map;

typedef struct		s_gnl
{
  int			tmp;
  int			test;
  char			*temp;
  char			*line;
}			t_gnl;

typedef struct		s_pos
{
  int			x;
  int			y;
  int			value;
}			t_pos;

typedef struct		s_chain
{
  int			x;
  int			y;
  struct s_chain	*next;
}			t_chain;

typedef struct		s_utils
{
  t_chain		*first;
  t_chain		*last;
}			t_utils;

typedef void	(*t_rew)(t_pos *, const t_pos *, const t_map *, const int **);

#endif /* !STRUCTS_H_ */
