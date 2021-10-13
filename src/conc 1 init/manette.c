#include "jeuu.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>



void arduinoWriteData(char x)
{
    char chemin[]="/dev/ttyUSB0";
    FILE*f;

    f=fopen(chemin,"w");
    if(f == NULL)
        printf("erreur\n");

    fprintf(f,"%c\n",x);
    fclose(f);


}

void arduinoReadData(char *x,FILE *f)
{


 if(f==NULL)
{
    printf("erreur\n");
}
while (!feof(f))
{
        fscanf(f,"%c\n",x);
}

  // printf("x=%c\n",*x);
        

 
}
