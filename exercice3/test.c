#include <stdlib.h>
#include<stdio.h>
#include "fonction.h"
#include<time.h>

int main()
{
	
	int tailleLigne;
	printf("Choissisez la taille du labyrinthe entre 6 et 20\n");
	printf("Entre 6 et 9 : petit labyrinthe, entre 10 et 15 : labyrinthe intermédiaire, entre 16 et 20 : grand labyrinthe\n");
	scanf("%d",&tailleLigne);
	int coordonne_personnage=tailleLigne+1;
	int tailleLaby = tailleLigne * tailleLigne;
	char tab[tailleLaby];
	char deplacement;
	int compt;
	
	creeLabyrinthe(tab,tailleLigne,tailleLaby);
	printf("si il n'y a pas d'issues possibles, tapez la lettre p\n");

	while(1){

		afficheLabyrinthe(tab,tailleLigne,tailleLaby,coordonne_personnage);
		scanf(" %c",&deplacement);
		compt=compt+1;
		if(deplacement==112){
			creeLabyrinthe(tab,tailleLigne,tailleLaby);
			coordonne_personnage=tailleLigne+1;
		}	
		coordonne_personnage=deplacePersonnage(tab,coordonne_personnage,deplacement,tailleLigne);
		if(tab[coordonne_personnage]=='/')
		{
		printf("Bravo, mission réussie! En %d coups!\n",compt);
		break;
		}
	}
	
	return 0;
}
