#include <iostream>
#include <cstring>
using namespace std ;
int main(){
    FILE *mon_fichier=fopen("ods4.txt","r");
    char *str;
    char temp[256];
    int count = 0;
    char *liste_mot[200];
    
    while (!feof(mon_fichier)){
        count ++;
    }
    
    while (!feof(mon_fichier)){
        
        strcpy(temp,fgets(temp,256,mon_fichier));
    
        liste_mot[count]=new char[strlen(temp)]; 
        strcpy(liste_mot[count],temp);
        

        count ++;
    }
    cout << liste_mot[1];
    fclose(mon_fichier);
    return 0;
}

