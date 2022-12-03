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

void dico_to_2Darray(char **liste_mots,int nb_mots, ifstream &file){
    file.clear();
    file.seekg(0); // on set le curseur au début du fichier pour pouvoir reparcourir le fichier 
    const int BUFFER_SIZE=256;
    char buffer[BUFFER_SIZE];
    int longueur_mot;
    int count=0;
    file >> setw(256)>> buffer;
    while(file){
        longueur_mot=strlen(buffer);
        liste_mots[count]= new char[longueur_mot];
        cout<< liste_mots[count];

        liste_mots[count]=buffer;
        
        file >> setw(BUFFER_SIZE) >>buffer;
        count++;
    }
}

void clear_2Darray(char **liste_mots , int nb_mots){
    for (size_t i = 0; i < nb_mots; i++)
    {
        delete [] liste_mots[i];
    }
    delete []liste_mots;
    
}