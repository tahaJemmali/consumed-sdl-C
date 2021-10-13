#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>
#include "jeuu.h"



void init_gestion(gestion *gt)
{
gt->vie=9;
gt->score=0;
int i;
char image[100];
TTF_Font *font=NULL;
SDL_Color c = {255, 255,255};
font = TTF_OpenFont("score.TTF", 30);
char texte[100];
sprintf(texte,"Score: %d",gt->score);
gt->texte_score = TTF_RenderText_Blended(font,texte, c); 
gt->pos_texte_score.x=0;
gt->pos_texte_score.y=70;
 /*for (i=0;i<5;i++)
    {
        sprintf(image,"/home/thepytro/Bureau/Projet jeu_init/img/entiter secondaire/les vie/c%d.png",i);
        gt->img_vie[i]=IMG_Load(image);
        gt->nbr_vie++;
    }*/
gt->nbr_vie=0;
gt->img_vie[0]=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/entiter secondaire/les vie/v0.png");
gt->nbr_vie=1;
gt->img_vie[1]=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/entiter secondaire/les vie/v1.png");
gt->nbr_vie=2;
gt->img_vie[2]=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/entiter secondaire/les vie/v2.png");
gt->nbr_vie=3;
gt->img_vie[3]=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/entiter secondaire/les vie/v3.png");
gt->nbr_vie=4;
gt->img_vie[4]=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/entiter secondaire/les vie/v4.png");
gt->nbr_vie=5;
gt->img_vie[5]=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/entiter secondaire/les vie/v5.png");
gt->nbr_vie=6;
gt->img_vie[6]=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/entiter secondaire/les vie/v5.png");
gt->nbr_vie=7;
gt->img_vie[7]=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/entiter secondaire/les vie/v7.png");
gt->nbr_vie=8;
gt->img_vie[8]=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/entiter secondaire/les vie/v8.png");
gt->nbr_vie=9;
gt->img_vie[9]=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/entiter secondaire/les vie/v9.png");
gt->img_go=IMG_Load("game_over.png");
gt->img_win=IMG_Load("win.png");

gt->pos_vie.x=0;
gt->pos_vie.y=0;

}


void gestion_vie_score(game *g)
{
/*int reponse=0;
reponse=Enigme(fenetre);
if(reponse!=1)
{*/
g->G.vie-=1;
//*}*/
g->G.nbr_vie=g->G.vie;
}

void gestion_score(game *g)
{
g->G.score+=20;
TTF_Font *font=NULL;
SDL_Color c = {255, 255,255};
font = TTF_OpenFont("score.TTF", 30);
char texte[100];
sprintf(texte,"Score: %d",g->G.score);
g->G.texte_score = TTF_RenderText_Blended(font,texte, c); 
}

void display_gestion(game g , SDL_Surface *fenetre)
{
if (g.G.nbr_vie>0)
{
SDL_BlitSurface(g.G.img_vie[g.G.nbr_vie],NULL,fenetre,NULL);
}
else
{
SDL_BlitSurface(g.G.img_go,NULL,fenetre,NULL);
//break;
}
if(g.G.score>=100)
{
SDL_BlitSurface(g.G.img_win,NULL,fenetre,NULL);
//break;
}
else
{
SDL_BlitSurface(g.G.texte_score,NULL,fenetre,&g.G.pos_texte_score);
}
}



