#include "importations.h"

/*
    Fonction de déchiffrement étant donnée un chiffré, une liste de sous clé
    ainsi que l'inverse des boite S et P.
*/
int dechiffrement(int cryp, int *gencle, int* invbox_s, int* invbox_p){
    cryp = cryp ^ gencle[10];
        
    for (int i = 9; i >= 0; i--){
        cryp = permut(cryp, invbox_p);
        cryp = substit(cryp, invbox_s);
        cryp = cryp ^ gencle[i];
    }
    return (cryp);
}