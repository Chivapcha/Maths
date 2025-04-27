#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Probleme(){
    // déclaration des variables
    int reponse_candidat;
    int reponse_correcte;
    int choix1, choix2;
    // déclaration de toutes les possibilités
    char tab[3][20]={"sacs", "boites", "pochettes"};
    char choixBoite[3][20]= {"feutres", "crayons", "petites voitures"};
    srand(time(NULL));
    choix1 = rand()%3;
    // on fait en sorte que le problème soit différent mais logique
    if (choix1 == 0){
        choix2 = 2;
    }
    else if (choix1 == 1){
        choix2 = rand()%3;
    }
    else{
        choix2 = rand()%3;
    }
    // génération aléatoire des nombres
    int nombres= rand()%30+1;
    int nombres2= rand()%10+1;
    int nombres3= rand()%20+1;
    // affichage du problème
    printf("Il y a %d %s dans %d %s on donne %d %s, combient y a t-il de %s maintenant? \n", nombres, choixBoite[choix2], nombres2, tab[choix1], nombres3, choixBoite[choix2], choixBoite[choix2]);
    scanf("%d", &reponse_candidat);
    // on fait le calcul de la réponse correcte
    reponse_correcte = nombres*nombres2 + nombres3;
    // on regarde si l'utilisateurs a bon
    if (reponse_candidat == reponse_correcte){
        printf("Bravo, vous avez repondu juste !\n");
    }
    else{
        printf("Dommage, la bonne reponse etait %d\n", reponse_correcte);
    }

}
int main(){
    Probleme();
    return 0;
}