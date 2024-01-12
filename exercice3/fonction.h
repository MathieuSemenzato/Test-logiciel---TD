#ifndef __FONCTION__
#define __FONCTION__

int regles_et_init();
void creer_bordures(char* tab,int tailleLigne, int tailleLaby);
void creer_obstacles(char* tab, int tailleLigne);
void finalise_creation(char* tab,int tailleLigne,int tailleLaby, int *compt);
void creeLabyrinthe(char* tab, int tailleLigne, int tailleLaby, int *compt, int *coordonne_personnage);
void afficheLabyrinthe(char* tab, int tailleLigne, int tailleLaby, int *coordonne_personnage);
char deplacer(char* tab, int tailleLigne, int tailleLaby, int *compt, int *coordonne_personnage);
void deplacePersonnage(char* tab, int *coordonne_personnage, int deplacement, int tailleLigne, int *compt);

#endif