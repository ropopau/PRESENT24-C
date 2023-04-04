
# Si aucune commande n'est précisée, le programme lance la recherche de clé pour Sanghyeon PARK.
run: park

# Fonctions qui lance le programme avec comme argument 1 (pour que le programme puisse choisir les bons couples.)
park: compil ./devoirPARK_KASHI
	./devoirPARK_KASHI 1

kashi: compil ./devoirPARK_KASHI
	./devoirPARK_KASHI 0

# Fonction qui compile les test et l'execute.
test: compiltest unittester
	./unittester

# Compile les fichiers nécessaires à la recherches.
compil: src/cadencement_opti.c src/couches_opti.c src/decryptage_opti.c src/encryptage_opti.c src/attaque_opti.c src/main.c
	gcc -o devoirPARK_KASHI src/cadencement_opti.c src/couches_opti.c src/decryptage_opti.c src/encryptage_opti.c src/attaque_opti.c src/main.c

# Compile les fichiers nécessaires aux tests.
compiltest: tests/main.c tests/couches_test.c tests/chiffre_test.c src/cadencement_opti.c src/couches_opti.c src/decryptage_opti.c src/encryptage_opti.c
	gcc -o unittester tests/main.c tests/couches_test.c tests/chiffre_test.c src/cadencement_opti.c src/couches_opti.c src/decryptage_opti.c src/encryptage_opti.c

# Fonction utilitaire de nettoyage.
clean: 
	rm -f ./devoirPARK_KASHI
	rm -f ./unittester

	