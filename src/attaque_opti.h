#define TAILLE 16777216

typedef struct{
        int cle;
        int val;
    } Tuplet;

void creer_list(int m1, int c1, int bor1, int bor2, Tuplet **lm, Tuplet **lc, int* box_s, int* box_p, int* invbox_s, int* invbox_p);
void trirapide(Tuplet **lmlc, int debut, int fin);
void recherche_cle(Tuplet **lm, Tuplet **lc, int m1, int c1, int m2, int c2, int *box_s, int *box_p);