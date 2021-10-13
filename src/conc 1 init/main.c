#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>	
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include "fonction.h"
#include "jeuu.h"

int main()
{ 
 SDL_Surface *ecran = NULL, *Fond=NULL,*img_ng=NULL,*img_option=NULL,*img_help=NULL,*img_exit=NULL,*texte=NULL,*img_ng2=NULL,*img_option2=NULL,*img_help2=NULL,*img_exit2=NULL;
 SDL_Rect position_tt,pos;
SDL_Surface *img[772],*img1[760];
game g;
int o=1;
int d=1;
/*************************************************************************/
    int continuer = 1;
    int i=0,j=0,k=0,t=1;
    SDL_Event event;
/************************************************************************/
SDL_Init(SDL_INIT_VIDEO); 
TTF_Init();
/***********************************************************************/
   ecran= SDL_SetVideoMode(1200,626, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
if (ecran == NULL) 
    {
        fprintf(stderr, "Impossible de charger le mode vidÃ©o : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
/********************************************************************/
if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) 
   {
      printf("%s", Mix_GetError());
   }
/***********************************************************************/
     Mix_Chunk *music;
     music = Mix_LoadWAV("/home/thepytro/Bureau/Projet jeu_init/res/sound/god.wav");
   Mix_Chunk *swap;
swap = Mix_LoadWAV("/home/thepytro/Bureau/Projet jeu_init/res/sound/swap.wav");
Mix_PlayChannel(0, music, -1);
/***********************************************************************/
SDL_WM_SetCaption("The Consumed", NULL);
img_ng=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/buttons/NG.png");
img_option=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/buttons/op.png");
img_help=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/buttons/Help.png");
img_exit=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/buttons/quit.png");
img_ng2=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/buttons/NG1.png");
img_option2=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/buttons/op1.png");
img_help2=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/buttons/Help1.png");
img_exit2=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/buttons/quit1.png");
Fond = IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/bg/1/9.png");
/************************************************************************/
char image[50];
 /*for (i=0;i<772;i++)
    {
        sprintf(image,"/home/thepytro/Bureau/Projet jeu_init/img/PngFINALE/Final_00%d.png",i);
        img[i]=IMG_Load(image);
    }*/


/*********************************************************************/
TTF_Font *font=NULL;
SDL_Color c = {255, 255,255};
font = TTF_OpenFont("/home/thepytro/Bureau/Projet jeu_init/res/ttf/tf.ttf", 15);
texte = TTF_RenderText_Blended(font,"Copyrigth Redemption", c); 
/*********************************************************************/
//int o=1; 
//SDL_Surface *img[13];
//animer(ecran,img,Fond,&o );
/*if(o)
{
     for(i=0;i<772;i++)
					{										
                       // SDL_BlitSurface(Fond, NULL, ecran, NULL);
						SDL_BlitSurface(img[i],NULL,ecran,NULL);
                        SDL_Delay(20);											
						SDL_Flip(ecran);						
					}
o=0;
}*/

SDL_Delay(500); 
ecran= SDL_SetVideoMode(800,600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
pre_menu(ecran,Fond,img_ng,img_option,img_help,img_exit,texte,&pos,&position_tt);
/**********************************************************************/

/************************************************************************/
//g.game_over=continuer;

  while (continuer && g.game_over!=0)
    { 


//pre_menu(ecran,Fond,img_ng,img_option,img_help,img_exit,texte,&pos,&position_tt);
        
        SDL_WaitEvent(&event);   
switch (event.type) {

            case SDL_QUIT:
                continuer = 0;
                t=0;
                break;
case SDL_KEYDOWN :
 
if(event.key.keysym.sym == SDLK_UP ) 
{ if((i==1)||(i==0)) i=4; 
else i--;
} 
if(event.key.keysym.sym == SDLK_DOWN ) 
{ if (i==4) i=1; 
else i++; 
} 
  if((i==1)&&(j==0))
{
pre_menu(ecran,Fond,img_ng2,img_option,img_help,img_exit,texte,&pos,&position_tt);
Mix_VolumeChunk(swap, MIX_MAX_VOLUME);
Mix_PlayChannel(-1, swap, 0);
}
if((i==2)&&(j==0))
{
pre_menu(ecran,Fond,img_ng,img_option2,img_help,img_exit,texte,&pos,&position_tt);
Mix_VolumeChunk(swap, MIX_MAX_VOLUME);
Mix_PlayChannel(-1, swap, 0);
}
if((i==3)&&(j==0))
{
pre_menu(ecran,Fond,img_ng,img_option,img_help2,img_exit,texte,&pos,&position_tt);
Mix_VolumeChunk(swap, MIX_MAX_VOLUME);
Mix_PlayChannel(-1, swap, 0);
}         
if((i==4)&&(j==0))
{
pre_menu(ecran,Fond,img_ng,img_option,img_help,img_exit2,texte,&pos,&position_tt);
Mix_VolumeChunk(swap, MIX_MAX_VOLUME);
Mix_PlayChannel(-1, swap, 0);
}         

if(event.key.keysym.sym == SDLK_RETURN )
{
if(i==4) continuer=0;
if(i==3) 
{
SDL_BlitSurface(Fond,NULL,ecran,NULL);
SDL_Flip(ecran);
j=1;
}
if(i==2) 
{
options(ecran,&continuer,music,&j,&i);
pre_menu(ecran,Fond,img_ng,img_option,img_help,img_exit,texte,&pos,&position_tt);
SDL_Flip(ecran);
j=1;
}
if(i==1) 
{
SDL_Flip(ecran);
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
//SDL_Delay(50);
SDL_Flip(ecran);
//SDL_BlitSurface(Fond,NULL,ecran,NULL);
/***************************************************************/
char image1[50];
 /*for (i=0;i<760;i++)
    {
        sprintf(image,"/home/thepytro/Bureau/Projet jeu_init/img/PngCinematique/pic_00%d.png",i);
        img1[i]=IMG_Load(image1);
    }
SDL_Flip(ecran);*/
/***************************************************************/
/*if(d)
{
     for(i=0;i<760;i++)
					{										
                       // SDL_BlitSurface(Fond, NULL, ecran, NULL);
						SDL_BlitSurface(img1[i],NULL,ecran,NULL);
                        SDL_Delay(20);											
						SDL_Flip(ecran);						
					}
d=0;
}*/
/*****************************************************************/
SDL_Flip(ecran);
jeu (ecran,&j,&i);
SDL_Flip(ecran);
j=1;
}
}
if(event.key.keysym.sym == SDLK_ESCAPE )
{j=0;
k=0;
i=0;

SDL_Flip(ecran);
}

case SDL_MOUSEMOTION:

    if( (event.motion.x >= 150) && (event.motion.y >=222) && (event.motion.x <= 355) && (event.motion.y <= 277)&&(j==0))
		{
pre_menu(ecran,Fond,img_ng2,img_option,img_help,img_exit,texte,&pos,&position_tt);
Mix_VolumeChunk(swap, MIX_MAX_VOLUME);
Mix_PlayChannel(-1, swap, 0);
i=1;
break;
        	}
if((event.motion.x >= 150) && (event.motion.y >=300) && (event.motion.x <= 355) && (event.motion.y <= 355)&&(j==0))
		{
pre_menu(ecran,Fond,img_ng,img_option2,img_help,img_exit,texte,&pos,&position_tt);
Mix_VolumeChunk(swap, MIX_MAX_VOLUME);
Mix_PlayChannel(-1, swap, 0);
i=2;
break;
        	}
if((event.motion.x >= 150) && (event.motion.y >=370) && (event.motion.x <= 355) && (event.motion.y <= 425)&&(j==0))
		{
pre_menu(ecran,Fond,img_ng,img_option,img_help2,img_exit,texte,&pos,&position_tt);
Mix_VolumeChunk(swap, MIX_MAX_VOLUME);
Mix_PlayChannel(-1, swap, 0);
i=3;
break;
}
if((event.motion.x >= 150) && (event.motion.y >=440) && (event.motion.x <= 355) && (event.motion.y <= 495)&&(j==0))
		{
pre_menu(ecran,Fond,img_ng,img_option,img_help,img_exit2,texte,&pos,&position_tt);
i=4;
Mix_VolumeChunk(swap, MIX_MAX_VOLUME);
Mix_PlayChannel(-1, swap, 0);
break;
}

case SDL_MOUSEBUTTONDOWN :
        
        {
        if(event.button.button==SDL_BUTTON_LEFT)
        {
        if ((event.button.x>=150)&&(event.button.y>=222)&&(event.button.x<=355)&&(event.button.y<=277)&&(j==0))
	{ 

SDL_Flip(ecran);
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
//SDL_Delay(50);
SDL_Flip(ecran);
//SDL_BlitSurface(Fond,NULL,ecran,NULL);
/***************************************************************/
char image1[50];
/* for (i=0;i<760;i++)
    {
        sprintf(image,"/home/thepytro/Bureau/Projet jeu_init/img/PngCinematique/pic_00%d.png",i);
        img1[i]=IMG_Load(image1);
    }
SDL_Flip(ecran);*/
/***************************************************************/
/*if(d)
{
     for(i=0;i<760;i++)
					{										
                       // SDL_BlitSurface(Fond, NULL, ecran, NULL);
						SDL_BlitSurface(img1[i],NULL,ecran,NULL);
                        SDL_Delay(20);											
						SDL_Flip(ecran);						
					}
d=0;
}
SDL_Flip(ecran);*/
/*****************************************************************/
jeu (ecran,&j,&i);
SDL_Flip(ecran);
j=1;
        }
if((event.button.x >= 150) && (event.button.y >=300) && (event.button.x <= 355) && (event.button.y <= 355)&&(j<2))
{
options(ecran,&continuer,music,&j,&i);
pre_menu(ecran,Fond,img_ng,img_option,img_help,img_exit,texte,&pos,&position_tt);
SDL_Flip(ecran);
j=1;
k=1;
}
if((event.button.x >= 150) && (event.button.y >=370) && (event.button.x <= 355) && (event.button.y <= 425)&&(j<3))
{
SDL_BlitSurface(Fond,NULL,ecran,NULL);
SDL_Flip(ecran);
}
if((event.button.x >= 150) && (event.button.y >=440) && (event.button.x <= 355) && (event.button.y <=495)&&(j==0))
{
continuer=0;
}
}
}	
 
if(j==0)
{
if(i==0)
{
pre_menu(ecran,Fond,img_ng,img_option,img_help,img_exit,texte,&pos,&position_tt);
}

/*if(g.game_over==0)
{
i=0;
j=0;
pre_menu(ecran,Fond,img_ng,img_option,img_help,img_exit,texte,&pos,&position_tt);
}*/

}

if(j==-1){continuer = 0;}
}

}

TTF_Quit();   
 SDL_FreeSurface(Fond);
SDL_FreeSurface(img_ng);
SDL_FreeSurface(img_option);
SDL_FreeSurface(img_help);
SDL_FreeSurface(img_exit);
 Mix_CloseAudio();
 SDL_Quit();
    return EXIT_SUCCESS; 
}
