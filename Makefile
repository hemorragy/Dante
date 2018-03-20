##
## Makefile for dante in /home/antoin_g/rendu/C_prog_elem/dante
##
## Made by Loïs
## Login   <antoin_g@epitech.net>
##
## Started on  Fri May 27 19:27:02 2016 Loïs
## Last update Sat May 28 02:06:47 2016 Loïs
##

LINK	=	make -C

GEN	=	generateur/generateur

DEPTH	=	profondeur/solver

LARGE	=	largeur/solver

ASTAR	=	astar/solver

TOUR	=	tournoi/solver

all:		$(DEPTH) $(LARGE) $(ASTAR) $(TOUR) $(GEN)

$(GEN):
		$(LINK) generateur

$(DEPTH):
		$(LINK) profondeur

$(LARGE):
		$(LINK) largeur

$(ASTAR):
		$(LINK) astar

$(TOUR):
		$(LINK) tournoi

clean:
		$(LINK) generateur clean
		$(LINK) profondeur clean
		$(LINK) largeur clean
		$(LINK) astar clean
		$(LINK) tournoi clean

fclean:		clean
		$(LINK) generateur fclean
		$(LINK) profondeur fclean
		$(LINK) largeur fclean
		$(LINK) astar fclean
		$(LINK) tournoi fclean

re:		fclean all

.PHONY:		all clean fclean re