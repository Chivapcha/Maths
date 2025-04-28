// déclaration des outils nécessaires
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// déclaration des points
int points=0;

// déclaration des fonctions
void Addition(){
    // on initialise le générateur de nombres aléatoires
    srand(time(NULL));
    // déclaration des variables
    // si trouve=0 alors l'utilisateur n'a pas trouvé la bonne réponse
    // i est le nombre d'essais restants
    int trouve = 0;
    int resultat;
    int i = 1;
    int a = rand() % 101;
    int b = rand() % 101;
    // on fait une boucle tant qu'il reste des essais et que l'utilisateur n'a pas trouvé la bonne réponse
    while (trouve == 0 && i <= 3){
        // on affiche le problème
        printf("%d + %d = ", a, b);
        // on lit la réponse de l'utilisateur
        scanf("%d", &resultat);
        //on vérifie si la réponse est correcte
        // si la réponse est correcte, on affiche un message de félicitations et on ajoute des points
        if (resultat == a+b){
            trouve = 1;
            printf("Bravo !\n");
            // on change le nombre de points gagné en fonction du nombre d'essais restant
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
            // si l'utilisateur ne trouve pas la bonne réponse, on affiche un message d'erreur et on lui dit combien d'essais il lui reste
            printf("Perdu... Il vous reste %d essais\n", 3-i);
        }
        // on incrémente le nombre d'essais
        i++;
    }
    // si au bout des essais il n'a pas trouvé la bonne réponse, on lui affiche la bonne réponse
    if (trouve == 0){
        printf("La reponse etait %d\n", a+b);
    }
}

void Soustraction(){
    // on initialise le générateur de nombres aléatoires
    srand(time(NULL));
    // déclaration des variables
    // si trouve = 0 alors l'utilisateur n'a pas trouvé la bonne réponse
    // i est le nombre d'essais restants
    int trouve = 0;
    int i = 1;
    int resultat;
    int a = rand() % 101;
    int b = rand() % 101;
    // on fait en sorte que a soit le plus grand nombre (pour que le résultat soit positif)
    if (a<b){
        int temp = a;
        a = b;
        b = temp;
    }
    // on fait une boucle tant qu'il reste des essais et que l'utilisateur n'a pas trouvé la bonne réponse
    while (trouve == 0 && i <= 3){
        // on affiche le problème
        printf("%d - %d = ", a, b);
        // on lit la réponse de l'utilisateur
        scanf("%d", &resultat);
        //on vérifie si la réponse est correcte
        // si la réponse est correcte, on affiche un message de félicitations et on ajoute des points
        if (resultat == a-b){
            trouve = 1;
            printf("Bravo !\n");
            // le nombre de points gagné dépend du nombre d'essais restants
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
        // si l'utilisateur ne trouve pas la bonne réponse, on affiche un message d'erreur et on lui dit combien d'essais il lui reste
        } else {
            printf("Perdu... Il vous reste %d essais\n", 3-i);
        }
        // on incrémente le nombre d'essais
        i++;
    }
    // si au bout des essais l'utilisateur n'a pas trouvé la bonne réponse, on lui affiche la bonne réponse
    if (trouve == 0){
        printf("La reponse etait %d\n", a-b);
    }
}

