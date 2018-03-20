/*
** functions.h for functions in /home/chouik_e/Rendu/xTODO/dante/astar/include
**
** Made by Eddy Chouikha
** Login   <chouik_e@chouik-e-pc>
**
** Started on  Wed Apr 27 19:15:29 2016 Eddy Chouikha
** Last update Thu May  5 20:07:02 2016 Loïs
*/

#ifndef FUNCTIONS_H_
# define FUNCTIONS_H_

# include <stdlib.h>
# include "structs.h"

int	my_strlen(const char *str);
int	recheck_map(int **tab, const t_map *map);
int	**creat_tab(const t_map *map);
void	my_putstr(const char *str);
void	my_error(const char *str);
void	go_deeper(int x, int y, int **tab, const t_map *map);
char	*get_next_line(const int fd);
char	*my_strdup(const char *str);
void	*xmalloc(size_t size);
char	**create_map(const t_map *map);
void	free_maps(t_map *map, int **tab);
void	set_path(const int **path, char **tab, const t_map *map);
void	my_mx(t_pos *tmp, const t_pos *pos, const t_map *map, const int **path);
void	my_px(t_pos *tmp, const t_pos *pos, const t_map *map, const int **path);
void	my_my(t_pos *tmp, const t_pos *pos, const t_map *map, const int **path);
void	my_py(t_pos *tmp, const t_pos *pos, const t_map *map, const int **path);
void	check_all_sens(int **tab, const t_map *map,
		       const t_chain *tmp, t_prio *prio);
int	check_next(int **tab, const t_map *map,
		   const t_chain *tmp, t_prio *prio);
int	go_back(t_prio *prio, int check, int **tab, const t_map *map);

#endif /* !FUNCTIONS_H_ */
