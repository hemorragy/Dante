/*
** defines.h for defines in /home/chouik_e/Rendu/xTODO/dante/astar/include
**
** Made by Eddy Chouikha
** Login   <chouik_e@chouik-e-pc>
**
** Started on  Wed Apr 27 19:15:46 2016 Eddy Chouikha
** Last update Sun May 22 17:20:40 2016 Loïs
*/

#ifndef DEFINES_H_
# define DEFINES_H_

#ifndef READ_SIZE
# define READ_SIZE (256)
#endif /* !READ_SIZE */

# define MAZE_ERROR_CHAR "Error : maze contain a wrong character\n"
# define MAZE_ERROR_FORM "Error : maze isn't rectangle\n"
# define MALLOC_ERROR "Error : Malloc failure\n"
# define OPEN_ERROR "Error : Open failure\n"
# define USAGE "Usage : ./solver file\n"
# define NO_PATH "No solution found\n"

enum		e_map
  {
    WALL	= -1,
    START	= -3,
    END		= 0,
    UNDEF	= -2
  };

#endif /* !DEFINES_H_ */