void Multiplication(){
    // on initialise le générateur de nombres aléatoires
    srand(time(NULL));
    // déclaration des variables
    // si trouve = 0 alors l'utilisateur n'a pas trouvé la bonne réponse
    // i est le nombre d'essais restants
    int trouve = 0;
    int i = 1;
    int resultat;
    int a = rand() % 11;
    int b = rand() % 11;
    // on fait une boucle tant qu'il reste des essais et que l'utilisateur n'a pas trouvé la bonne réponse
    while (trouve == 0 && i <= 3){
        // on affiche le problème
        printf("%d * %d = ", a, b);
        // on lit la réponse de l'utilisateur
        scanf("%d", &resultat);
        // on vérifie si la réponse est correcte
        // si la réponse est correcte, on affiche un message de félicitations et on ajoute des points
        if (resultat == a*b){
            trouve = 1;
            printf("Bravo !\n");
            // les points varient en fonction des essais restant
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
        // on incrémente le nombre d'essais
        i++;
    }
    // si au bout des essais l'utilisateur n'a pas trouvé la bonne réponse, on lui affiche la bonne réponse
    if (trouve == 0){
        printf("La reponse etait %d\n", a*b);
    }
}

void TablesMultiplication(){
    // on initialise les fautes à 0 puisqu'il n'a le droit qu'à trois fautes
    int fautes = 0;
    // on initialise le chiifre dont l'utilisateur doit remplir la table
    int chiffre;
    // on demande à l'utilisateur de choisir un chiffre entre 1 et 10
    printf("Sur quelle table souhaitez-vous travailer ? (de 1 a 10)\n");
    // ce chiffre sera le chiffre dont l'utilisateur doit remplir la table
    scanf("%d", &chiffre);
    // on vérifie que le chiffre est entre 1 et 10
    while (chiffre < 1 || chiffre > 10){
        printf("Table invalide, veuillez choisir un nombre entre 1 et 10\n");
        scanf("%d", &chiffre);
    }
    // on affiche la table de multiplication
    for (int i = 1; i <= 10; i++){
        printf("%d * %d = %d\n", chiffre, i, chiffre*i);
    }
    // on demande à l'utilisateur de remplir la table
    printf("Exercice : remplissez la table\n");
    for (int i = 1; i <= 10; i++){
        // on initialise les valeurs nécessaire pour faire la table et vérifier la réponse
        int resultat;
        // on initialise le nombre d'essais restant
        int j = 1;
        // si trouve = 0 alors l'utilisateur n'a pas trouvé la bonne réponse
        int trouve = 0;
        // on fait une boucle tant que l'utilisateur n'a pas trouvé la bonne réponse et qu'il lui reste des essais
        while (trouve == 0 && j <= 3){
            // on affiche le problème
            printf("%d * %d = ", chiffre, i);
            // on lit la réponse de l'utilisateur
            scanf("%d", &resultat);
            // on vérifie la réponse
            // si la réponse est fausse, on affiche un message d'erreur et on lui dit combien d'essais il lui reste
            if (resultat != chiffre*i){
                printf("Perdu... Il vous reste %d essais\n", 3-j);
                // on ajoute une faute
                fautes += 1;
            }
            // si la réponse est bonne trouve = 1 et on passe au nombre suivant
            else {
                trouve = 1;
            }
            j++;
        }
        // au bout de 3 essais la réponse est affichée
        if (trouve == 0){
            printf("La reponse etait %d\n", chiffre*i);
        }
    }
    // on donne les points en fonction des fautes
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
    // on initialise le générateur de nombres aléatoires
    srand(time(NULL));
    // déclaration des variables
    int trouve = 0;
    int i = 1;
    int quotient;
    int reste;
    // on fait en sorte que le résultat ne soit pas 0
    int a = rand() % 100+1;
    int b = rand() % 10+1;
    // on fait en sorte que a soit le plus grand nombre (pour que le résultat ne soit pas juste a sur b)
    if (a<b){
        int temp = a;
        a = b;
        b = temp;
    }
    // tant que l'utilisateur n'a pas trouvé la bonne réponse et qu'il lui reste des essais
    while (trouve == 0 && i <= 3){
        // on demande le quotient
        printf("Le quotient de %d / %d = ", a, b);
        // on lit la réponse de l'utilisateur
        scanf("%d", &quotient);
        // on demande le reste
        printf("Le reste de %d / %d = ", a, b);
        // on lit la réponse de l'utilisateur
        scanf("%d", &reste);
        // on vérifie les réponses 
        if (quotient == a/b && reste == a%b){
            // si la réponse est correcte, on affiche un message de félicitations et on ajoute des points en fonction des essais
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
            // on dit que l'utilisateur a trouvé la bonne réponse pour sortir de la boucle
            trouve = 1;
            // si le résultat est faux, on affiche un message d'erreur et on lui dit combien d'essais il lui reste
        } else {
            printf("Perdu... Il vous reste %d essais\n", 3-i);
        }

        // on incrémente le nombre d'essais
        i++;
    }
    // si on est sorti de la boucle sans avoir trouvé la bonne réponse, on affiche la bonne réponse
    if (trouve == 0){
        printf("Le quotient etait %d et le reste etait %d\n", a/b, a%b);
    }
        
}

void Longueurs(){
    // on initialise le générateur de nombres aléatoires
    srand(time(NULL));
    // déclaration des variables
    // on choisit deux unités de mesure aléatoires
    int option1 = rand() % 7;
    int option2 = rand() % 7;
    // on fait en sorte que les deux unités soient différentes
    // si elles sont égales, on en choisit une autre
    while (option1 == option2){
        option2 = rand() % 7;
    }
    // si l'option 1 est plus grande que l'option 2, on les échange pour que la conversion soit possible
    if (option1 > option2){
        int temp = option1;
        option1 = option2;
        option2 = temp;
    }
    // on initialise le tableau de conversion
    char tabMesures[7][3] = {"km", "hm", "dam", "m", "dm", "cm", "mm"};
    // on initialise les variables nécessaires
    // si trouve = 0 alors l'utilisateur n'a pas trouvé la bonne réponse
    int trouve = 0;
    int i = 1;
    int resultat;
    // on calcule la réponse
    int a = rand() % 10 + 1;
    int reponse = a*pow(10, (option2-option1));
    // on fait une boucle tant que l'utilisateur n'a pas trouvé la bonne réponse et qu'il lui reste des essais
    while (trouve == 0 && i <= 3){
        // on affiche le problème
        printf("%d %s = ? %s \n", a, tabMesures[option1], tabMesures[option2]);
        // on lit la réponse de l'utilisateur
        scanf("%d", &resultat);
        // on vérifie la réponse
        // si la réponse est correcte, on affiche un message de félicitations et on ajoute des points en fonction des essais
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
            // lorsque la réponse est fausse, on affiche un message d'erreur et on lui dit combien d'essais il lui reste
        } else {
            printf("Perdu... Il vous reste %d essais\n", 3-i);
        }
        // on incrémente le nombre d'essais
        i++;
    }
    // si au bout des essais l'utilisateur n'a pas trouvé la bonne réponse, on lui affiche la bonne réponse
    if (trouve == 0){
        printf("La reponse etait %d\n", reponse);
    }
}

