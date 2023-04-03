'''
Fonction de subsitution bit-à-bit.
'''
def substit(mot24, box_s):
    modif = 0
    for i in range(6):
        decal = i*4
        a = (mot24 >> decal) & 0xf
        modif = modif | (box_s[a] << decal)
    return modif

'''
Fonction de permutation bit-à-bit.
'''
def permut(mot24, box_p):
    modif = 0
    for i in range(24):
        a = mot24 & 0x1 
        modif = modif | (a << (23-box_p[23 - i])) 
        mot24 = (mot24 >> 1) 
    return modif