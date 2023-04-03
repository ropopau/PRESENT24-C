from couches_opti import permut, substit


'''
Fonction de déchiffrement. Inverse de l'algorithme present24 vu dans l'énoncé.
'''
def dechiffrement(cryp, gencle, invbox_s, invbox_p):
    etat = cryp ^ gencle[-1]
    for souscle in reversed(gencle[0:10]):
        etat = permut(etat, invbox_p)
        etat = substit(etat, invbox_s)
        etat = etat ^ souscle
    m = etat
    return m
