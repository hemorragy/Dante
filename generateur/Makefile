##
## Makefile for generateur in /home/eddy/Rendu/dante/generateur
##
## Made by Eddy Chouikha
## Login   <eddy@epitech.net>
##
## Started on  Wed May 11 15:20:12 2016 Eddy Chouikha
## Last update Sun May 22 01:06:45 2016 Eddy Chouikha
##

CC		= gcc

RM		= rm -rf

NAME		= generateur

CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -Iinclude

GEN		= srcs/gen/

UTILS		= srcs/utils/

SRCS		= srcs/main.c \
		$(UTILS)my_strisnum.c \
		$(UTILS)my_error.c \
		$(UTILS)my_getnbr.c \
		$(UTILS)my_strlen.c \
		$(GEN)gen.c \
		$(GEN)get_neighbours.c

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
