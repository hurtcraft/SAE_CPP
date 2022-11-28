#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "function.hpp"
using namespace std ;

int get_nb_mot_dico(ifstream &file){
    const int BUFFER_SIZE=256;
    char buffer[BUFFER_SIZE];
    int count = 0;
    file >> setw(256)>> buffer;
    while(file){
        count ++;
        file >> setw(BUFFER_SIZE) >>buffer;
    }
    return count;
}
bool verif_joueur(int argc , char *argv[]){
    if (argc!=2 ){
        cout << "saisir des joueurs H(humain) ou R(robot)"<< endl;
        return false;
    }
    int nb_joueurs=strlen(argv[argc-1]);

    for (size_t i = 0; i < nb_joueurs; i++)
    {
        if (argv[argc-1][i]!='H' && argv[argc-1][i]!='R'){
            cout << "argument invalide saisir H(humain) et R(robot)"<< endl;
            return false;
        }
    }
    if(nb_joueurs<2){
        cout << "nombre de joueurs insuffisant"<< endl;
        return false;
    }
    return true;

}