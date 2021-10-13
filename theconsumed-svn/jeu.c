#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "jeuu.h"


/////////////////init_game///////////////////////
int init_game (game *g)
{
SDL_Surface *fenetre;
SDL_Init (SDL_INIT_VIDEO);
fenetre=SDL_SetVideoMode(200,300,32,SDL_HWSURFACE);
g->game_over=0;
init_personnage(&g->P);
init_background(&g->B);
init_EntiterSecondaire(&g->ES);
init_son(&g->R);
    return 0;
}

//////////////input/////////////////////
int input (int tab_key[])
{int cont=0;
    
    while (!cont)
{
SDL_Event event;
SDL_PollEvent (&event);

switch (event.type)
 {
case SDL_QUIT:
cont=1;
break;
case SDL_KEYDOWN:
tab_key[event.key.keysym.sym]=1;
break;
case SDL_KEYUP:
tab_key[event.key.keysym.sym]=0;
break;
}
}
return 0;
}

////////////////////update////////////////////////
void update(int tab_key[],game *g)
{
SDL_BlitSurface (g->R,NULL,fenetre,&g->positionR);
SDL_BlitSurface (g->ES.,NULL,fenetre,&g->ES.);
SDL_BlitSurface (g->P,NULL,fenetre,&g->positionP);
SDL_BlitSurface (g->B,NULL,fenetre,&g->positionB);

if (g->positionP == g->positionES.CercleStage1)
{
SDL_BlitSurface (g->BStage,NULL,fenetre,&g->positionBS);
void UpdateCollison();
}
else
{
   void UpdateCollison() //fonction de collision 
}
}
////////////////////Display////////////////////////
void display (game *g,SDL_Surface *ecran);
{
    Display_Player ();
    Display_Background ();
    Display_ES ();
}

/************************jeu*******************/
int main ()
{game g;
int tab_key[SDLK_LAST];
int test;
test=init_game(&g);
printf ("%d",test);
return 0;
}
