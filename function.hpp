#ifndef __FUNCTION_HPP
#define __FUNCCTION_HPP

#include <fstream>
typedef struct JOUEUR{
    char type;
    int nb_quart_singe;
}JOUEUR;
int get_nb_mot_dico(std::ifstream &file);
bool verif_joueur(int argc , char *argv[]);
void dico_to_2Darray(char **liste_mots,int nb_mots, std::ifstream &file);
void clear_2Darray(char **liste_mots , int nb_mots);

bool is_in_dico( char **liste_mot ,  char *str, int min , int max);
int naif(char **liste_mot ,  char *str,int nb_mot);
int iteratif(char **liste_mot ,char *str,int nb_mot);
void create_joueurs(JOUEUR *liste_joueurs,char *str);
void clear_joueur_array(JOUEUR *liste_joueurs);


#endif 