#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "jeuu.h"
#include <string.h>

void init_personnage (personnage *p)
{int i;
char nomr[300];
char noml[300];
char nomf[300];
char nomb[300];
p->vitesse=0;
for(i=0;i<9;i++)
{
sprintf(nomr,"/home/thepytro/Bureau/Projet jeu_init/img/personnage/jack/droit/r%d.png",i);
sprintf(noml,"/home/thepytro/Bureau/Projet jeu_init/img/personnage/jack/gauche/l%d.png",i);
sprintf(nomf,"/home/thepytro/Bureau/Projet jeu_init/img/personnage/jack/front/f%d.png",i);
sprintf(nomb,"/home/thepytro/Bureau/Projet jeu_init/img/personnage/jack/back/b%d.png",i);
p->tab[i]=IMG_Load(nomr);
p->tabl[i]=IMG_Load(noml);
p->tabf[i]=IMG_Load(nomf);
p->tabb[i]=IMG_Load(nomb);
}
p->image=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/personnage/jack/droit/f0.png");
p->r=0;
p->l=0;
p->f=0;
p->b=0;

p->positionP.x=360;
p->positionP.y=250;
p->REALPOS.x=360;
p->REALPOS.y=250;
p->POS.x=360;
p->POS.y=250;
}

void mvt_right (game *g,SDL_Surface *fenetre,int *i)
{
if ((*i)>8)
(*i)=0;

g->P.image=g->P.tab[*i];
                        g->P.REALPOS.x=((g->camera.x)+(g->camera.w)/2-10);
                        g->P.REALPOS.y=((g->camera.y)+(g->camera.h)/2-52);
                        (*i)++;
}


void mvt_left  (game *g,SDL_Surface *fenetre,int *i)
{
if ((*i)>8)
(*i)=0;

g->P.image=g->P.tabl[*i];
                        g->P.REALPOS.x=((g->camera.x)+(g->camera.w)/2-29);
                        g->P.REALPOS.y=((g->camera.y)+(g->camera.h)/2+5);
                        (*i)++;
}

void mvt_up (game *g,SDL_Surface *fenetre,int *i)
{
if ((*i)>8)
(*i)=0;

g->P.image=g->P.tabb[*i];
                        g->P.REALPOS.x=((g->camera.x)+(g->camera.w)/2-29);
                        g->P.REALPOS.y=((g->camera.y)+(g->camera.h)/2-52);
(*i)++;
}

void mvt_down (game *g,SDL_Surface *fenetre,int *i)
{
if ((*i)>8)
(*i)=0;

g->P.image=g->P.tabf[*i];
                        g->P.REALPOS.x=((g->camera.x)+(g->camera.w)/2+29);
                        g->P.REALPOS.y=((g->camera.y)+(g->camera.h)/2-20);
                        (*i)++;
}

void affichage_pers (game *g,SDL_Surface *fenetre)
{
if (g->B.numbg==0)
SDL_BlitSurface(g->P.image,NULL,fenetre,&g->P.positionP);
else
SDL_BlitSurface(g->P.image,NULL,fenetre,&g->P.POS);
}

void free_pers (personnage *p,SDL_Surface *fenetre)
{
SDL_FreeSurface(p->image);
SDL_Flip(fenetre);
}