void Masses(){
    // on initialise le générateur de nombres aléatoires
    srand(time(NULL));
    // comme précedemment on choisit deux unités de mesure aléatoires
    // on fait en sorte qu'elles soient différentes
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
    // le tableau de mesure change on est maintenant en masse
    char tabMesures[7][3] = {"kg", "hg", "dag", "g", "dg", "cg", "mg"};
    int trouve = 0;
    int i = 1;
    int resultat;
    // on calcule la réponse
    int a = rand() % 10 + 1;
    int reponse = a*pow(10, (option2-option1));
    // on fait une boucle tant que l'utilisateur n'a pas trouvé la bonne réponse et qu'il lui reste des essais
    while (trouve == 0 && i <= 3){
        // on affiche le problème
        printf("%d %s = ? %s \n", a, tabMesures[option1], tabMesures[option2]);
        // on lit la réponse de l'utilisateur
        scanf("%d", &resultat);
         // on vérifie que la réponse est correcte 
        if (resultat == reponse){
            // si la réponse est bonne on donne des points en fonction du nombre d'essais restants
            trouve = 1;
            // on affiche un message de félicitations
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
            // si la réponse est fausse, on affiche un message d'erreur et on lui dit combien d'essais il lui reste
        } else {
            printf("Perdu... Il vous reste %d essais\n", 3-i);
        }
        // on incrémente le nombre d'essais
        i++;
    }
    // si au bout des essais l'utilisateur n'a pas trouvé la bonne réponse, on lui affiche la bonne réponse
    if (trouve == 0){
        printf("La reponse etait %d\n", reponse);
    }
}

