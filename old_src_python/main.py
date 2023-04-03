from encryptage_opti import *
from decryptage_opti import *
from cadencement_opti import keygen_opti
from attaque_opti import creer_liste
import multiprocessing as mp
import time



if __name__ == "__main__":
    debug = False
    box_s = {0: 12, 1: 5, 2: 6, 3: 11, 4: 9, 5: 0, 6: 10, 
                7: 13, 8: 3, 9: 14, 10: 15, 11: 8, 12: 4, 13: 7, 
                14: 1, 15: 2}
    box_p = {0: 0, 1: 6, 2: 12, 3: 18, 4: 1, 5: 7, 6: 13, 7: 19, 8: 2, 9: 8, 10: 14,
            11: 20, 12: 3, 13: 9, 14: 15, 15: 21, 16: 4, 17: 10, 18: 16, 19: 22, 20: 5,
            21: 11, 22: 17, 23: 23}
    invbox_s = {12: 0, 5: 1, 6: 2, 11: 3, 9: 4, 0: 5, 10: 6,
                13: 7, 3: 8, 14: 9, 15: 10, 8: 11, 4: 12, 7: 13,
                1: 14, 2: 15} 
    invbox_p = {0: 0, 6: 1, 12: 2, 18: 3, 1: 4, 7: 5, 13: 6, 19: 7, 2: 8, 8: 9, 14: 10,
                20: 11, 3: 12, 9: 13, 15: 14, 21: 15, 4: 16, 10: 17, 16: 18, 22: 19, 5: 20,
                11: 21, 17: 22, 23: 23}
    m1, c1 = 0x61f06c, 0xf45a76
    m2, c2 = 0x2bcf92,0xc63bcc
    
    nb_cpu = 4#mp.cpu_count()
    qlm = mp.Queue()
    qlc = mp.Queue()
    ql = mp.Queue()
    long= 24
    taille = 2**long
    # 4 intervalle pour pouvoir divisier les taches par 4 .
    l_taille = [(i, i + taille // nb_cpu)  for i in range(0, taille, taille // nb_cpu)]
    # Initialisation des processus.
    pool_lmlc = [mp.Process(target=creer_liste, args=(m1, c1, bor1, bor2, qlm, qlc, box_s, box_p, invbox_s, invbox_p, taille)) for bor1, bor2 in l_taille]

    # Début du compte à rebours.
    ft = time.perf_counter()
    print("Debut etape1.")
    # Démarrage des processus.
    for proc in pool_lmlc:
        proc.start()
    lm = []
    lc = []
    for _ in range(4):
        print("Récupérations des clés")
        lm += qlm.get()
        lc +=  qlc.get()
        
    for proc2 in pool_lmlc:
        proc2.join()
    
    
    
    tg = time.perf_counter() - ft
    print('Temps Generations: ', tg)
    print("Fin etape1.")
    print("===========================")