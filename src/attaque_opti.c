#include "importations.h"
/*
    Fonction qui affiches dans le terminal si les clés potentielles sont valides ou non.
*/
int estCles(int m1, int c1, int m2, int c2, int k1, int k2, int *box_s, int *box_p){    
    bool rescomp = true;
    if (c1 == doublechiffrement(m1, k1, k2, box_s, box_p)){
        if (c2 == doublechiffrement(m2, k1, k2, box_s, box_p)){  
            printf("Clés valides ! (k1, k2): (%#06x, %#06x)\n", k1, k2);
            return (1);
        }
        else{
            printf("Collisions ! (k1, k2): (%#06x, %#06x)\n", k1, k2);
        }
    }
    else{
        printf("Collisions ! (k1, k2): (%#06x, %#06x)\n", k1, k2);
    }
    return (0);
}
/*  
    Fonction de recherches des éléments en commun.
    Il prend en compte tout les doublons probables.
    Exemple:
    lm = {1, 51, 51, 51, 51, 80, 120}
    lc = {51, 51, 67, 74, 100, 153, 201}

    le programme prendra en compte les clés suivant:
    (1, 0), (2, 0), (3, 0), (4, 0), (1, 1), (2, 1), (3, 1), (4, 1)
*/
void recherche_cle(Tuplet **lm, Tuplet **lc, int m1, int c1, int m2, int c2, int *box_s, int *box_p){
    int i = 0;
    int j = 0;
    int nb_collision = 0;
    int nb_cles = 0;

    while (i < TAILLE - 1 && j < TAILLE - 1){
        if (lc[j]->val < lm[i]->val){
            j++;
        }
        else if (lc[j]->val > lm[i]->val){
            i++;
        }
        else if (lc[j]->val == lm[i]->val){
            nb_collision += 1;
            if (c2 == doublechiffrement(m2, lm[i]->cle, lc[j]->cle, box_s, box_p)){
                nb_cles += estCles(m1, c1, m2, c2, lm[i]->cle, lc[j]->cle, box_s, box_p);
                
            }

            /*
                PRISE EN COMPTE DES DOUBLONS.
                    Dans le cas où la clé est une clé potentielle, 
                    on rentre dans une phase de sous boucles:
                        1- on compare lm[i] avec tout les lc[locali] tel que lm[locali] == lc[j] et initié à j + 1
                        2- on compare lc[j] avec tout les lm[localj] tel que lc[localj] == lm[i] et initié à i + 1
                    Une fois ceci fait, on incrémente i et j de 1 pour avancer.
                    Ainsi on retrouve à chaque fois tout les doublons possibles.
            */
            // Etape 1 cité au dessus.
            if (i < TAILLE - 1 & lm[i + 1]->val == lm[i]->val){

                int locali = i + 1;
                while (locali < TAILLE - 1 & lm[locali]->val == lm[i]->val ){
                    
                    if (c2 == doublechiffrement(m2, lm[locali]->cle, lc[j]->cle, box_s, box_p)){
                        nb_cles += estCles(m1, c1, m2, c2, lm[locali]->cle, lc[j]->cle, box_s, box_p);
                    }
                    locali++;
                }
            }
            // Etape 2 cité au dessus.
            if (j < TAILLE - 1 & lc[j + 1]->val == lc[j]->val){
                int localj = j + 1;
                while (localj < TAILLE - 1 & lc[localj]->val == lc[j]->val ){
                    
                    if (c2 == doublechiffrement(m2, lm[i]->cle, lc[localj]->cle, box_s, box_p)){
                        nb_cles += estCles(m1, c1, m2, c2, lm[i]->cle, lc[localj]->cle, box_s, box_p);
                    }
                    localj++;
                }
            }
            i++;
            j++;
            
        }

    }
    printf("Nombre de collisions: %d\nNombre de clés valides: %d\n", nb_collision - nb_cles, nb_cles);
}


/* 
    Implémentation d'un pseudo code du tri rapide récursif 
    selon un tableau de pointeur de pointeur vers des éléments de la struct Tuplet
    (composé de val et cle).
*/
void trirapide(Tuplet **lmlc, int debut, int fin){
    
    int pivot;
    int i;
    int j;
    Tuplet *temp;
    if (debut < fin){
        pivot = debut;
        i = debut;
        j = fin;
        while (i < j) {
            while (lmlc[i]->val <= lmlc[pivot]->val && i < fin){               
                i++;
            }
            while (lmlc[j]->val > lmlc[pivot]->val){
                j--;
            }
            if (i < j) {
                temp = lmlc[i];
                lmlc[i] = lmlc[j];
                lmlc[j] = temp;
            }
        }
        
        temp = lmlc[pivot];
        lmlc[pivot] = lmlc[j];
        lmlc[j] = temp;
        
        trirapide(lmlc, debut, j - 1);
        trirapide(lmlc, j + 1, fin);

    }
}



/*
    Fonction qui génère les tableaux lm et lc comme décrit dans le cours sur le chiffrement à bloc du Cours.
*/
void creer_list(int m1, int c1, int bor1, int bor2, Tuplet **lm, Tuplet **lc, int* box_s, int* box_p, int* invbox_s, int* invbox_p){
    int i; 
    if (bor2 == TAILLE){
        bor2 += 1;
    }

    for (i = bor1; i < TAILLE; i++){
        int res[11];
        keygen_opti(i, res, box_s);

        lm[i]->cle = i;
        lm[i]->val = chiffrement(m1, res, box_s, box_p);
        lc[i]->cle = i;
        lc[i]->val = dechiffrement(c1, res, invbox_s, invbox_p);
    }


}


