##
## Makefile for dante in /home/chouik_e/Rendu/xTODO/dante/astar
##
## Made by Eddy Chouikha
## Login   <chouik_e@epitech.net>
##
## Started on  Wed Apr 27 19:09:37 2016 Eddy Chouikha
## Last update Thu May  5 16:23:53 2016 Loïs
##

CC	=	gcc

RM	=	rm -rf

NAME	=	solver

CFLAGS	=	-Wextra -Wall -Werror
CFLAGS	+=	-Iinclude

SRCS	=	srcs/main.c \
		srcs/my_putstr.c \
		srcs/my_strlen.c \
		srcs/depth.c \
		srcs/rewrite_path.c \
		srcs/find_path.c \
		srcs/xmalloc.c \
		srcs/tab_gestions.c \
		srcs/my_strdup.c \
		srcs/my_error.c \
		srcs/get_next_line.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
