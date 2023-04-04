#include <stdio.h>
#include <assert.h>
#include "../src/_encdec.h"
#include "../src/_cadencement_opti.h"
#include "../src/_couches_opti.h"
/*  Vecteurs tests
    clair  | maitre | chiffre
    ________________________
  1 000000 | 000000 | bb57e6
  2 ffffff | 000000 | 739293
  3 000000 | ffffff | 1b56ce
  4 f955b9 | d1bd2d | 47a929
*/

void test_dechiffrement(int *invbox_s, int *invbox_p){
    int ltest[11];
    int resttest;
    // Vecteur 1
    keygen_opti(0x0, ltest, invbox_s);
    resttest = dechiffrement(0xbb57e6, ltest, invbox_s, invbox_p);
    assert(resttest == 0x0);

    // Vecteur 2
    keygen_opti(0x0, ltest, invbox_s);
    resttest = dechiffrement(0x739293 , ltest, invbox_s, invbox_p);
    assert(resttest == 0xffffff);
    

    // Vecteur 3
    keygen_opti(0xffffff , ltest, invbox_s);
    resttest = dechiffrement(0x1b56ce, ltest, invbox_s, invbox_p);
    assert(resttest == 0x0);
    

    // Vecteur 4
    keygen_opti(0xd1bd2d, ltest, invbox_s);
    resttest = dechiffrement(0xf955b9, ltest, invbox_s, invbox_p);
    assert(resttest == 0x47a929);


}

void test_chiffrement(int *box_s, int *box_p){
    int ltest[11];
    int resttest;
    // Vecteur 1
    keygen_opti(0x0, ltest, box_s);
    resttest = chiffrement(0x0, ltest, box_s, box_p);
    assert(resttest == 0xbb57e6);

    // Vecteur 2
    keygen_opti(0x0, ltest, box_s);
    resttest = chiffrement(0xffffff , ltest, box_s, box_p);
    assert(resttest == 0x739293);
    

    // Vecteur 3
    keygen_opti(0xffffff , ltest, box_s);
    resttest = chiffrement(0x0, ltest, box_s, box_p);
    assert(resttest == 0x1b56ce);
    

    // Vecteur 4
    keygen_opti(0xd1bd2d, ltest, box_s);
    resttest = chiffrement(0xf955b9, ltest, box_s, box_p);
    assert(resttest == 0x47a929);
}



int main(){
    int box_s[16] = {12, 5, 6, 11, 9, 0, 10, 13, 3, 14, 15, 8, 4, 7, 1, 2};
    int box_p[24] = {0, 6, 12, 18, 1, 7, 13, 19, 2, 8, 14, 20, 3, 9, 15, 21, 4, 10, 16, 22, 5, 11, 17, 23};
    int invbox_s[16] = {5, 14, 15, 8, 12, 1, 2, 13, 11, 4, 6, 3, 0, 7, 9, 10};
    int invbox_p[24] = {0, 4, 8, 12, 16, 20, 1, 5, 9, 13, 17, 21, 2, 6, 10, 14, 18, 22, 3, 7, 11, 15, 19, 23};

    test_chiffrement(box_s, box_p);
    printf("Tests de chiffrement réussis (cadencement et chiffrement).\n");
    test_dechiffrement(invbox_s, invbox_p);
    printf("Tests de déchiffrement réussis (cadencement et déchiffrement).\n");

}