#include <stdio.h>
#include <stdlib.h>

int main() {
    int l, h;

    while (1) {
        printf("Veuillez entrer la longueur : \n");
        if (scanf("%d", &l) != 1) {
            while ((l = getchar()) != '\n' && l != EOF);
            continue;
        }

        printf("Veuillez entrer la hauteur : \n");
        if (scanf("%d", &h) != 1) {
            while ((h = getchar()) != '\n' && h != EOF);
            continue;
        }

        if (l < 1 || h < 1) {
            continue;
        }

        break;
    }

    char** jeu = (char **) malloc(h * sizeof(char*));
    if (jeu == NULL) {
        printf("Out of memory");
        exit(0);
    }

    for (int i = 0; i < h; i++) {
        jeu[i] = (char*) malloc(l * sizeof(char));

        if (jeu[i] == NULL) {
            printf("Out of memory");
            exit(0);
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < l; j++) {
            jeu[i][j] = '.';
        }
    }

    char joueur = 'x'; //0 = x, 1 = o
    while (1) {
        int colonne;

        printf("Colonne joueur %c ? ", joueur);
        if (scanf("%d", &colonne) != 1) {
            while ((colonne = getchar()) != '\n' && colonne != EOF);
            continue;
        }

        if (colonne < 0) {
            continue;
        }

        // if (colonne > l) {
        //     for (int i = h; i < colonne; i++) {
        //         jeu[i] = (char*) realloc(jeu[i], colonne);

        //         if (jeu[i] == NULL) {
        //             printf("Out of memory");
        //             exit(0);
        //         }
        //     }
        //     l = colonne;
        // }

        if (colonne == 0) {
            break;
        }

        for (int i = h - 1; i >= 0; i--) {
            if (jeu[i][colonne - 1] == '.') {
                jeu[i][colonne -1 ] = joueur;
                if (joueur == 'x') {
                    joueur = 'o';
                } else {
                    joueur = 'x';
                }
                break;
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < l; j++) {
                printf("%c ", jeu[i][j]);
            }
            printf("\n");
        }
    }

    for (int i = 0; i < l; i++) {
        free(jeu[i]);
    }
    free(jeu);
}