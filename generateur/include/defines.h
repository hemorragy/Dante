/*
 ** defines.h for defines in /home/eddy/Rendu/dante/generateur/include
 **
 ** Made by Eddy Chouikha
 ** Login   <eddy@ubuntu>
 **
 ** Started on  Wed May 11 15:30:57 2016 Eddy Chouikha
** Last update Sun May 22 01:02:24 2016 Eddy Chouikha
 */

#ifndef DEFINES_H_
# define DEFINES_H_

/*
** ENUM
*/
enum	e_moves
{
  L,
  T,
  R,
  B
};

/*
** VALUES
*/
# define TRUE 1
# define FALSE 0
# define H_MIN 4
# define W_MIN 4
# define MIN_ARGS 3
# define MAX_ARGS 4
# define DENS 5

/*
** MESSAGES
*/
# define USAGE "./generateur x y [parfait]\n"
# define INVALID_TYPE "Error: x and y must be integers\n"
# define INVALID_SIZE "Error: maze size must be 4x4 at least\n"
# define MALLOC_FAILED "Error: malloc failed\n"

#endif /* !DEFINES_H_ */
