

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"

void pre_menu(SDL_Surface *ecran,SDL_Surface *Fond,SDL_Surface *img_ng,SDL_Surface *img_option,SDL_Surface *img_help,SDL_Surface *img_exit,SDL_Surface *texte,SDL_Rect *pos,SDL_Rect *position_tt)
{




SDL_BlitSurface(Fond,NULL,ecran,NULL);
    pos->x=150;
    pos->y=220; 
    
SDL_BlitSurface(img_ng,NULL,ecran,pos);
    pos->y=300;
   
SDL_BlitSurface(img_option,NULL,ecran,pos);
    pos->y=370;

SDL_BlitSurface(img_help,NULL,ecran,pos);
    pos->y=440;
 
SDL_BlitSurface(img_exit,NULL,ecran,pos);
position_tt->x=630;
position_tt->y=580;

  


SDL_BlitSurface(texte,NULL,ecran,position_tt);
SDL_Flip(ecran);

}