void Durees(){
    srand(time(NULL));
    int trouve = 0;
    int i = 1;
    int resultat;
    // on met plusieurs options pour que le problème soit différent
    int option = rand() % 2;
    // option 1 est avec heure et minutes
    if (option == 0) {
        // dans l'exercice les heures vont de 1 à 10
        // les minutes vont de 0 à 59
        int heures = rand() % 10+1;
        int minutes = rand() % 60;
        while (trouve == 0 && i <= 3){
            // on affiche le problème
            printf("%d h %d min = ? min\n", heures, minutes);
            // on lit la réponse de l'utilisateur
            scanf("%d", &resultat);
            // on vérifie la réponse
            // si la réponse est correcte, on affiche un message de félicitations et on ajoute des points en fonction des essais
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
                // si la réponse est fausse, on affiche un message d'erreur et on lui dit combien d'essais il lui reste
            } else {
                printf("Perdu... Il vous reste %d essais\n", 3-i);
            }
            // on incrémente le nombre d'essais
            i++;
        }
        // si au bout des essais l'utilisateur n'a pas trouvé la bonne réponse, on lui affiche la bonne réponse
        if (trouve == 0){
            printf("La reponse etait %d\n", (heures*60)+minutes);
        }
    }
    // option 2 est avec minutes et secondes
    else {
        // dans l'exercice les minutes vont de 1 à 10
        int minutes = rand() % 10+1;
        // les secondes vont de 0 à 59
        int secondes = rand() % 60;
        // on fait une boucle tant que l'utilisateur n'a pas trouvé la bonne réponse et qu'il lui reste des essais
        while (trouve == 0 && i <= 3){
            // on affiche le problème
            printf("%d m %d s = ? s\n", minutes, secondes);
            // on lit la réponse de l'utilisateur
            scanf("%d", &resultat);
            // on vérifie la réponse
            // si la réponse est correcte, on affiche un message de félicitations et on ajoute des points en fonction des essais
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
                // si la réponse est fausse, on affiche un message d'erreur et on lui dit combien d'essais il lui reste
            } else {
                printf("Perdu... Il vous reste %d essais\n", 3-i);
            }
            // on incrémente le nombre d'essais
            i++;
        }
        // si au bout des essais l'utilisateur n'a pas trouvé la bonne réponse, on lui affiche la bonne réponse
        if (trouve == 0){
            printf("La reponse etait %d\n", (minutes*60)+secondes);
        }
    }
}

