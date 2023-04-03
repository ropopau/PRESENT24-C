from couches_opti import permut, substit
from cadencement_opti import keygen_opti
import os
import time
'''
Algorithme present24 comme vu dans l'énoncé.
'''
def chiffrement(etat, gencle, box_s, box_p):
    i = 0
    while i < 11:
        etat = etat ^ gencle[i]
        etat = substit(etat, box_s)
        etat = permut(etat, box_p)

        

        i += 1
    etat = etat ^ gencle[-1]
    return etat

def doublechiffrement(msg, k1, k2, box_s, box_p):
    souscle1 = keygen_opti(k1, 11, box_s, False)
    souscle2 = keygen_opti(k2, 11, box_s, False)
    dbled = chiffrement(chiffrement(msg, souscle1, box_s, box_p), souscle2, box_s, box_p)
    return dbled