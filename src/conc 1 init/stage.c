#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "jeuu.h"
#include "fonction.h"

/************************jeu*******************/
void jeu (SDL_Surface *fenetre,int *j,int *i)
{

    game g;
    int tab_key[325]={0};
SDL_EnableKeyRepeat(0,0);
    //SDL_Init (SDL_INIT_VIDEO);
   // fenetre=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);

    if (fenetre == NULL)
    {
        fprintf(stderr,"error %s \n",SDL_GetError());
        exit(EXIT_FAILURE);
    }
init_game (&g,fenetre);


    while (tab_key[SDLK_ESCAPE]!=1 && g.game_over!=0)
    {
input (tab_key);
update(tab_key,&g,fenetre);
//display (&g,fenetre,g.camera);
display (&g,fenetre,g.camera,j,i);
SDL_Flip(fenetre);
    }


//free_es(g.ES);
free_background (g.B,fenetre);
free_pers (&g.P,fenetre);
//SDL_Flip(fenetre);
    
}



