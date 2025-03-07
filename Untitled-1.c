#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Addition(){
    srand(time(NULL));
    int resultat;
    int a = rand() % 101;
    int b = rand() % 101;
    printf("%d + %d ?\n", a, b);
    printf("Entrez le resultat : \n");
    scanf("%d", &resultat);
    if (resultat == a+b){
        printf("Bravo !\n");
    } else {
        printf("Mauvaise reponse, la reponse etait %d\n", a+b);
    }
}

void Soustraction(){
    srand(time(NULL));
    int resultat;
    int a = rand() % 101;
    int b = rand() % 101;
    if (a<b){
        int temp = a;
        a = b;
        b = temp;
    }
    printf("%d - %d ?\n", a, b);
    printf("Entrez le resultat : \n");
    scanf("%d", &resultat);
    if (resultat == a-b){
        printf("Bravo !\n");
    } else {
        printf("Mauvaise reponse, la reponse etait %d\n", a-b);
    }
}

void Multiplication(){
    srand(time(NULL));
    int resultat;
    int a = rand() % 11;
    int b = rand() % 11;
    printf("%d * %d ?\n", a, b);
    printf("Entrez le resultat : \n");
    scanf("%d", &resultat);
    if (resultat == a*b){
        printf("Bravo !\n");
    } else {
        printf("Mauvaise reponse, la reponse etait %d\n", a*b);
    }
}

void TablesMultiplications(){
    int chiffre;
    printf("Sur quelle table souhaitez-vous travailer ? (de 1 a 10)\n");
    scanf("%d", &chiffre);
    while (chiffre < 1 || chiffre > 10){
        printf("Table invalide, veuillez choisir un nombre entre 1 et 10\n");
        scanf("%d", &chiffre);
    }
    for (int i = 1; i <= 10; i++){
        printf("%d * %d = %d\n", chiffre, i, chiffre*i);
    }
    printf("Exercice : remplissez la table\n");
    // Terminer (les points,  verifier la boucle)
    for (int i = 1; i <= 10; i++){
        int resultat;
        printf("%d * %d ?\n", chiffre, i);
        printf("Entrez le resultat : \n");
        scanf("%d", &resultat);
        if (resultat == chiffre*i){
            printf("Bravo !\n");
        } else {
            printf("Mauvaise reponse, la reponse etait %d\n", chiffre*i);
        }
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
                Soustraction();
                break;
            case 3:
                printf("Multiplication\n");
                Multiplication();
                break;
            case 4:
                printf("Tables de multiplication\n");
                break;
            case 5:
                printf("Division\n");
                break;
            case 0:
                printf("Merci pour votre visite\n");
                break;
        }
    }

    return 0;
}

