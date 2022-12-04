#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "function.hpp"
#include <chrono>

using namespace std ;

int main(int argc , char *argv[]){
    /*
    if (!verif_joueur(argc,argv)){
        exit(EXIT_FAILURE);
    }
    */
    ifstream file("ods4.txt");
    const int NB_JOUEUR=strlen(argv[1]);
    JOUEUR *liste_joueurs=new JOUEUR[NB_JOUEUR];
    //int nb_mots=get_nb_mot_dico(file);
    const int NB_MOTS=369085;
    char **liste_mots=NULL;
    liste_mots=new char*[NB_MOTS];
    dico_to_2Darray(liste_mots,NB_MOTS,file);
    file.close();
    create_joueurs(liste_joueurs,argv[1]);
    



    clear_joueur_array(liste_joueurs);
    clear_2Darray(liste_mots,NB_MOTS);
    return 0;
}

