#ifndef __FONCTION__
#define __FONCTION__

int regles_et_init();
void creeLabyrinthe(char* tab,int tailleLigne,int tailleLaby, int coordonne_personnage, int compt);
void afficheLabyrinthe(char* tab,int tailleLigne,int tailleLaby,int coordonne_personnage);
void deplacer(char deplacement, int compt);
void deplacePersonnage(char* tab,int coordonne_personnage,int deplacement,int tailleLigne);

#endif