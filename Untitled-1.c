#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int points=0;

void Addition(){
    srand(time(NULL));
    int trouve = 0;
    int resultat;
    int i = 1;
    int a = rand() % 101;
    int b = rand() % 101;
    while (trouve == 0 && i <= 3){
        printf("%d + %d = ", a, b);
        scanf("%d", &resultat);
        if (resultat == a+b){
            trouve = 1;
            printf("Bravo !\n");
            if (i == 1) {
                printf("Vous avez gagne 10 points\n");
                points += 10;
            } else if (i == 2) {
                printf("Vous avez gagne 5 points\n");
                points += 5;
            } else {
                printf("Vous avez gagne 1 point\n");
                points += 1;
            }
        } else {
            printf("Perdu... Il vous reste %d essais\n", 3-i);
        }
        i++;
    }
    if (trouve == 0){
        printf("La reponse etait %d\n", a+b);
    }
}

void Soustraction(){
    srand(time(NULL));
    int trouve = 0;
    int i = 1;
    int resultat;
    int a = rand() % 101;
    int b = rand() % 101;
    if (a<b){
        int temp = a;
        a = b;
        b = temp;
    }
    while (trouve == 0 && i <= 3){
        printf("%d - %d = ", a, b);
        scanf("%d", &resultat);
        if (resultat == a-b){
            trouve = 1;
            printf("Bravo !\n");
            if (i == 1) {
                printf("Vous avez gagne 10 points\n");
                points += 10;
            } else if (i == 2) {
                printf("Vous avez gagne 5 points\n");
                points += 5;
            } else {
                printf("Vous avez gagne 1 point\n");
                points += 1;
            }
        } else {
            printf("Perdu... Il vous reste %d essais\n", 3-i);
        }
        i++;
    }
    if (trouve == 0){
        printf("La reponse etait %d\n", a-b);
    }
}

void Multiplication(){
    srand(time(NULL));
    int trouve = 0;
    int i = 1;
    int resultat;
    int a = rand() % 11;
    int b = rand() % 11;
    while (trouve == 0 && i <= 3){
        printf("%d * %d = ", a, b);
        scanf("%d", &resultat);
        if (resultat == a*b){
            trouve = 1;
            printf("Bravo !\n");
            if (i == 1) {
                printf("Vous avez gagne 10 points\n");
                points += 10;
            } else if (i == 2) {
                printf("Vous avez gagne 5 points\n");
                points += 5;
            } else {
                printf("Vous avez gagne 1 point\n");
                points += 1;
            }
        } else {
            printf("Perdu... Il vous reste %d essais\n", 3-i);
        }
        i++;
    }
    if (trouve == 0){
        printf("La reponse etait %d\n", a*b);
    }
}

//Le joueur a le droit à 3 erreur pour obtenir des points
void TablesMultiplication(){
    int fautes = 0;
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
    for (int i = 1; i <= 10; i++){
        int resultat;
        int j = 1;
        int trouve = 0;
        while (trouve == 0 && j <= 3){
            printf("%d * %d = ", chiffre, i);
            scanf("%d", &resultat);
            if (resultat != chiffre*i){
                printf("Perdu... Il vous reste %d essais\n", 3-j);
                fautes += 1;
            }
            else {
                trouve = 1;
            }
            j++;
        }
        if (trouve == 0){
            printf("La reponse etait %d\n", chiffre*i);
        }
    }
    if (fautes == 0){
        printf("Vous avez fait 0 fautes et obtenu 10 points !\n");
        points += 10;
    }
    else if (fautes == 1){
        printf("Vous avez fait 1 faute et obtenu 5 points !\n");
        points += 5;
    }
    else if (fautes == 2){
        printf("Vous avez fait 2 fautes et obtenu 1 points !\n");
        points += 1;
    }
    else {
        printf("Vous avez fait %d fautes et n'avez pas obtenu de points\n", fautes);
    }
}

void Division(){
    srand(time(NULL));
    int trouve = 0;
    int i = 1;
    int quotidient;
    int reste;
    int a = rand() % 100+1;
    int b = rand() % 10+1;
    if (a<b){
        int temp = a;
        a = b;
        b = temp;
    }
    while (trouve == 0 && i <= 3){
        printf("Le quotidient de %d / %d = ", a, b);
        scanf("%d", &quotidient);
        printf("Le reste de %d / %d = ", a, b);
        scanf("%d", &reste);
        if (quotidient == a/b && reste == a%b){
            printf("Bravo !\n");
            if (i == 1) {
                printf("Vous avez gagne 10 points\n");
                points += 10;
            } else if (i == 2) {
                printf("Vous avez gagne 5 points\n");
                points += 5;
            } else {
                printf("Vous avez gagne 1 point\n");
                points += 1;
            }
            trouve = 1;
        } else {
            printf("Perdu... Il vous reste %d essais\n", 3-i);
        }
        i++;
    }
    if (trouve == 0){
        printf("Le quotidient etait %d et le reste etait %d\n", a/b, a%b);
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
                TablesMultiplication();
                break;
            case 5:
                printf("Division\n");
                Division();
                break;
            case 0:
                printf("Merci pour votre visite\n");
                printf("Vous avez obtenu %d points\n", points);
                break;
        }
    }
    return 0;
}

