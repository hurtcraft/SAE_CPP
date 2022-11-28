#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "function.hpp"

using namespace std ;

int main(int argc , char *argv[]){
    if (!verif_joueur(argc,argv)){
        exit(EXIT_FAILURE);
    }
    ifstream file("ods4.txt");

    int a=get_nb_mot_dico(file);
    
    file.close();
    return 0;
}

