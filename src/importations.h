// Macros
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdint.h>
#include <time.h>
#include <stdbool.h>

#define TAILLE 16777216
#define TAILLE_CHUNK 4194304

typedef struct{
        int cle;
        int val;
    } Tuplet;

// attaque_opti.c
void creer_list(int m1, int c1, int bor1, int bor2, Tuplet **lm, Tuplet **lc, int* box_s, int* box_p, int* invbox_s, int* invbox_p);
void trirapide(Tuplet **lmlc, int debut, int fin);
void recherche_cle(Tuplet **lm, Tuplet **lc, int m1, int c1, int m2, int c2, int *box_s, int *box_p);

// cadencement_opti.c
void keygen_opti(uint64_t maitre, int *list_tour, int* box_s);

// chiffrement_opti.c et dechiffrement_opti.c
int dechiffrement(int cryp, int *gencle, int* invbox_s, int* invbox_p);
int chiffrement(int etat, int *gencle, int* box_s, int* box_p);
int doublechiffrement(int m, int k1, int k2, int* box_s, int* box_p);

// couches_opti.c
int substit(int mot24, int* box_s);
int permut(int mot24, int* box_p);