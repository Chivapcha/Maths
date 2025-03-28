#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Probleme(){
    int choix1, choix2;
    char tab[3]=["sacs", "boites", "pochettes"];
    char choixBoite[3]=["feutres", "crayons", "petites voitures"];
    choix1 = rand()%3;
    if (choix1 == 0){
        choix2 = 2;
    }
    else if (choix1 == 1){
        choix2 = rand()%3;
    }
    else
    choix2 = rand()%3;


}
int main(){
    
}