#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


void options(SDL_Surface *ecran,int *continuer,Mix_Chunk *music,int *j,int *i);
void pre_menu(SDL_Surface *ecran,SDL_Surface *Fond,SDL_Surface *img_ng,SDL_Surface *img_option,SDL_Surface *img_help,SDL_Surface *img_exit,SDL_Surface *texte,SDL_Rect *pos,SDL_Rect *position_tt);
//void UpdateEvents(Input* in);
void animer(SDL_Surface *ecran,SDL_Surface *img[],SDL_Surface *Fond,int *o );
void jeu (SDL_Surface *fenetre,int *j,int *i);
