#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Probleme(){
    int choix1, choix2;
    char tab[3][20]={"sacs", "boites", "pochettes"};
    char choixBoite[3][20]= {"feutres", "crayons", "petites voitures"};
    srand(time(NULL));
    choix1 = rand()%3;
    if (choix1 == 0){
        choix2 = 2;
    }
    else if (choix1 == 1){
        choix2 = rand()%3;
    }
    else{
        choix2 = rand()%3;
    }
    int nombres= rand()%30+1;
    int nombres2= rand()%10+1;
    printf("choix 1 : %d\n", choix1);
    printf("choix 2 : %d\n", choix2);
    printf("nombres : %d\n", nombres);
    printf("nombres2 : %d\n", nombres2);
    printf("Il y a %d %s dans %d %s on donne %d %s, combient y a t-il de %s dans %s ? \n, nombres, choixBoites[choix2], nombres2, tab[choix1], nombres2, tab[choix1], choixBoites[choix1], tab[choix1]);");

}
int main(){
    Probleme();
    return 0;
}