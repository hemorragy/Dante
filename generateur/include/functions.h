/*
** functions.h for functions in /home/eddy/Rendu/dante/generateur/include
**
** Made by Eddy Chouikha
** Login   <eddy@ubuntu>
**
** Started on  Wed May 11 15:31:09 2016 Eddy Chouikha
** Last update Sun May 22 00:27:08 2016 Eddy Chouikha
*/

#ifndef FUNCTIONS_H_
# define FUNCTIONS_H_

#include <stdbool.h>
#include "structs.h"

/*
** UTILS
*/
int	my_error(const char *msg);
int	my_getnbr(const char *str);
int	my_strisnum(const char *str);
int	my_strlen(const char *str);
/*
** GEN
*/
void	gen_maze(t_maze *maze);
void	get_neighbours(t_maze *maze, int *idx, bool *moves);

#endif /* !FUNCTIONS_H_ */
