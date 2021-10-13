#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>
#include <stdlib.h>
#include <stdio.h>
#include "jeuu.h"

void init_background(background *bg)
{
    bg->img_bg_collide[0]=IMG_Load("map_collide.jpg");
    bg->img_bg[0]=IMG_Load("map.jpg");
    bg->img_bg_collide[1]=IMG_Load("collideStage1.jpg");
    bg->img_bg[1]=IMG_Load("stage 1.jpg");
    bg->img_bg_collide[2]=IMG_Load("collideStage2.jpg");
    bg->img_bg[2]=IMG_Load("stage 2.jpg");
    bg->pos_bg.x=0;
    bg->pos_bg.y=0;
    bg->numbg=0;
   bg->minimap=rotozoomSurface(bg->img_bg[0],0,0.04,0);


}

void display_background(background bg ,SDL_Surface *fenetre,SDL_Rect camera)
{
 SDL_BlitSurface(bg.img_bg[bg.numbg],&camera, fenetre ,NULL);
}

void free_background (background bg,SDL_Surface *fenetre)
{
    SDL_FreeSurface(bg.img_bg[bg.numbg]);
    SDL_FreeSurface(bg.minimap);
    SDL_Flip(fenetre);
}
