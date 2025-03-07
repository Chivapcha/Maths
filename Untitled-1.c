#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Addition(){
    srand(time(NULL));
    int resultat;
    int a = rand() % 101;
    int b = rand() % 101;
    printf("Quel est le resultat de %d + %d ?\n", a, b);
    printf("Entrez le resultat : \n");
    scanf("%d", &resultat);
    if (resultat == a+b){
        printf("Bravo !\n");
    } else {
        printf("Mauvaise reponse, la reponse etait %d\n", a+b);
    }
}

int main(){
    int choix = -1;
    while (choix != 0) {
        printf("+--------------------------------+\n");
        printf("|1 : Addition                    |\n");
        printf("|2 : Soustraction                |\n");
        printf("|3 : Multiplication              |\n");
        printf("|4 : Tables des multiplications  |\n");
        printf("|5 : Division                    |\n");
        printf("|0 : Sortir du jeu               |\n");
        printf("+--------------------------------+\n");
        printf("Quel est votre choix ?\n");
        scanf("%d", &choix);
        while (choix < 0 || choix > 5) {
            printf("Choix invalide, veuillez choisir un nombre entre 0 et 5\n");
            scanf("%d", &choix);
        }
        switch(choix){
            case 1:
                printf("Addition\n");
                Addition();
                break;
            case 2:
                printf("Soustraction\n");
                break;
            case 3:
                printf("Multiplication\n");
                break;
            case 4:
                printf("Tables de multiplication\n");
                break;
            case 5:
                printf("Division\n");
                break;
            case 0:
                printf("Sortie\n");
                break;
        }
    }

    return 0;
}

