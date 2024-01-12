#include <stdlib.h>
#include<stdio.h>
#include "fonction.h"
#include<time.h>

int main()
{
	/*
	initialisation des paramètres du labyrinthe
	on utilise des variables globales afin de permettre une mise à jour directement dans les fonctions
	cela rend le code plus lisible et, puisque l'on exécute une boucle assez longue permet d'éviter de définir constamment
	de nouvelles variables locales
	*/

	int tailleLigne = regles_et_init();
	int coordonne_personnage;
	int tailleLaby = tailleLigne * tailleLigne;
	char tab[tailleLaby];
	char deplacement;
	int compt;
	
	creeLabyrinthe(tab,tailleLigne,tailleLaby, coordonne_personnage, compt);
	while(1)
	{
		afficheLabyrinthe(tab,tailleLigne,tailleLaby,coordonne_personnage);
		deplacer(deplacement, compt);
		
		deplacePersonnage(tab,coordonne_personnage,deplacement,tailleLigne);
		
		// On vérifie si l'on a atteint la sortie
		if(tab[coordonne_personnage]=='/')
		{
			printf("Bravo, mission réussie! En %d coups!\n",compt);
			break;
		}
	}
	return 0;
}