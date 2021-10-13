#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include "jeuu.h"

/*
void free_es(entitersecondaire es)
{
SDL_FreeSurface(es.C->Civilb);
SDL_FreeSurface(es.C->Civilf);
SDL_FreeSurface(es.C->Civilr);
SDL_FreeSurface(es.C->Civill);
SDL_Quit();
}*/


void init_EntiterSecondaire (entitersecondaire *es)
{int i=0;
char nomr[300];
char noml[300];
char nomf[300];
char nomb[300];

for(i=0;i<9;i++)
{
sprintf(nomr,"/home/thepytro/Bureau/Projet jeu_init/img/personnage/jack/droit/r%d.png",i);
sprintf(noml,"/home/thepytro/Bureau/Projet jeu_init/img/personnage/jack/gauche/l%d.png",i);
sprintf(nomf,"/home/thepytro/Bureau/Projet jeu_init/img/personnage/jack/front/f%d.png",i);
sprintf(nomb,"/home/thepytro/Bureau/Projet jeu_init/img/personnage/jack/back/b%d.png",i);


es->C.Civilr[i]=IMG_Load(nomr);
es->C.Civill[i]=IMG_Load(noml);
es->C.Civilb[i]=IMG_Load(nomf);
es->C.Civilf[i]=IMG_Load(nomb);

}
es->C.image=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/personnage/jack/droit/f0.png");
es->C.posCivil.x=334;
es->C.posCivil.y=280;
es->C.l=0;
es->C.f=0;
es->C.r=0;
es->C.b=0;

}


void affichage_es(game *g,SDL_Surface *fenetre)
{

if (g->ES.C.f < g->P.f)
{
g->ES.C.image=g->ES.C.Civilf[g->P.f];
g->ES.C.f=g->P.f;
}
 if (g->ES.C.l < g->P.l)
{
g->ES.C.image=g->ES.C.Civill[g->P.l];
g->ES.C.l=g->P.l;
}
if (g->ES.C.r < g->P.r)
{
g->ES.C.image=g->ES.C.Civilr[g->P.r];
g->ES.C.r=g->P.r;
}
if (g->ES.C.b < g->P.b)
{
g->ES.C.image=g->ES.C.Civilb[g->P.b];
g->ES.C.b=g->P.b;
}

if (g->ES.C.b >8)
g->ES.C.b=0;

if (g->ES.C.l >8)
g->ES.C.l=0;

if (g->ES.C.f >8)
g->ES.C.f=0;

if (g->ES.C.r >8)
g->ES.C.r=0;

SDL_BlitSurface(g->ES.C.image,NULL,fenetre,&g->ES.C.posCivil);
}
