#include "unitttester.h"
#include <stdio.h>

int main(){
    int box_s[16] = {12, 5, 6, 11, 9, 0, 10, 13, 3, 14, 15, 8, 4, 7, 1, 2};
    int box_p[24] = {0, 6, 12, 18, 1, 7, 13, 19, 2, 8, 14, 20, 3, 9, 15, 21, 4, 10, 16, 22, 5, 11, 17, 23};
    int invbox_s[16] = {5, 14, 15, 8, 12, 1, 2, 13, 11, 4, 6, 3, 0, 7, 9, 10};
    int invbox_p[24] = {0, 4, 8, 12, 16, 20, 1, 5, 9, 13, 17, 21, 2, 6, 10, 14, 18, 22, 3, 7, 11, 15, 19, 23};
    test_chiffrement(box_s, box_p);
    printf("==================================================================\n");
    printf("Tests de chiffrement réussis (cadencement et chiffrement).\n");
    test_dechiffrement(box_s, invbox_s, invbox_p);
    printf("==================================================================\n");
    printf("Tests de déchiffrement réussis (cadencement et déchiffrement).\n");

    test_substit(box_s, invbox_s);
    printf("==================================================================\n");
    printf("Tests de substitution réussis (avec comme valeurs entier 0 et 25).\n");
    printf("==================================================================\n");
    test_permut(box_p, invbox_p);
    printf("Tests de déchiffrement réussis (avec comme valeurs entier 0 et 25).\n");
    printf("==================================================================\n");

}