#ifndef __FONCTION_BIS__
#define __FONCTION_BIS__

int regles_et_init();
void creer_bordures(char* tab,int tailleLigne,int tailleLaby);
void creer_obstacles(char* tab, int tailleLigne);
void finalise_creation(char* tab,int tailleLigne,int tailleLaby, int *compt);
void creeLabyrinthe(char* tab,int tailleLigne,int tailleLaby, int *compt);
void afficheLabyrinthe(char* tab,int tailleLigne,int tailleLaby,int coordonne_personnage);
char deplacer(char* tab,int tailleLigne, int tailleLaby, int coordonne_personnage, int *compt);
int deplacePersonnage(char* tab,int coordonne_personnage,int deplacement,int tailleLigne, int *compt);

#endif