void Aires(){
    // on initialise le générateur de nombres aléatoires
    srand(time(NULL));
    // déclaration des variables
    int option1 = rand() % 5;
    int option2 = rand() % 5;
    // on fait en sorte que les deux unités soient différentes
    // si elles sont égales, on en choisit une autre
    while (option1 == option2){
        option2 = rand() % 5;
    }
    // si l'option 1 est plus grande que l'option 2, on les échange pour que la conversion soit possible
    if (option1 > option2){
        int temp = option1;
        option1 = option2;
        option2 = temp;
    }
    // on initialise le tableau de conversion
    char tabMesures[5][5] = {"dam2", "m2", "dm2", "cm2", "mm2"}; // sur le site on va de km jusqu'à mm, mais dans ce programme ça ne marche pas, apparemment le nombre est trop long et ça renvoie un chiffre négatif
    int trouve = 0;
    int i = 1;
    int resultat;
    // on calcule la réponse
    int a = rand() % 9 + 1;
    int reponse = a*pow(10, (option2-option1)*2);
    // on fait une boucle tant que l'utilisateur n'a pas trouvé la bonne réponse et qu'il lui reste des essais
    while (trouve == 0 && i <= 3){
        // on affiche le problème
        printf("%d %s = ? %s \n", a, tabMesures[option1], tabMesures[option2]);
        // on lit la réponse de l'utilisateur
        scanf("%d", &resultat);
        // on vérifie la réponse
        // si la réponse est correcte, on affiche un message de félicitations et on ajoute des points en fonction des essais
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
            // si la réponse est fausse, on affiche un message d'erreur et on lui dit combien d'essais il lui reste
        } else {
            printf("Perdu... Il vous reste %d essais\n", 3-i);
        }
        // on incrémente le nombre d'essais
        i++;
    }
    // si au bout des essais l'utilisateur n'a pas trouvé la bonne réponse, on lui affiche la bonne réponse
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
        if (tab_reponse[0] == 4) { // sans ce "if else", le programme affiche "quatrecinq" au lieu de "quatre"
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
        if (tab_reponse[1] == 4) { // sans ce "if", le programme affiche "quatrecinq" au lieu de "quatre"
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
            if (tab_reponse[3] == 4) { // sans ce "if", le programme affiche "quatrecinq" au lieu de "quatre"
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
        } else if (tab_reponse[4] == 4) { // sans ce "if", le programme affiche "quatrecinq" au lieu de "quatre"
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
            if (tab_reponse[6] == 4) { // sans ce "if", le programme affiche "quatrecinq" au lieu de "quatre"
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
        // on affiche le problème
        printf("Ecrivez le nombre en chiffres : ");
        // on lit la réponse de l'utilisateur
        scanf("%d", &reponse_utilisateur);
        // on vérifie la réponse
        // si la réponse est correcte, on affiche un message de félicitations et on ajoute des points en fonction des essais
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
            // si la réponse est fausse, on affiche un message d'erreur et on lui dit combien d'essais il lui reste
        } else {
            printf("Perdu... Il vous reste %d essais\n", 3-i);
        }
        // on incrémente le nombre d'essais
        i++;
    }
    // si au bout des essais l'utilisateur n'a pas trouvé la bonne réponse, on lui affiche la bonne réponse
    if (trouve == 0){
        printf("La reponse etait %d\n", choix_millions * 1000000 + choix_milles * 1000 + choix_reste);
    }
}

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
    // on fait le calcul de la réponse correcte
    reponse_correcte = nombres*nombres2 + nombres3;
    int trouve = 0;
    int i = 1;
    // on regarde si l'utilisateurs a bon
    while(trouve == 0 && i<=3){
        printf("Il y a %d %s dans %d %s on donne %d %s, combient y a t-il de %s maintenant? \n", nombres, choixBoite[choix2], nombres2, tab[choix1], nombres3, choixBoite[choix2], choixBoite[choix2]);
        scanf("%d", &reponse_candidat);
        // on vérifie la réponse
        // si la réponse est correcte, on affiche un message de félicitations et on ajoute des points en fonction des essais
        if (reponse_candidat == reponse_correcte){
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
        }
        // si la réponse est fausse, on affiche un message d'erreur et on lui dit combien d'essais il lui reste
        else{
            printf("Perdu... Il vous reste %d essais\n", 3-i);
        }
        // on incrémente le nombre d'essais
        i++;
    }
    // si au bout des essais l'utilisateur n'a pas trouvé la bonne réponse, on lui affiche la bonne réponse
    if (trouve == 0){
        printf("La reponse etait %d\n", reponse_correcte);
    }
    
}

