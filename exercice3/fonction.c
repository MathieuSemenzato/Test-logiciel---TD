#include <stdlib.h>
#include<stdio.h>
#include<time.h>

int regles_et_init()
{
	system("clear");
	printf("Bienvenue !\n");
	printf("Nous allons vous proposez de resoudre un labyrinthe en utilisant le moins de coup possible.\n");
	printf("Dans un premier temps, choissisez la taille du labyrinthe entre 6 et 20\n");
	printf("Entre 6 et 9 : petit labyrinthe\nEntre 10 et 15 : labyrinthe intermédiaire\nEntre 16 et 20 : grand labyrinthe\n");
	int tailleLigne;
	scanf("%d",&tailleLigne);

	return tailleLigne;
}

void creeLabyrinthe(char* tab,int tailleLigne,int tailleLaby)
{
	int c;
	int i;
	srand( time( NULL ) );
	for (i=0; i< tailleLaby; i++)
	{
		if (i < tailleLigne )
		{
			tab[i] = '*';
		}
		else if (i >= tailleLaby - tailleLigne )
		{
			tab[i] = '*';
		}
		else if ( (i % (tailleLigne) == 0) || (i % (tailleLigne) == tailleLigne-1))
		{
			tab[i] = '*';
		}
		else
		{
			tab[i] = '#';
			
		}	
	}
	int cpt = 0;
	int deplacement = tailleLigne+1;
	int change;
	int aleat;
	
	while (cpt != 8 + 5*(tailleLigne-6))
	{
		aleat = rand() % 3;
		if (aleat == 0)
		{
			if (tab[deplacement+1] == '#')
			{
				tab[deplacement+1] = ' '; //le chiffre 1 corresponds au parcours praticable pour trouver la sortie
				deplacement = deplacement + 1;
				change = 1;
				//cpt ++;
			}
		}
		else if (aleat == 1)
		{
			if (tab[deplacement+tailleLigne] == '#')
			{
				tab[deplacement+tailleLigne] = ' '; //le chiffre 1 corresponds au parcours praticable pour trouver la sortie
				deplacement = deplacement + tailleLigne;
				change = 1;
				//cpt ++;
			}
		}
		else
		{
			if (tab[deplacement-1] == '#')
			{
				tab[deplacement-1] = ' '; //le chiffre 1 corresponds au parcours praticable pour trouver la sortie
				deplacement = deplacement - 1;
				change = 1;	
				//cpt ++;
			}
		}
		
		if (change == 1)
		{
			cpt ++;
		}
		
	}
	tab[deplacement] = '/';

	if(tailleLigne>9)
	{
		for(i=0;i<2*tailleLigne;i++)
		{
			c=rand() % (tailleLaby/2);
			while((tab[c]!='#'))
			{
				c=rand() % tailleLaby;
			}		
			tab[c]=' ';
			if((tab[c+i]=='#'))
			{
				tab[c+i]=' ';
			}
		}
	}
	else
	{
		for(i=0;i<2*tailleLigne-i;i++)
		{
			c=rand() % (tailleLaby);
			if((tab[c]=='#'))
			{
				tab[c]=' ';
			}
		}
	}
	tab[tailleLigne+1]='v';
}

void afficheLabyrinthe(char* tab,int tailleLigne,int tailleLaby,int coordonne_personnage)
{
	printf("si il n'y a pas d'issues possibles, tapez la lettre p\n");
	int i;
	
	for (i=0; i<tailleLaby; i++)
	{
		if (i % tailleLigne == 0)
		{
			printf("\n");
		}
		if(tab[i]=='v')
		{
		tab[i]=' ';
		}
		if( i == coordonne_personnage)
		{	
			
			if(tab[i]!='#'){
				tab[i]='v';
			}
		}
	printf("%c", tab[i]);
	}
	printf("\n");
}


int deplacePersonnage(char* tab,int coordonne_personnage,int deplacement,int tailleLigne)
{
	if (deplacement==100){
		if((tab[coordonne_personnage+1]!='#')&&((tab[coordonne_personnage+1]!='*')))
		{
			coordonne_personnage=coordonne_personnage+1;
		}
	}
	else if  (deplacement==113){
		if((tab[coordonne_personnage-1]!='#')&&(tab[coordonne_personnage-1]!='*'))
		{
			coordonne_personnage=coordonne_personnage-1;
		}
	}
	else if  (deplacement==122){
		if((tab[coordonne_personnage-tailleLigne]!='#')&&(tab[coordonne_personnage-tailleLigne]!='*'))
		{
			coordonne_personnage=coordonne_personnage-tailleLigne;
		}
	}
	else if  (deplacement==115){
		if((tab[coordonne_personnage+tailleLigne]!='#')&&(tab[coordonne_personnage+tailleLigne]!='*'))
		{
			coordonne_personnage=coordonne_personnage+tailleLigne;
		}
	}
return coordonne_personnage;
}

