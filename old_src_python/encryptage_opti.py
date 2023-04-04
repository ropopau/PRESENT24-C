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

def doublechiffrement(msg, gencle1, gencle2, box_s, box_p):
    dbled = chiffrement(chiffrement(msg, gencle1, box_s, box_p), gencle2, box_s, box_p)
    return dbled