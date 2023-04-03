'''
Algorithme de cadencement de clé avec options de debugage.
'''
def keygen_opti(maitre, nb_tour, box_s):
    # Liste des sous clés.
    list_tour = []
    # Les masque a utiliser pendant les opérations.
    # Masque pour récupérer la clé du tour.
    masque_ct = 0xffffff
    # Masque à appliquer lors de la rotation.
    masque_rot = 0xffffffffffffffffffff
    # Masque à appliquer lors de la récupération des 4 bits de poids forts.
    masque_bitpf = 0xfffffffffffffffffff
    # Masque pour récupérer la partie à xorer
    masque_xor = 0x1f
    # Masque pour placer la partie xorée
    masque_xor2 = 0xfffffffffffffff07fff
    # On initialise le registre en plaçant la clé maitre dans les 24 bits de poids forts.
    reg = 0 | (maitre << 56 )
    for ind in range(1, nb_tour + 1):

        # On récupère la clé de ce tour et on le met dans la liste.
        cletour = reg >> 16 & masque_ct
        list_tour.append(cletour)
        a = 2
        a << 1
        # ETAPE 1: On pivote de 61 bits vers la gauches
        reg, reg2 = reg << 61 , reg >> (80 - 61)
        reg = reg & masque_rot | reg2

        # ETAPE 2: On fais passer les 4 bits de poids fort dans la boite S.
        bitpf = reg >> 76
        nvbitpf = box_s[bitpf] << 76
        reg = nvbitpf | (reg & masque_bitpf)

        # ETAPE 3: On xore le nombre formé par les 5 bit entre 19 et 15 avec le numero du round
        nb = (reg >> 15) & masque_xor
        nvlnb = (nb ^ ind) 
        reg = (nvlnb << 15) | (reg & masque_xor2)
    return list_tour
