
# DM Attaque par le milieu en C
## Sanghyeon PARK 22001322
## Mohand-Hedi KASHI 22005107

Ce programme a été créé afin d'effectuer une attaque par le milieu à partir de deux couples clair/chiffrés connus.


/!\ **Le dossier source python (old_src_python) est seulement présent à titre indicatif afin de témoigner de l'historique du projet.** /!\

Nous avions tout d'abords voulu le coder en python. Cepandant, malgré le multiprocessing mis en place, la génération des listes lm et lc durait ~10 minutes. (Ancien code source **incomplet** visible dans le dossier "old_src_python".)
C'est pourquoi nous avons finalement codé le DM en C.

**Temps de créations des listes lm et lc avec un intel Core i5-1035G7 sur secteur.**: 
 - En python avec parallélisation: ~600 secondes.
 - En C sans parallélisation: ~30 secondes.

Soit une REDUCTION du temps d'exécutions de -95%.

**La recherche complète dure environ 1 minutes 30.**


## EXECUTION

Placez vous dans le dossier racine du projet.


Lancer l'attaque avec les couples de Sanghyeon PARK.

(m1, c1) = (61f06c, f45a76) et 
(m2, c2) = (2bcf92, c63bcc)

```bash
  make park
```

Lancer l'attaque avec les couples de Mohand-Hedi KASHI.

(m1, c1) = (06d8ac, fc85aa) et 
(m2, c2) = (531012, a66745)

```bash
  make kashi
```

## TEST

Placez vous dans le dossier racine du projet.


Lancer les unittests présent dans le dossier "./tests".

```bash
  make test
```

## NETTOYAGE

Placez vous dans le dossier racine du projet.


Nettoyer les exécutables.

```bash
  make clean
```