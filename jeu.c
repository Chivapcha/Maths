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

void Aires(){
    srand(time(NULL));
    int option1 = rand() % 5;
    int option2 = rand() % 5;
    while (option1 == option2){
        option2 = rand() % 5;
    }
    if (option1 > option2){
        int temp = option1;
        option1 = option2;
        option2 = temp;
    }
    char tabMesures[5][5] = {"dam2", "m2", "dm2", "cm2", "mm2"}; // sur le site on va de km jusqu'à mm, mais dans ce programme ça marche pas, apparemment le nombre est trop long et ça renvoie un chiffre négatif
    int trouve = 0;
    int i = 1;
    int resultat;
    int a = rand() % 9 + 1;
    int reponse = a*pow(10, (option2-option1)*2);
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

void GrandsNombres() {
    int reponse;
    srand(time(NULL));
    int choix_millions = rand() % 10; // 0-9
    int choix_milles = rand() % 1000; // 0-999
    int choix_reste = rand() % 1000; // 0-999
    reponse = choix_millions * 1000000 + choix_milles * 1000 + choix_reste; // 0-9999999
    // on a notre nombre entre 0 et 9999999, on le met dans un tableau de 7 chiffres
    int tab_reponse[7];
    for (int i = 6; i >= 0; i--) {
        tab_reponse[i] = reponse % 10;
        reponse /= 10;
    }
    // on initiamise les tableaux de chiffres en lettres
    char zero_neuf[10][6] = {"", "un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf"};
    char onze_dixneuf[10][10] = {"", "onze", "douze", "treize", "quatorze", "quinze", "seize", "dix-sept", "dix-huit", "dix-neuf"};
    char dizaines[10][16] = {"", "dix", "vingt", "trente", "quarante", "cinquante", "soixante", "soixante-dix", "quatre-vingt", "quatre-vingt-dix"};

    char nombre_ecrit[7][100]; // tableau pour stocker les chiffres en lettres
    if (tab_reponse[0] != 0) { // si le premier nombre (millions) est différent de 0, on affiche le chiffre et "million"
        if (tab_reponse[0] == 4) { // sans ce "if else", le programme affiche "quatrecinq" au lieu de "quatre", mais je ne sais pas pourquoi
            strcat(nombre_ecrit[0], "quatre");
        }
        else {
            strcat(nombre_ecrit[0], zero_neuf[tab_reponse[0]]);
        }
        if (tab_reponse[0] == 1) { // si le chiffre est égale à 1, on ajoute "million" sans "s"
            strcat(nombre_ecrit[0], " million");
        }
        else { // sinon, on ajoute "millions"
            strcat(nombre_ecrit[0], " millions");
        }
    }

    if (tab_reponse[1] != 0) { // si le deuxième nombre (centaines de milles) est différent de 0, on affiche le chiffre et "cent", sauf si c'est 1, dans ce cas on affiche juste "cent"
        if (tab_reponse[1] == 4) { // sans ce "if", le programme affiche "quatrecinq" au lieu de "quatre", mais je ne sais pas pourquoi
            strcat(nombre_ecrit[1], "quatre");
            strcat(nombre_ecrit[1], " cent");
        }
        else if (tab_reponse[1] == 1) {
            strcat(nombre_ecrit[1], "cent");
        } else {
            strcat(nombre_ecrit[1], zero_neuf[tab_reponse[1]]);
            strcat(nombre_ecrit[1], " cent");
        }
    }

    if (tab_reponse[2] != 0) { // si le troisième nombre (dizaines de milles) est différent de 0 :
        if (tab_reponse[2] == 1 && tab_reponse[3] != 0) { // si ce nombre est 1 et qu'il y a un chiffre après, on affiche le nombre entre 11 et 19
            strcat(nombre_ecrit[2], onze_dixneuf[tab_reponse[3]]);
        }
        else if (tab_reponse[2] == 7 || tab_reponse[2] == 9) { // si le chiffre est 7 ou 9 :
            if (tab_reponse[3] < 7) { // si le chiffre suivant est inférieur à 7 :
                if (tab_reponse[3] == 0) { // si le chiffre suivant est 0, on ajoute "-dix"
                    strcat(nombre_ecrit[2], dizaines[tab_reponse[2] - 1]);
                    strcat (nombre_ecrit[2], "-dix");
                } else {
                    strcat(nombre_ecrit[2], dizaines[tab_reponse[2] - 1]);
                    strcat (nombre_ecrit[2], "-");
                    strcat(nombre_ecrit[2], onze_dixneuf[tab_reponse[3]]);
                }
            } else {
                strcat(nombre_ecrit[2], dizaines[tab_reponse[2]]);
                strcat (nombre_ecrit[2], "-");
                strcat(nombre_ecrit[2], zero_neuf[tab_reponse[3]]);
            }
        }
        else { // sinon, on affiche le chiffre et "dix" ou "vingt" ou "trente", etc.
            strcat(nombre_ecrit[2], dizaines[tab_reponse[2]]);
            if (tab_reponse[3] == 1) { // si le chiffre suivant est 1, on ajoute "et" entre les deux
                strcat(nombre_ecrit[2], "-et-");
            } else if (tab_reponse[3] != 0) { // si le chiffre suivant n'est pas 0, on ajoute un tiret entre les deux
                strcat(nombre_ecrit[2], "-");
            }
        }
    }
    
    if (tab_reponse[3] != 0) { // si le quatrième nombre (unités de milles) est différent de 0, on affiche le chiffre
        if (tab_reponse[2] != 1) { // si le chiffre précédent n'est pas 1 (le nombre d'unités de milles n'est pas entre 11 et 19), on affiche le chiffre
            if (tab_reponse[3] == 4) { // sans ce "if", le programme affiche "quatrecinq" au lieu de "quatre", mais je ne sais pas pourquoi
                strcat(nombre_ecrit[3], "quatre");
            }
            else {
                strcat(nombre_ecrit[3], zero_neuf[tab_reponse[3]]);
            }
        }
        if (tab_reponse[2] == 7 || tab_reponse[2] == 9) { // si le chiffre précédent est 7 ou 9 on efface les unités parce qu'on les a déjà ajoutées
            strcpy(nombre_ecrit[3], "");
        }
    }

    if (tab_reponse[1] != 0 || tab_reponse[2] != 0 || tab_reponse[3] != 0) { // si il y a un nombre de milles alors on affiche "mille" à la fin
        strcat(nombre_ecrit[3], " mille");
    }

    if (tab_reponse[4] != 0) { // si le cinquième nombre (centaines) est différent de 0, on affiche le chiffre (si c'est pas 1) et "cent"
        if (tab_reponse[4] == 1) {
            strcat(nombre_ecrit[4], "cent");
        } else if (tab_reponse[4] == 4) { // sans ce "if", le programme affiche "quatrecinq" au lieu de "quatre", mais je ne sais pas pourquoi
            strcat(nombre_ecrit[4], "quatre");
            strcat(nombre_ecrit[4], " cent");
        }
        else{
            strcat(nombre_ecrit[4], zero_neuf[tab_reponse[4]]);
            strcat(nombre_ecrit[4], " cent");
        }
    }

    if (tab_reponse[5] != 0) { // si le sixième nombre (dizaines) est différent de 0 :
        if (tab_reponse[5] == 1 && tab_reponse[6] != 0) { // si ce nombre est 1 et qu'il y a un chiffre après, on affiche le nombre entre 11 et 19
            strcat(nombre_ecrit[5], onze_dixneuf[tab_reponse[6]]);
        }
        else if (tab_reponse[5] == 7 || tab_reponse[5] == 9) { // si le chiffre est 7 ou 9 :
            if (tab_reponse[6] < 7) { // si le chiffre suivant est inférieur à 7 :
                if (tab_reponse[6] == 0) { // si le chiffre suivant est 0, on ajoute "-dix"
                    strcat(nombre_ecrit[5], dizaines[tab_reponse[5] - 1]);
                    strcat (nombre_ecrit[5], "-dix");
                } else {
                    strcat(nombre_ecrit[5], dizaines[tab_reponse[5] - 1]);
                    strcat (nombre_ecrit[5], "-");
                    strcat(nombre_ecrit[5], onze_dixneuf[tab_reponse[6]]);
                }
            } else {
                strcat(nombre_ecrit[5], dizaines[tab_reponse[5]]);
                strcat (nombre_ecrit[5], "-");
                strcat(nombre_ecrit[5], zero_neuf[tab_reponse[6]]);
            }
        }
        else { // sinon, on affiche le chiffre et "dix" ou "vingt" ou "trente", etc.
            strcat(nombre_ecrit[5], dizaines[tab_reponse[5]]);
        }
        if (!(tab_reponse[5] == 1 || tab_reponse[5] == 7 || tab_reponse[5] == 9) && tab_reponse[6] == 1) { // si le chiffre est pas 1, 7 ou 9 et que le chiffre suivant est 1, on ajoute "et" entre les deux
            strcat(nombre_ecrit[5], "-et-");
        } else if (!(tab_reponse[5] == 1 || tab_reponse[5] == 7 || tab_reponse[5] == 9) && tab_reponse[3] != 0) { // si le chiffre suivant n'est pas 0, on ajoute un tiret entre les deux
            strcat(nombre_ecrit[5], "-");
        }
    }
    
    if (tab_reponse[6] != 0) { // si le septième nombre (unités) est différent de 0, on affiche le chiffre
        if (tab_reponse[5] != 1) { // si le chiffre précédent n'est pas 1 (le nombre d'unités n'est pas entre 11 et 19) :
            if (tab_reponse[6] == 4) { // sans ce "if", le programme affiche "quatrecinq" au lieu de "quatre", mais je ne sais pas pourquoi
                strcat(nombre_ecrit[6], "quatre");
            }
            else if (tab_reponse[5] == 7 || tab_reponse[5] == 9) { // si le chiffre précédent est 7 ou 9 :
                if (tab_reponse[6] < 7) { // si le chiffre suivant est inférieur à 7 :
                    strcat(nombre_ecrit[6], onze_dixneuf[tab_reponse[6]]);
                } else {
                    strcat(nombre_ecrit[6], zero_neuf[tab_reponse[6]]);
                }
            }
            else {
                strcat(nombre_ecrit[6], zero_neuf[tab_reponse[6]]);
            }
        }
        if (tab_reponse[5] == 7 || tab_reponse[5] == 9) { // si le chiffre précédent est 7 ou 9 on efface les unités parce qu'on les a déjà ajoutées
            strcpy(nombre_ecrit[6], "");
        }
    }

    // On affiche le nombre écrit en toutes lettres
    for (int i = 0; i < 7; i++) {
        printf("%s ", nombre_ecrit[i]);
    }
    printf("\n");

    // On demande à l'utilisateur de le réécrire
    int reponse_utilisateur;
    int trouve = 0;
    int i = 1;
    while (trouve == 0 && i <= 3){
        printf("Ecrivez le nombre en chiffres : ");
        scanf("%d", &reponse_utilisateur);
        if (reponse_utilisateur == choix_millions * 1000000 + choix_milles * 1000 + choix_reste) {
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
        printf("La reponse etait %d\n", choix_millions * 1000000 + choix_milles * 1000 + choix_reste);
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
                joueurs[nbJoueurs].score = joueurs[nbJoueurs].score + nouveauxPoints;
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
        printf("|9 : Aires                       |\n");
        printf("10 : Grands nombres              |\n");
        printf("|0 : Sortir du jeu               |\n");
        printf("+--------------------------------+\n");
        printf("Quel est votre choix ?\n");
        scanf("%d", &choix);

        while (choix < 0 || choix > 10) {
            printf("Choix invalide, veuillez choisir un nombre entre 0 et 10\n");
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
            case 9:
                printf("Aires\n");
                Aires();
                break;
            case 10:
                printf("Grands nombres\n");
                GrandsNombres();
                break;
            case 0:
                printf("Merci pour votre visite\n");
                printf("Vous avez %d points en tout\n", points);

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