void jeu_op(){
    // déclaration des variables
    int reponse_candidat;
    int resultat;
    int reponse_correcte;
    int nombre1,nombre2,nombre3,nombre4;
    // déclaration des opérations
    char operation[][4] = {"+", "-", "*", "/"};
    srand(time(NULL));
    // génération aléatoire des nombres et des opérations
    nombre1 = rand() % 10 + 1;
    nombre2 = rand() % 10 + 1;
    nombre3 = rand() % 10 + 1;
    nombre4 = rand() % 10 + 1;
    int op1 = rand() % 4;
    int op2 = rand() % 4;
    int op3 = rand() % 4;
    // mélange des nombres on mélange les nombres pour éviter de toujours avoir le même ordre
    int numbers[] = {nombre1, nombre2, nombre3, nombre4};
    for (int i = 3; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
    // on fait le calcul en fonction des opérations
    switch (op1) {
        case 0: resultat = numbers[0] + numbers[1]; break;
        case 1: resultat = numbers[0] - numbers[1]; break;
        case 2: resultat = numbers[0] * numbers[1]; break;
        case 3: resultat = numbers[0] / numbers[1]; break;
    }

    switch (op2) {
        case 0: resultat += numbers[2]; break;
        case 1: resultat -= numbers[2]; break;
        case 2: resultat *= numbers[2]; break;
        case 3: resultat /= numbers[2]; break;
    }

    switch (op3) {
        case 0: resultat += numbers[3]; break;
        case 1: resultat -= numbers[3]; break;
        case 2: resultat *= numbers[3]; break;
        case 3: resultat /= numbers[3]; break;
    }
    // affichage du problème
    printf("Ecris l'operation pour trouver : %d\n", resultat);
    printf("Tu dois utiliser les nombres suivants : %d, %d, %d et %d\n", nombre1, nombre2, nombre3, nombre4);
    printf("Tu peux utiliser les operations +, -, * et les parentheses ( ). Exemple : (8*3)+(4*7)\n");
    printf("Ecris ta reponse : ");
    char reponse_candidat_texte[100];
    char resultat_texte[100];

    // Convertis le résultat en texte
    sprintf(resultat_texte, "(%d %s %d) %s %d %s %d", 
            numbers[0], operation[op1], numbers[1], 
            operation[op2], numbers[2], 
            operation[op3], numbers[3]);

    // lis la réponse du candidat en str et la lie juste après qu'il ait cliqué sur entrée, il ignore les espaces aussi
    scanf(" %[^\n]", reponse_candidat_texte);
    // on initialise la réponse correcte à 0
    reponse_correcte = 0;
    // on enlève les espaces de la réponse du candidat
    char *ptr = reponse_candidat_texte;
    while (*ptr) {
        if (*ptr == ' ') {
            //déplace toute la châine de caractères vers la gauche
            memmove(ptr, ptr + 1, strlen(ptr));
        } else {
            // on avance le pointeur
            ptr++;
        }
    }

    //on créé 2 stacks, un pour les nombres et un pour les opérateurs
    int stack[100], top = -1;
    char operators[100];
    //montre qu'il n'y a rien dedans
    int op_top = -1;

    //on parcourt la réponse du candidat
    for (int i = 0; reponse_candidat_texte[i] != '\0'; i++) {
        //si le caractère est un nombre, on le met dans la pile
        if (isdigit(reponse_candidat_texte[i])) {
            int num = 0;
            //tant que le nombre reste le même, on le met dans la pile
            while (isdigit(reponse_candidat_texte[i])) {
                //si le nombre est 10 on a '1' et '0' et on le met dans la pile tel que 10 et pas 1 et 0
                num = num * 10 + (reponse_candidat_texte[i] - '0');
                //avance pour lire les chiffres
                i++;
            }
            // on décrémente i car il y a un i++ dans la boucle
            i--;
            //ajoute le nombre dans la pile
            stack[++top] = num;
        //si le caractère est une parenthèse ouvrante, on le met dans la pile
        } else if (reponse_candidat_texte[i] == '(') {
            //on met la parenthèse ouvrante dans la pile
            operators[++op_top] = reponse_candidat_texte[i];
        //si le caractère est une parenthèse fermante, on fait le calcul puisque ce n'est plus dans la parenthèse ce n'est plus prioritaire
        } else if (reponse_candidat_texte[i] == ')') {
            //on fait le calcul jusqu'à ce qu'on trouve la parenthèse ouvrante (donc un autre calcul prioritaire)
            while (op_top >= 0 && operators[op_top] != '(') {
                //on fait le calcul donc en l'enlevant de la pile
                int b = stack[top--];
                int a = stack[top--];
                char op = operators[op_top--];
                //calcul en fonction des opérateurs
                switch (op) {
                    case '+': stack[++top] = a + b; break;
                    case '-': stack[++top] = a - b; break;
                    case '*': stack[++top] = a * b; break;
                    case '/': stack[++top] = a / b; break;
                }
            }
            op_top--; // on enlève les '(' de la pile
        //si le caractère est un opérateur, on fait le calcul
        } else if (strchr("+-*/", reponse_candidat_texte[i])) {
            //on gère la priorité des opérations
            while (op_top >= 0 && strchr("+-*/", operators[op_top]) &&
                   ((reponse_candidat_texte[i] == '+' || reponse_candidat_texte[i] == '-') ||
                    (reponse_candidat_texte[i] == '*' || reponse_candidat_texte[i] == '/'))) {
                //on fait le calcul donc en l'enlevant de la pile        
                int b = stack[top--];
                int a = stack[top--];
                char op = operators[op_top--];
                //calcul en fonction des opérateurs
                switch (op) {
                    case '+': stack[++top] = a + b; break;
                    case '-': stack[++top] = a - b; break;
                    case '*': stack[++top] = a * b; break;
                    case '/': stack[++top] = a / b; break;
                }
            }
            //on change l'opérateur
            operators[++op_top] = reponse_candidat_texte[i];
        }
    }
    //on fait le calcul final en utilisant tout ce qui reste dans la pile
    while (op_top >= 0) {
        int b = stack[top--];
        int a = stack[top--];
        char op = operators[op_top--];
        switch (op) {
            case '+': stack[++top] = a + b; break;
            case '-': stack[++top] = a - b; break;
            case '*': stack[++top] = a * b; break;
            case '/': stack[++top] = a / b; break;
        }
    }
    //le résultat final est le dernier élément de la pile
    reponse_correcte = stack[top];

    // vérifie que le résultat est correct
    if (reponse_correcte == resultat) {
        printf("Bravo, vous avez repondu juste et gagne 10 points !\n");
        points += 10; // on ajoute 10 points si la réponse est correcte
    } else {
        printf("Dommage, la bonne reponse etait : %s. Vous n'avez pas gagne de points.\n", resultat_texte);
    }
}

// on définit une structure pour stocker les joueurs
typedef struct {
    char nom[20];
    int score;
    char dateHeure[20]; // Champ pour stocker la date et l'heure
} Joueur;

// on fait une fonction pour sauvegarder le score
void sauvegarderScore(char *nomJoueur, int nouveauxPoints) {
    // on ouvre le fichier en mode lecture
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
    // on laisse m'utilisateur le choix du jeu chosit
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
        printf("|10 : Grands nombres             |\n");
        printf("|11 : Probleme de logique        |\n");
        printf("|12 : Jeu des Operations         |\n");
        printf("|0 : Sortir du jeu               |\n");
        printf("+--------------------------------+\n");
        printf("Quel est votre choix ?\n");
        scanf("%d", &choix);

        // on vérifie que le choix est valide
        while (choix < 0 || choix > 12) {
            printf("Choix invalide, veuillez choisir un nombre entre 0 et 10\n");
            scanf("%d", &choix);
        }
        // on fait un switch pour choisir le jeu
        // on affiche le nom du jeu et on appelle la fonction correspondante
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
            case 11:
                printf("Probleme de logique\n");
                Probleme();
                break;
            case 12:
                printf("Jeu des Operations\n");
                jeu_op();
                break;
            case 0:
                printf("Merci pour votre visite\n");
                printf("Vous avez %d points en tout\n", points);

                // Demander à sauvegarder les points
                char choixSauvegarde;
                printf("Voulez-vous sauvegarder vos points ? (O/N)\n");
                scanf(" %c", &choixSauvegarde);
                // si l'utilisateur était déjà connecté, on sauvegarde directement
                // sinon on lui demande son nom
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