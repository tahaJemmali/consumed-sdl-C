#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>
#include "jeuu.h"
#include "fonction.h"


/////////////////init_game///////////////////////
int init_game (game *g,SDL_Surface *fenetre)
{

    g->game_over=1;
    init_personnage(&g->P);
    init_background(&g->B);
    init_EntiterSecondaire(&g->ES);
    init_gestion(&g->G);
  g->zoom=1;
  g->cas=0;
    g->camera.w = 800;
    g->camera.h = 600;
    g->camera.x = 2300;
    g->camera.y = 2644;

    g->cameraStage.w = 800;
    g->cameraStage.h = 500;
    g->cameraStage.x = 0;
    g->cameraStage.y = 0;

//init_son(&g->R);
    return 0;
}

//////////////input/////////////////////

void input (int tab_key[])
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {

        switch (event.type)
        {

        case SDL_QUIT:
            exit(-1);
            break;
        case SDL_KEYDOWN:
            tab_key[event.key.keysym.sym]=1;
            break;
        case SDL_KEYUP:
            tab_key[event.key.keysym.sym]=0;
            break;
        }
    }
}


////////////////////update////////////////////////
void update(int tab_key[],game *g,SDL_Surface *fenetre)
{
    int reponse=0 ;
    int SPACE=1;

    fprintf(stderr,"\n x = %d y= %d \n",g->P.POS.x,g->P.POS.y);
    if (collision_Parfaite(*g,0)==4)
    {
        g->B.numbg=0;
    }
    if (collision_Parfaite(*g,0)==2)
    {
        g->B.numbg=1;
    }
    if (collision_Parfaite(*g,0)==3)
    {
        g->P.POS.x=360;
        g->P.POS.y=250;
        reponse=Enigme(fenetre);
        if (reponse==1)
           { g->B.numbg=0;
            gestion_score(&(*g));
           }
        else
{
            g->B.numbg=1;
           gestion_vie_score(&(*g));
 }   }


    if (tab_key[SDLK_UP]==1)
    {


        mvt_up (&(*g),fenetre,&g->P.f);
        if (collision_Parfaite(*g,2)!=0)
        {
            if (g->B.numbg==0)
                scrolling (&(*g),SDLK_UP,&g->camera);
            else
                scrolling (&(*g),SDLK_UP,&g->P.POS);
        }
        else
        {
            g->P.POS.x=360;
            g->P.POS.y=250;
        }

    }
    if (tab_key[SDLK_DOWN]==1)
    {

        mvt_down (&(*g),fenetre,&g->P.b);
        if (collision_Parfaite(*g,3)!=0)
        {
            if (g->B.numbg==0)
                scrolling (&(*g),SDLK_DOWN,&g->camera);
            else
                scrolling (&(*g),SDLK_DOWN,&g->P.POS);
        }
        else
        {
            g->P.POS.x=360;
            g->P.POS.y=250;
        }
 

    }
    if (tab_key[SDLK_RIGHT]==1)
    {

        mvt_right (&(*g),fenetre,&g->P.r);

        if (collision_Parfaite(*g,0)!=0)
        {
            if (g->B.numbg==0)
                scrolling (&(*g),SDLK_RIGHT,&g->camera);
            else
                scrolling (&(*g),SDLK_RIGHT,&g->P.POS);
        }
        else
        {
            g->P.POS.x=360;
            g->P.POS.y=250;
        }

    }
    if (tab_key[SDLK_LEFT]==1)
    {

        mvt_left  (&(*g),fenetre,&g->P.l);
        if (collision_Parfaite(*g,1)!=0)
        {
            if (g->B.numbg==0)
                scrolling (&(*g),SDLK_LEFT,&g->camera);
            else
                scrolling (&(*g),SDLK_LEFT,&g->P.POS);
        }
        else
        {
            g->P.POS.x=360;
            g->P.POS.y=250;
        }

    }
    if (tab_key[SDLK_z]==1)
    {

    }
    if (tab_key[SDLK_q]==1)
    {

    }
    if (tab_key[SDLK_d]==1)
    {

    }
    if (tab_key[SDLK_s]==1)
    {

    }
    if (tab_key[SDLK_KP_PLUS]==1)
    {
    zoom(&g->B.img_bg[0],&(*g),0.01);
    zoom(&g->B.img_bg_collide[0],&(*g),0.01);
    }
    if (tab_key[SDLK_KP_MINUS]==1)
    {
    zoom(&g->B.img_bg[0],&(*g),-0.01);
    zoom(&g->B.img_bg_collide[0],&(*g),-0.01);
    }

    if(SPACE)
{
    if (tab_key[SDLK_SPACE]==1)
    {
    g->P.vitesse=5;
    }
}


    if (tab_key[SDLK_RSHIFT]==1 || tab_key[SDLK_LSHIFT]==1)
    {
    g->P.vitesse=0;
    SPACE=0;
    }

/************************************************************/
if(tab_key[SDLK_i]==1)
{
g->cas=1;
}
/*************************************************************/
printf("%d %d \n",g->camera.x,g->camera.y);
}
////////////////////Display////////////////////////


