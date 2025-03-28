#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

void Longueurs(){
    srand(time(NULL));
    int option1 = rand() % 7;
    int option2 = rand() % 7;
    while (option1 == option2){
        option2 = rand() % 7;
    }
    if (option1 > option2){
        int temp = option1;
        option1 = option2;
        option2 = temp;
    }
    char tabMesures[7][3] = {"km", "hm", "dam", "m", "dm", "cm", "mm"};
    int trouve = 0;
    int i = 1;
    int resultat;
    int a = rand() % 10 + 1;
    int reponse = a*pow(10, (option2-option1));
    while (trouve == 0 && i <= 3){
        printf("%d %s = ? %s \n", a, tabMesures[option1], tabMesures[option2]);
        scanf("%d", &resultat);
        if (resultat == reponse){
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
        printf("La reponse etait %d\n", reponse);
    }
}

void Masses(){
    srand(time(NULL));
    int option1 = rand() % 7;
    int option2 = rand() % 7;
    while (option1 == option2){
        option2 = rand() % 7;
    }
    if (option1 > option2){
        int temp = option1;
        option1 = option2;
        option2 = temp;
    }
    char tabMesures[7][3] = {"kg", "hg", "dag", "g", "dg", "cg", "mg"};
    int trouve = 0;
    int i = 1;
    int resultat;
    int a = rand() % 10 + 1;
    int reponse = a*pow(10, (option2-option1));
    while (trouve == 0 && i <= 3){
        printf("%d %s = ? %s \n", a, tabMesures[option1], tabMesures[option2]);
        scanf("%d", &resultat);
        if (resultat == reponse){
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
        printf("La reponse etait %d\n", reponse);
    }
}

void Durees(){
    srand(time(NULL));
    int trouve = 0;
    int i = 1;
    int resultat;
    int option = rand() % 2;
    if (option == 0) {
        int heures = rand() % 10+1;
        int minutes = rand() % 60;
        while (trouve == 0 && i <= 3){
            printf("%d h %d min = ? min\n", heures, minutes);
            scanf("%d", &resultat);
            if (resultat == (heures*60)+minutes){
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
            printf("La reponse etait %d\n", (heures*60)+minutes);
        }
    }
    
    else {
        int minutes = rand() % 10+1;
        int secondes = rand() % 60;
        while (trouve == 0 && i <= 3){
            printf("%d m %d s = ? s\n", minutes, secondes);
            scanf("%d", &resultat);
            if (resultat == (minutes*60)+secondes){
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
            printf("La reponse etait %d\n", (minutes*60)+secondes);
        }
    }
}

typedef struct {
    char nom[20];
    int score;
} Joueur;

void sauvegarderScore(char *nomJoueur, int nouveauxPoints) {
    FILE *fichier = fopen("scores.txt", "r");
    Joueur joueurs[100]; // Tableau pour stocker temporairement les joueurs
    int nbJoueurs = 0;
    int joueurExistant = 0;

    // Vérifier si le fichier existe et lire les scores
    if (fichier != NULL) {
        while (fscanf(fichier, "%s %d", joueurs[nbJoueurs].nom, &joueurs[nbJoueurs].score) != EOF) {
            if (strcmp(joueurs[nbJoueurs].nom, nomJoueur) == 0) {
                joueurs[nbJoueurs].score += nouveauxPoints; // Ajouter les points au score existant
                joueurExistant = 1;
            }
            nbJoueurs++;
        }
        fclose(fichier);
    }

    // Si le joueur n'existe pas encore, l'ajouter à la liste
    if (!joueurExistant) {
        strcpy(joueurs[nbJoueurs].nom, nomJoueur);
        joueurs[nbJoueurs].score = nouveauxPoints;
        nbJoueurs++;
    }

    // Réécrire tout le fichier avec les nouveaux scores
    fichier = fopen("scores.txt", "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }

    for (int i = 0; i < nbJoueurs; i++) {
        fprintf(fichier, "%s %d\n", joueurs[i].nom, joueurs[i].score);
    }

    fclose(fichier);
}

int main() {
    int choix = -1;
    char nom[20];
    char choixConnection;
    int AncienScore;
    char NomRecherche[20];

    // Demander si l'utilisateur veut se connecter
    printf("Voulez-vous vous connecter ? (O/N)\n");
    scanf(" %c", &choixConnection);

    if (choixConnection == 'O') {
        printf("Quel est votre nom ?\n");
        scanf(" %s", NomRecherche);

        // Ouvrir le fichier et chercher le joueur
        FILE *fichier = fopen("scores.txt", "r");
        if (fichier != NULL) {
            while (fscanf(fichier, "%s %d", nom, &AncienScore) != EOF) {
                if (strcmp(nom, NomRecherche) == 0) {
                    printf("Bienvenue %s, vous avez %d points\n", nom, AncienScore);
                    break;
                }
            }
            fclose(fichier);
        }
    }

    while (choix != 0) {
        printf("+--------------------------------+\n");
        printf("|1 : Addition                    |\n");
        printf("|2 : Soustraction                |\n");
        printf("|3 : Multiplication              |\n");
        printf("|4 : Tables des multiplications  |\n");
        printf("|5 : Division                    |\n");
        printf("|6 : Longueurs                   |\n");
        printf("|7 : Masses                      |\n");
        printf("|8 : Durees                      |\n");
        printf("|0 : Sortir du jeu               |\n");
        printf("+--------------------------------+\n");
        printf("Quel est votre choix ?\n");
        scanf("%d", &choix);

        while (choix < 0 || choix > 8) {
            printf("Choix invalide, veuillez choisir un nombre entre 0 et 8\n");
            scanf("%d", &choix);
        }

        switch (choix) {
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
            case 6:
                printf("Longueurs\n");
                Longueurs();
                break;
            case 7:
                printf("Masses\n");
                Masses();
                break;
            case 8:
                printf("Durees\n");
                Durees();
                break;
            case 0:
                printf("Merci pour votre visite\n");
                printf("Vous avez obtenu %d points\n", points);

                // Demander à sauvegarder les points
                char choixSauvegarde;
                printf("Voulez-vous sauvegarder vos points ? (O/N)\n");
                scanf(" %c", &choixSauvegarde);

                if (choixSauvegarde == 'O') {
                    if (choixConnection == 'O') {
                        sauvegarderScore(nom, points);
                    } else {
                        printf("Quel est votre nom ?\n");
                        scanf(" %s", nom);
                        sauvegarderScore(nom, points);
                    }
                }
                break;
        }
    }
    return 0;
}