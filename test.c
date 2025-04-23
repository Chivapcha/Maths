#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int points=0;
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
typedef struct {
    char nom[20];
    int score;
    char dateHeure[20]; // Champ pour stocker la date et l'heure
} Joueur;

void sauvegarderScore(char *nomJoueur, int nouveauxPoints) {
    FILE *fichier = fopen("scores.txt", "r");
    Joueur joueurs[100]; // Tableau pour stocker temporairement les joueurs
    int nbJoueurs = 0;
    int joueurExistant = 0;

    // Récupérer la date et l'heure actuelles
    char dateHeureActuelle[20];
    time_t now = time(NULL);
    strftime(dateHeureActuelle, sizeof(dateHeureActuelle), "%Y-%m-%d %H:%M:%S", localtime(&now));

    // Lire les scores existants dans le fichier
    if (fichier != NULL) {
        while (fscanf(fichier, "%s %d %[^\n]", joueurs[nbJoueurs].nom, &joueurs[nbJoueurs].score, joueurs[nbJoueurs].dateHeure) != EOF) {
            if (strcmp(joueurs[nbJoueurs].nom, nomJoueur) == 0) {
                // Mettre à jour le score et la date/heure pour le joueur existant
                joueurs[nbJoueurs].score = nouveauxPoints;
                strcpy(joueurs[nbJoueurs].dateHeure, dateHeureActuelle);
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
        strcpy(joueurs[nbJoueurs].dateHeure, dateHeureActuelle);
        nbJoueurs++;
    }

    // Réécrire tout le fichier avec les nouveaux scores et inclure la date/heure
    fichier = fopen("scores.txt", "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }

    for (int i = 0; i < nbJoueurs; i++) {
        // Écrire chaque joueur avec son score et la date/heure
        fprintf(fichier, "%s %d %s\n", joueurs[i].nom, joueurs[i].score, joueurs[i].dateHeure);
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
            int joueurTrouve = 0;
            char dateHeure[20];
            while (fscanf(fichier, "%s %d %s", nom, &AncienScore, dateHeure) != EOF) {
                if (strcmp(nom, NomRecherche) == 0) {
                    printf("Bienvenue %s, vous avez %d points (dernière connexion : %s)\n", nom, AncienScore, dateHeure);
                    points = AncienScore; // Charger le score existant
                    joueurTrouve = 1;
                    break;
                }
            }
            fclose(fichier);

            if (!joueurTrouve) {
                printf("Joueur non trouvé, un nouveau compte sera créé.\n");
                strcpy(nom, NomRecherche);
            }
        } else {
            printf("Aucun fichier de scores trouvé, un nouveau sera créé.\n");
            strcpy(nom, NomRecherche);
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
        printf("|9 : Aires                       |\n");
        printf("|0 : Sortir du jeu               |\n");
        printf("+--------------------------------+\n");
        printf("Quel est votre choix ?\n");
        scanf("%d", &choix);

        while (choix < 0 || choix > 9) {
            printf("Choix invalide, veuillez choisir un nombre entre 0 et 9\n");
            scanf("%d", &choix);
        }

        switch (choix) {
            case 1:
                printf("Addition\n");
                break;
            case 2:
                printf("Soustraction\n");
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
            case 6:
                printf("Longueurs\n");
                break;
            case 7:
                printf("Masses\n");
                break;
            case 8:
                printf("Durees\n");
                break;
            case 9:
                printf("Aires\n");
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