from encryptage_opti import chiffrement
from decryptage_opti import dechiffrement
from cadencement_opti import keygen_opti
'''
Fonction qui est appelé pendant le multiprocessing permettant de générer les listes lm et lc.
'''
def creer_liste(m1, c1, bor1, bor2, qm, qc, box_s, box_p, invbox_s, invbox_p, t):
    lm = []
    lc = []
    res = None
    if bor2 == t:
        bor2 += 1
    for i in range(bor1, bor2):
        res = keygen_opti(i, 11, box_s)
        lm.append((i, chiffrement(m1, res, box_s, box_p)))
        lc.append((i, dechiffrement(c1, res, invbox_s, invbox_p)))
    qm.put(lm) 
    qc.put(lc)

def trirapide():
    # Tri rapide à implémenter.
    pass

def recherchecommun():
    # Recherche des éléments communs à implémenter.
    pass