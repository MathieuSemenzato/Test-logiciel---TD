#include <stdlib.h>
#include<stdio.h>
#include "fonction.h"
#include<time.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void test_move_right_within_maze(void) {
    char tab[36] = {'*', '*', '*', '*', '*', '*', 'v', ' ', ' ', '#', '*', '*', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', '#', '*'};
    int tailleLigne = 6;
    int tailleLaby = 36;
    int coordonne_personnage = 6;
    int compt = 20;

    char deplacement = 'd'; 
    deplacePersonnage(tab, &coordonne_personnage, deplacement, tailleLigne, &compt);

    CU_ASSERT_EQUAL(coordonne_personnage, 7);
    CU_ASSERT_EQUAL(compt, 21);
}

void test_move_right_twice_within_maze(void) {
    char tab[36] = {'*', '*', '*', '*', '*', '*', ' ', 'v', ' ', '#', '*', '*', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*'};
    int tailleLigne = 6;
    int tailleLaby = 36;
    int coordonne_personnage = 7;
    int compt = 21;

    char deplacement = 'd'; 
    deplacePersonnage(tab, &coordonne_personnage, deplacement, tailleLigne, &compt);
    deplacePersonnage(tab, &coordonne_personnage, deplacement, tailleLigne, &compt);

    CU_ASSERT_EQUAL(coordonne_personnage, 8);
    CU_ASSERT_EQUAL(compt, 22);
}

void test_move_left_within_maze(void) {
    char tab[36] = {'*', '*', '*', '*', '*', '*', ' ', ' ', 'v', '#', '*', '*', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*'};
    int tailleLigne = 6;
    int tailleLaby = 36;
    int coordonne_personnage = 8;
    int compt = 22;

    char deplacement = 'q'; 
    deplacePersonnage(tab, &coordonne_personnage, deplacement, tailleLigne, &compt);

    CU_ASSERT_EQUAL(coordonne_personnage, 7);
    CU_ASSERT_EQUAL(compt, 23);
}

void test_move_left_twice_within_maze(void) {
    char tab[36] = {'*', '*', '*', '*', '*', '*', ' ', 'v', ' ', '#', '*', '*', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*'};
    int tailleLigne = 6;
    int tailleLaby = 36;
    int coordonne_personnage = 7;
    int compt = 23;

    char deplacement = 'q'; 
    deplacePersonnage(tab, &coordonne_personnage, deplacement, tailleLigne, &compt);
    deplacePersonnage(tab, &coordonne_personnage, deplacement, tailleLigne, &compt);

    CU_ASSERT_EQUAL(coordonne_personnage, 6);
    CU_ASSERT_EQUAL(compt, 24);
}

void test_creer_bordures(void) {
    char tab[36]; 
    int tailleLigne = 6;
    int tailleLaby = 36;

    creer_bordures(tab, tailleLigne, tailleLaby);
    for (int i = 0; i < tailleLaby; i++) {
        if (i < tailleLigne || i >= tailleLaby - tailleLigne || i % tailleLigne == 0 || i % tailleLigne == tailleLigne - 1) {
            CU_ASSERT_EQUAL(tab[i], '*');
    	}
	}
}

void test_creeLabyrinthe(void) {
    int tailleLigne = 6;
	int coordonne_personnage = 7;
    int compt = 23;
    int tailleLaby = tailleLigne * tailleLigne;
    char tab[tailleLaby];
    char deplacement;

    creeLabyrinthe(tab, tailleLigne, tailleLaby, &compt, &coordonne_personnage);

    CU_ASSERT_EQUAL(coordonne_personnage, tailleLigne + 1);
    CU_ASSERT_EQUAL(compt, 0);
}


int main()
{
	/*
	initialisation des paramètres du labyrinthe
	on utilise des variables globales afin de permettre une mise à jour directement dans les fonctions
	cela rend le code plus lisible et, puisque l'on exécute une boucle assez longue permet d'éviter de définir constamment
	de nouvelles variables locales
	*/
	int tailleLigne = regles_et_init();
	int *coordonne_personnage=malloc(sizeof(int));
	int tailleLaby = tailleLigne * tailleLigne;
	char tab[tailleLaby];
	char deplacement;
	int *compt = malloc(sizeof(int));
	
	creeLabyrinthe(tab, tailleLigne, tailleLaby, compt, coordonne_personnage);

	while(1)
	{
		afficheLabyrinthe(tab,tailleLigne,tailleLaby,coordonne_personnage);
		deplacement = deplacer(tab, tailleLigne, tailleLaby, compt, coordonne_personnage);
		deplacePersonnage(tab,coordonne_personnage,deplacement,tailleLigne, compt);
		
		// On regarde si l'on a atteint la sortie du labyrinthe
		if(tab[*coordonne_personnage]=='/')
		{
			printf("Bravo, mission réussie! En %d coups!\n", *compt);
			break;
		}
	}

	CU_initialize_registry();
    CU_pSuite pSuite = CU_add_suite("Suite_deplacePersonnage", NULL, NULL);

	CU_add_test(pSuite, "test_move_right_within_maze", test_move_right_within_maze);
	CU_add_test(pSuite, "test_move_right_twice_within_maze", test_move_right_twice_within_maze);
	CU_add_test(pSuite, "test_move_left_within_maze", test_move_left_within_maze);
	CU_add_test(pSuite, "test_move_left_twice_within_maze", test_move_left_twice_within_maze);
	CU_add_test(pSuite, "test_creer_bordures",test_creer_bordures);
	CU_add_test(pSuite, "test_creeLabyrinthe",test_creeLabyrinthe);

	CU_basic_run_tests();
	CU_basic_show_failures(CU_get_failure_list());
	printf("\n");
	CU_cleanup_registry();
	return 0;
}