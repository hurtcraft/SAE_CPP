#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "function.hpp"

using namespace std ;

int main(int argc , char *argv[]){
    
    /*
    if (!verif_joueur(argc,argv)){
        exit(EXIT_FAILURE);
    }
    */
    ifstream file("ods4.txt");
    
    int nb_mots=get_nb_mot_dico(file);

    char **liste_mots;

    liste_mots=new char*[nb_mots];

    dico_to_2Darray(liste_mots,nb_mots,file);
    cout << liste_mots[0] <<liste_mots[1];
    clear_2Darray(liste_mots,nb_mots);
    
    file.close();
    return 0;
}

