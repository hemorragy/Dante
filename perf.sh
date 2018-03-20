make -C profondeur
make -C largeur
make -C astar
make -C tournoi
clear
printf "10x10 Parfaite\n"
printf "Profondeur :\n"
time profondeur/solver mazes/10_perfect >result
printf "Largeur :\n"
time largeur/solver mazes/10_perfect >result
printf "Astar :\n"
time astar/solver mazes/10_perfect >result
printf "Tournoi :\n"
time tournoi/solver mazes/10_perfect >result
read && clear
printf "10x10 Imparfaite\n"
printf "Profondeur :\n"
time profondeur/solver mazes/10_imperfect >result
printf "Largeur :\n"
time largeur/solver mazes/10_imperfect >result
printf "Astar :\n"
time astar/solver mazes/10_imperfect >result
printf "Tournoi :\n"
time tournoi/solver mazes/10_imperfect >result
read && clear
printf "100x100 Parfaite\n"
printf "Profondeur :\n"
time profondeur/solver mazes/100_perfect >result
printf "Largeur :\n"
time largeur/solver mazes/100_perfect >result
printf "Astar :\n"
time astar/solver mazes/100_perfect >result
printf "Tournoi :\n"
time tournoi/solver mazes/100_perfect >result
read && clear
printf "100x100 Imparfaite\n"
printf "Profondeur :\n"
time profondeur/solver mazes/100_imperfect >result
printf "Largeur :\n"
time largeur/solver mazes/100_imperfect >result
printf "Astar :\n"
time astar/solver mazes/100_imperfect >result
printf "Tournoi :\n"
time tournoi/solver mazes/100_imperfect >result
read && clear
printf "1000x1000 Parfaite\n"
printf "Profondeur :\n"
time profondeur/solver mazes/1000_perfect >result
printf "Largeur :\n"
time largeur/solver mazes/1000_perfect >result
printf "Astar :\n"
time astar/solver mazes/1000_perfect >result
printf "Tournoi :\n"
time tournoi/solver mazes/1000_perfect >result
read && clear
printf "1000x1000 Imparfaite\n"
printf "Profondeur :\n"
time profondeur/solver mazes/1000_imperfect >result
printf "Largeur :\n"
time largeur/solver mazes/1000_imperfect >result
printf "Astar :\n"
time astar/solver mazes/1000_imperfect >result
printf "Tournoi :\n"
time tournoi/solver mazes/1000_imperfect >result
read && clear
make -C profondeur fclean
make -C largeur fclean
make -C astar fclean
make -C tournoi fclean
rm result
clear
