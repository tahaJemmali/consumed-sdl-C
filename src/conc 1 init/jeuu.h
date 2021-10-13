#ifndef JEUU_H_INCLUDED
#define JEUU_H_INCLUDED
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>	
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct gestion
{
SDL_Surface *img_vie[10];
SDL_Surface *img_go;
SDL_Surface *img_win;
SDL_Surface *texte_score;
SDL_Rect pos_vie;
SDL_Rect pos_texte_score;
int nbr_vie,vie,score;
}gestion;

typedef struct Civil
{
SDL_Surface *image;
SDL_Surface *Civilf[10];
SDL_Surface *Civill[10];
SDL_Surface *Civilb[10];
SDL_Surface *Civilr[10];
SDL_Rect posCivil;
int r,l,f,b;

}Civil;

typedef struct entitersecondaire
{
  Civil C;

}entitersecondaire;

typedef struct enigme
{
SDL_Surface *texte;
SDL_Surface *answer[4];
SDL_Rect postxt;
SDL_Rect posans1;
SDL_Rect posans2;
SDL_Rect posans3;
}enigme;

typedef struct enigmes
{
int nbenigmes;
enigme E[30];
}enigmes;

typedef struct personnage
{SDL_Surface *image;
SDL_Surface *tab[10];
SDL_Surface *tabl[10];
SDL_Surface *tabf[10];
SDL_Surface *tabb[10];
SDL_Rect positionP ;
SDL_Rect REALPOS;
SDL_Rect POS;
int r,l,f,b;
int vitesse;
}
personnage ;

typedef struct background
{
    SDL_Surface *img_bg[5];
    SDL_Surface *img_bg_collide[5];
    int numbg;
    SDL_Rect pos_bg;
    SDL_Surface *minimap;
}background;

typedef struct game
{
int game_over;
entitersecondaire ES;
personnage P;
background B;
gestion G;
SDL_Rect camera;
SDL_Rect cameraStage;
int cas;
float zoom;
//ressource R;
}game;

void init_background(background *bg);
void display_background(background bg ,SDL_Surface *fenetre,SDL_Rect camera);
void free_background (background bg,SDL_Surface *fenetre);

void init_personnage (personnage *p);
void mvt_right (game *g,SDL_Surface *fenetre,int *i);
void mvt_left  (game *g,SDL_Surface *fenetre,int *i);
void mvt_up (game *g,SDL_Surface *fenetre,int *i);
void mvt_down (game *g,SDL_Surface *fenetre,int *i);
void affichage_pers (game *g,SDL_Surface *fenetre);
void free_pers (personnage *p,SDL_Surface *fenetre);

void init_EntiterSecondaire (entitersecondaire *es);
void affichage_es(game *g,SDL_Surface *fenetre);
void Move (game *g ,SDL_Surface *fenetre, int Nvoiture);
void free_es(entitersecondaire es);


int init_game (game *g,SDL_Surface *fenetre);
void input (int tab_key[]);
void update(int tab_key[],game *g,SDL_Surface *fenetre);
void display (game *g,SDL_Surface *fenetre,SDL_Rect camera,int *j,int *i);
void play (game *g);

void scrolling (game *g,int bouton,SDL_Rect *camera);

int collision_Parfaite(game g,int d);
SDL_Color GetPixel(SDL_Surface *surface,int x,int y);
int collisionAB(SDL_Surface *iA,SDL_Surface *iB,SDL_Rect pA,SDL_Rect pB);

void initialiser_enigmes(enigmes *ES);
int  afficher_enigmes(enigmes *ES,SDL_Surface *fenetre);
int ResolutionEniges(enigmes ES,int IndiceEnigme,char an[]);
int Enigme (SDL_Surface *fenetre );

void zoom(SDL_Surface **map,game *g,float zoom_addition);
void mini_map(SDL_Surface *fenetre,game g);

void init_gestion(gestion *gt);
void gestion_vie_score(game *g);
void display_gestion(game g , SDL_Surface *fenetre);

void save(game g);
int sous_menu(SDL_Surface *fenetre,game g,int *j,int *i);
void gestion_score(game *g);

#endif // JEUU_H_INCLUDED
