#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "jeuu.h"

void save(game g)
{
  FILE *f=NULL;
  f=fopen("saveinfo.txt","a+");
  if(f!=NULL)
  {
  fprintf(f,"position perso = y= %d / x=%d \n",g.camera.x,g.camera.y);
  fprintf(f,"gestion de vie et de score = %d / %d \n",g.G.vie,g.G.score);
  fprintf(f,"num stage = %d \n",g.B.numbg);
  fclose(f);
  }
  else 
  printf("erreur\n");
}



