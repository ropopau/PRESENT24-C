#include "importations.h"


/*
    Fonction de chiffrement étant donnée un clair, une liste de sous clé
    ainsi que l'inverse des boite S et P.
*/
int chiffrement(int etat, int *gencle, int* box_s, int* box_p){
    for (int i =0; i < 10; i++){

        etat = etat ^ gencle[i];
        etat = substit(etat, box_s);
        etat = permut(etat, box_p);

    }
    return (etat ^ gencle[10]);

}
/*
    Fonction de chiffrement double pour effectuer un chiffrement 2present24 selon deux clés k1 et k1.
*/
int doublechiffrement(int m, int k1, int k2, int* box_s, int* box_p){
    int souscle1[11];
    int souscle2[11];
    keygen_opti(k1, souscle1, box_s);
    keygen_opti(k2, souscle2, box_s);
    int dbled = chiffrement(chiffrement(m, souscle1, box_s, box_p), souscle2, box_s, box_p);
    return (dbled);
}
