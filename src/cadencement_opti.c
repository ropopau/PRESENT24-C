#include <stdint.h>
#define NB_TOUR 11

/*
Fonction qui applique l'algorithme de cadencement présenté dans l'énoncé.
*/
void keygen_opti(uint64_t maitre, int *list_tour, int* box_s){
    //Le maximum de bit d'un entier est de 64.
    //Il faut donc diviser en deux partie: 
    //part1 pour les bits de poids fort de 79 à 40.    
    uint64_t part1 = maitre << 16;
    //part2 pour les bits de poids faibles de 39 à 0.
    uint64_t part2 = 0;

    // Masque pour récupèrer les 19 bits de poids faibles. 
    uint64_t masque_pfa = 0x7ffff;
    // Masque pour supprimer les 4 bits de poids forts.
    uint64_t masque_4pfo = 0xfffffffff;

    uint64_t part1temp;
    uint64_t part2temp;
    
    for (int i = 1; i < NB_TOUR + 1; i++){
        // On récupère les clés de chaques tours.
        list_tour[i - 1] = part2 >> 16;

        // ETAPE 1: On pivote le registre de 61 bits vers la gauches 
        // Cela reviens à faire une rotation de 19 bits vers la droite.
        part1temp = (part1 & masque_pfa) << 21;
        part2temp = (part2 & masque_pfa) << 21;
        part1 = (part1 >> 19) | part2temp;
        part2 = (part2 >> 19) | part1temp;
        

        // ETAPE 2: On isole les 4 bits de poids fort pour les passer dans la box S.
        uint64_t bitpfo = part1 >> 36;
        // On supprimes les 4 bits de poids forts.
        part1 = part1 & masque_4pfo;
        uint64_t nvval = box_s[bitpfo];
        bitpfo = nvval << 36;
        part1 = part1 | bitpfo;

        // ETAPE 3: On xor le numéro de tour actuel au 5 bit entre 15 et 19. 
        uint64_t val = i << 15;
        part2 = part2 ^ val;
    }

}