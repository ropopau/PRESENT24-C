#include "importations.h"

int main(int argc, const char *argv[]){
    
    clock_t debut, fin, debut1, fin1, debut2, fin2, debut3, fin3; 
    // Détermine quelles valeurs de clairs chiffré le programme doit prendre.
    int nb_utilisateur;
    int m1, m2, c1, c2;

    // Détermine les boites de substitution et de permutation ainsi que leurs inverse.
    int box_s[16] = {12, 5, 6, 11, 9, 0, 10, 13, 3, 14, 15, 8, 4, 7, 1, 2};
    int box_p[24] = {0, 6, 12, 18, 1, 7, 13, 19, 2, 8, 14, 20, 3, 9, 15, 21, 4, 10, 16, 22, 5, 11, 17, 23};
    int invbox_s[16] = {5, 14, 15, 8, 12, 1, 2, 13, 11, 4, 6, 3, 0, 7, 9, 10};
    int invbox_p[24] = {0, 4, 8, 12, 16, 20, 1, 5, 9, 13, 17, 21, 2, 6, 10, 14, 18, 22, 3, 7, 11, 15, 19, 23};

    // Alloue la mémoire pour les tableaux lm et lc.
    Tuplet **lm = malloc(sizeof(Tuplet *)* TAILLE);
    Tuplet **lc = malloc(sizeof(Tuplet *)* TAILLE);
    for (int i = 0; i < TAILLE; i++){
        lm[i] = malloc(sizeof(Tuplet));
        lc[i] = malloc(sizeof(Tuplet));
    }

    // Détermine quelles couples chiffré il faut choisir.
    if (argc >= 2){
        nb_utilisateur = atoi(argv[1]);
    }
        
    //Sanghyeon PARK
    if (nb_utilisateur == 1){

        m1 = 0x61f06c;
        c1 = 0xf45a76;
        m2 = 0x2bcf92; 
        c2 = 0xc63bcc;

        printf("==========================================\n");
        printf("  Recherche des clés de Sanghyeon PARK.\n");
        printf("==========================================\n");
        printf("       m1: %#06x et c1: %#06x\n", m1, c1);
        printf("       m2: %#06x et c2: %#06x\n", m2, c2);
        printf("==========================================\n\n");
    }
    //Hedi KASHI
    if (nb_utilisateur == 0){
        m1 = 0x06d8ac;
        c1 = 0xfc85aa;
        m2 = 0x531012;
        c2 = 0xa66745;
        printf("======================================\n");
        printf("  Recherche des clés de Hédi KASHI.\n");
        printf("======================================\n");
        printf("    m1: %#06x et c1: %#06x\n", m1, c1);
        printf("    m2: %#06x et c2: %#06x\n", m2, c2);
        printf("======================================\n\n");
        
    }
    // Début étape 1:
    debut = clock();
    creer_list(m1, c1, 0, TAILLE, lm, lc, box_s, box_p, invbox_s, invbox_p);
    fin = clock();
    float duree = ((double) (fin - debut)) / CLOCKS_PER_SEC;
    printf("============================================================\n");
    printf("Création liste... Temps: %fs.\n", duree);
    printf("============================================================\n\n");
    // Fin étape 1:

    // Début étape 2:
    debut1 = clock();
    trirapide(lm, 0, TAILLE - 1);
    trirapide(lc, 0, TAILLE - 1);
    fin1 = clock();
    float duree1 = ((double) (fin1 - debut1)) / CLOCKS_PER_SEC;
    printf("============================================================\n");
    printf("Tri rapide... Temps: %fs et Temps total: %fs.\n", duree1, duree + duree1);
    printf("============================================================\n\n");
    // Fin étape 2:

    // Début étape 3:
    debut2 = clock();
    recherche_cle(lm, lc, m1, c1, m2, c2, box_s, box_p);
    fin2 = clock();
    float duree2 = ((double) (fin2 - debut2)) / CLOCKS_PER_SEC;
    printf("============================================================\n");
    printf("Recherche clés... Temps: %fs et Temps total: %fs.\n", duree2, duree + duree1 + duree2);
    printf("============================================================\n\n");
    // Fin étape 3


    // Libérations des espaces mémoires pour éviter les fuites de mémoires.
    
    debut3 = clock();
    
    for (int i = 0; i < TAILLE; i++){
        free(lm[i]);
        free(lc[i]);
    }
    free(lm);
    free(lc);
    fin3 = clock();
    float duree3 = ((double) (fin3 - debut3)) / CLOCKS_PER_SEC;
    // Affichage du temps final
    printf("===================================\n");
    printf("  Temps final: %fs.\n", duree + duree1 + duree2 + duree3);
    printf("===================================\n\n");

    return (0);



}