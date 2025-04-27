#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void jeu(){
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
    printf("Tu peux utiliser les opérations +, -, * et les parenthèses ( ). Exemple : (8*3)+(4*7)\n");
    printf("Ecris ta réponse : ");
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
        printf("Bravo, vous avez repondu juste !\n");
    } else {
        printf("Dommage, la bonne reponse etait : %s\n", resultat_texte);
    }



}
int main(){
    jeu();
    return 0;
}