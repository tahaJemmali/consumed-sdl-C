#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

void animer(SDL_Surface *ecran,SDL_Surface *img[],SDL_Surface *Fond,int *o )
{
    int i;
    char a[10],ext[5],image[13];
    for (i=0;i<13;i++)
    {
        sprintf(a,"t%d",i);
        strcpy(image,"../img/bg/test/");
        strcpy(ext,".png");
        strcat(image,a);
        strcat(image,ext);
        img[i]=IMG_Load(image);
    }

   if(*o)
{
     for(i=0;i<13;i++)
					{										
                       // SDL_BlitSurface(Fond, NULL, ecran, NULL);
						SDL_BlitSurface(img[i],NULL,ecran,NULL);
                        SDL_Delay(60);											
						SDL_Flip(ecran);						
					}
*o=0;
}
}
