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

void test_dechiffrement(int *box_s,int *invbox_s, int *invbox_p){
    int ltest[11];
    int resttest;
    // Vecteur 1
    keygen_opti(0x0, ltest, box_s);
    resttest = dechiffrement(0xbb57e6, ltest, invbox_s, invbox_p);
    assert(resttest == 0x0);

    // Vecteur 2
    keygen_opti(0x0, ltest, box_s);
    resttest = dechiffrement(0x739293 , ltest, invbox_s, invbox_p);
    assert(resttest == 0xffffff);
    

    // Vecteur 3
    keygen_opti(0xffffff , ltest, box_s);
    resttest = dechiffrement(0x1b56ce, ltest, invbox_s, invbox_p);
    assert(resttest == 0x0);
    

    // Vecteur 4
    keygen_opti(0xd1bd2d, ltest, box_s);
    resttest = dechiffrement(0x47a929, ltest, invbox_s, invbox_p);
    assert(resttest == 0xf955b9);


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
