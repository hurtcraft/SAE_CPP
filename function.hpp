#ifndef __FUNCTION_HPP
#define __FUNCCTION_HPP

#include <fstream>
;
int get_nb_mot_dico(std::ifstream &file);
bool verif_joueur(int argc , char *argv[]);
void dico_to_2Darray(char **liste_mots,int nb_mots, std::ifstream &file);
void clear_2Darray(char **liste_mots , int nb_mots);
#endif 