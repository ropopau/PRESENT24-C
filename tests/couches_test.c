#include <stdio.h>
#include <assert.h>
#include "../src/_couches_opti.h"
/*  Vecteurs tests
    clair  | maitre | chiffre
    ________________________
  1 000000 | 000000 | bb57e6
  2 ffffff | 000000 | 739293
  3 000000 | ffffff | 1b56ce
  4 f955b9 | d1bd2d | 47a929
*/

void test_substit(int *box_s, int *invbox_s){
    int ltest[11];
    int resttest;

    resttest = substit(0, box_s);
    assert(resttest == 13421772);

    resttest = substit(25, box_s);
    assert(resttest == 13421662);

    resttest = substit(0, invbox_s);
    assert(resttest == 5592405);

    resttest = substit(25, invbox_s);
    assert(resttest == 5592548);

    
}

void test_permut(int *box_p, int *invbox_p){
    int ltest[11];
    int resttest;

    resttest = permut(0, box_p);
    assert(resttest == 0);

    resttest = permut(25, box_p);
    assert(resttest == 262147);

    resttest = permut(0, invbox_p);
    assert(resttest == 0);

    resttest = permut(25, invbox_p);
    assert(resttest == 69633);
    


}