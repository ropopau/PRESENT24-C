
# Projet Attaque man in the middle en C

Ce programme a été crée afin d'effectuer une attaque par le milieu à partir de deux couples clair/chiffrés connus.


/!\ **Le dossier source python est seulement présent à titre indicatif afin de témoigner de l'historique du projet.** /!\

Nous avions tout d'abords voulu le coder en python. Cepandant, malgré le multiprocessing mis en place, la génération des listes lm et lc durait ~10 minutes. (Ancien code source (INCOMPLET) visible dans le dossier "old_src_python".)
C'est pourquoi nous avons finalement codé le projet en C.

Temps de créations des listes lm et lc: 
 - En python avec parallélisation: ~600 secondes.
 - En C sans parallélisation: ~30 secondes.

Soit une REDUCTION du temps d'exécutions de -95%.



## Exécution

Placez vous dans le dossier racine du projet.


Lancer l'attaque avec les couples de Sanghyeon PARK.

(m1, c1) = (61f06c,f45a76)
(m2, c2) = (2bcf92,c63bcc)

```bash
  make park
```

Lancer l'attaque avec les couples de Mohand-Hedi KASHI.

(m1, c1) = (06d8ac,fc85aa)
(m2, c2) = (531012,a66745)

```bash
  make kashi
```

Lancer l'attaque avec les couples de Sanghyeon PARK ET de Hedi KASHI.

```bash
  make
```