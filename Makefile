all: compil deux


deux: compil ./devoirPARK_KASHI
	./devoirPARK_KASHI 1
	./devoirPARK_KASHI 0
	rm -f devoirPARK_KASHI


park: compil ./devoirPARK_KASHI
	./devoirPARK_KASHI 1
	rm -f devoirPARK_KASHI


kashi: compil ./devoirPARK_KASHI
	./devoirPARK_KASHI 0
	rm -f devoirPARK_KASHI

compil: src/cadencement_opti.c src/couches_opti.c src/decryptage_opti.c src/encryptage_opti.c src/attaque_opti.c src/main.c
	gcc -o devoirPARK_KASHI src/cadencement_opti.c src/couches_opti.c src/decryptage_opti.c src/encryptage_opti.c src/attaque_opti.c src/main.c

compiltest: tests/main.c tests/couches_test.c tests/chiffre_test.c src/cadencement_opti.c src/couches_opti.c src/decryptage_opti.c src/encryptage_opti.c
	gcc -o unittester tests/main.c tests/couches_test.c tests/chiffre_test.c src/cadencement_opti.c src/couches_opti.c src/decryptage_opti.c src/encryptage_opti.c

test: compiltest unittester
	./unittester
	rm -f unittester

	