void display (game *g,SDL_Surface *fenetre,SDL_Rect camera,int *j,int *i)
{
    SDL_Surface *ecran;
       // 
    if (g->B.numbg==0)
{
       // ecran=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
        display_background(g->B,ecran,g->camera);
       // affichage_es(g,fenetre);
}
    else
    {
        ecran=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
        SDL_BlitSurface(g->B.img_bg[g->B.numbg],NULL,ecran,&g->B.pos_bg);
    }
mini_map(fenetre,*g);
display_gestion(*g ,fenetre);
affichage_pers (&(*g),fenetre);

g->game_over=sous_menu(fenetre,*g,j,i);

    SDL_Flip(fenetre);
}

void zoom(SDL_Surface **map,game *g,float zoom_addition)
{
g->camera.x*=(float) 1/ g->zoom;
g->camera.y*=(float) 1/ g->zoom;
g->camera.h*=(float) 1/ g->zoom;
g->camera.w*=(float) 1/ g->zoom;
*map=rotozoomSurface(*map,0, (float) 1/ g->zoom , 0);
g->zoom +=zoom_addition;
*map=rotozoomSurface(*map,0,  g->zoom , 0);
g->camera.x*= g->zoom;
g->camera.y*= g->zoom;
g->camera.w*= g->zoom;
g->camera.h*= g->zoom;
}

void mini_map(SDL_Surface *fenetre,game g)
{
SDL_Rect minimap_pos;
SDL_Rect minimapcursor_pos;
SDL_Surface *minimapcursor;
minimapcursor=IMG_Load("cursor.png");
minimap_pos.x=fenetre->w/2-g.B.minimap->w/2;
minimap_pos.y=0;
SDL_BlitSurface(g.B.minimap,NULL,fenetre,&minimap_pos);
minimapcursor_pos.x = minimap_pos.x + ( g.camera.x ) *0.043 ; 
minimapcursor_pos.y = minimap_pos.y + (  g.camera.y ) *0.0425 ;
printf("cx=%d cy=%d\n",minimapcursor_pos.x,minimapcursor_pos.y);
SDL_BlitSurface(minimapcursor,NULL,fenetre,&minimapcursor_pos);
}

int sous_menu(SDL_Surface *fenetre,game g,int *j,int *i)
{

int val=-1;
if(g.cas==1)
{
SDL_Surface *image=NULL,*yes=NULL,*no=NULL;
SDL_Rect imgpos,yespos,nopos;
SDL_Event event;

imgpos.x=0;
imgpos.y=0;

image=IMG_Load("Savegamebg.png");
yes=IMG_Load("Yes.png");
no=IMG_Load("No.png");
yespos.x=173;
yespos.y=320;

nopos.x=461;
nopos.y=320;

SDL_BlitSurface(image,NULL,fenetre,&imgpos);
SDL_BlitSurface(yes,NULL,fenetre,&yespos);
SDL_BlitSurface(no,NULL,fenetre,&nopos);


SDL_WaitEvent(&event);
    switch (event.type)
	{
 printf("motionx=%d motiony=%d\n",event.motion.x,event.motion.y);
          case SDL_MOUSEMOTION:

 		              if ((event.motion.x>=173)&&(event.motion.y>=320)&&(event.motion.x<=173+205)&&(event.motion.y<=320+55))
	                        {  
                                   yes=IMG_Load("Yes1.png");
                                   no=IMG_Load("No.png");
SDL_BlitSurface(image,NULL,fenetre,&imgpos);
SDL_BlitSurface(yes,NULL,fenetre,&yespos);
SDL_BlitSurface(no,NULL,fenetre,&nopos);
break;
                                } 
                              if((event.motion.x>=461)&&(event.motion.y>=320)&&(event.motion.x<=461+205)&&(event.motion.y<=320+55))
                                { 
                                   yes=IMG_Load("Yes.png");
                                   no=IMG_Load("No1.png");
SDL_BlitSurface(image,NULL,fenetre,&imgpos);
SDL_BlitSurface(yes,NULL,fenetre,&yespos);
SDL_BlitSurface(no,NULL,fenetre,&nopos);
break;
                                }



	   case SDL_MOUSEBUTTONDOWN :
                 if(event.button.button==SDL_BUTTON_LEFT)
                {
 		              if ((event.button.x>=173)&&(event.button.y>=320)&&(event.button.x<=173+205)&&(event.button.y<=320+55))
	                        {  
                                   save(g);
                                   val=0;
                                   i=0;
                                   j=0;

                                   printf("Done1\n");
                                } 
                              if((event.button.x>=461)&&(event.button.y>=320)&&(event.button.x<=461+205)&&(event.button.y<=320+55))
                                { 
                                   val=0;
                                   i=0;
                                   j=0;

                                   printf("Done2\n");
                                }
                }

        }
   }


return val;
}

