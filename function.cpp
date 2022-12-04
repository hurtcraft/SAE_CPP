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
    /*
    file.clear();
    file.seekg(0); // on set le curseur au début du fichier pour pouvoir reparcourir le fichier 
    */
    const int BUFFER_SIZE=256;
    char buffer[BUFFER_SIZE];
    int longueur_mot;
    int count=0;
    file >> setw(256)>> buffer;
    while(file){
        
        longueur_mot=strlen(buffer)+1;
        liste_mots[count]= new char[longueur_mot];
        
        strncpy(liste_mots[count],buffer,longueur_mot);

        //cout<< liste_mots[count]<< endl;
        
        file >> setw(BUFFER_SIZE) >>buffer;
        count++;
    }
}

void clear_2Darray(char **liste_mots , int nb_mots){
    for (size_t i = 0; i < nb_mots; i++)
    {
        delete [] liste_mots[i];
    }
    delete [] liste_mots;
    
}

bool is_in_dico( char **liste_mot ,  char *str, int min , int max){
    /*recherche par dichotomie recursif*/
    static int iter= 0;
    if (min>max)
    {
        return false;
    }
    
    int milieu=(max+min)/2;
    if (strcmp(liste_mot[milieu],str)==0){
        return true;
    }
    else if (strcmp(liste_mot[milieu],str)>0){
        iter++;
        return is_in_dico(liste_mot,str,min,milieu-1);
    }
    else{
        iter++;
        return is_in_dico(liste_mot,str,milieu+1,max);
    }

}

int iteratif(char **liste_mot ,char *str,int nb_mot){
    int min=0;
    int max=nb_mot;
    int milieu=(min+max)/2;
    while(min <= max){
        if(strcmp(liste_mot[milieu],str)==0){
            return milieu;
        }
        else if(strcmp(liste_mot[milieu],str)>0){
            max=milieu-1;
        }
        else{
            min=milieu+1;

        }
        milieu=(max+min)/2;
    }
    return -1;
}

void create_joueurs(JOUEUR *liste_joueurs,char *str){
    /*
        liste_jouer -> liste en allocation dynamique qui va contenir tout les joueurs 
        str-> chaine qui nous dit quels seront les joueurs de la partie ex: "HRHR"
    */
   JOUEUR mon_joueur;

   for (size_t i = 0; i < strlen(str); i++)
   {
        mon_joueur.type=str[i];
        mon_joueur.nb_quart_singe=0;
        liste_joueurs[i]=mon_joueur;
   }
   
}

void clear_joueur_array(JOUEUR *liste_joueurs){
    delete [] liste_joueurs;
}
