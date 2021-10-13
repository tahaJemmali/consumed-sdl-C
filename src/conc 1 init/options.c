#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

void options(SDL_Surface *ecran,int *continuer,Mix_Chunk *music,int *j,int *i)
{
   SDL_Surface  *ImageSLoaders=NULL,*img_screen = NULL, *bg=NULL,*img_full=NULL,*img_sfull=NULL,*img_check1=NULL,*img_check2=NULL;
SDL_Rect positionsd,positionbg,pos_screen,pos_full,pos_sfull,pos_check1,pos_check2;
int a =0 , b=0;
int cont=1;
 
 positionbg.x=0;
 positionbg.y=0;
 positionsd.x=140;
 positionsd.y=150;
/**********************************************/
pos_screen.x=30;
pos_screen.y= 300;
pos_full.x=170;
pos_full.y=300;
pos_check1.x=310;
pos_check1.y=300;
pos_sfull.x=450;
pos_sfull.y=300;
pos_check2.x=590;
pos_check2.y=300;
/**********************************************/


 bg=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/bg/1/1.png");
img_screen=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/buttons_op/screen.png");
img_full=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/buttons_op/ws.png");
img_sfull=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/buttons_op/fs.png");
img_check1=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/buttons_op/check_box.png");
img_check2=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/buttons_op/empty_box.png");



ImageSLoaders= IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/sound_track/6.png");


int k=0;

 SDL_Event e ;
 while( *continuer && cont ) 
    {
        SDL_WaitEvent(&e);
        if(e.type==SDL_QUIT)
        {*continuer=0;}
     if(e.key.keysym.sym==SDLK_ESCAPE)
             { 
      cont =0;  
      *i=0;
      *j=0;                
               break;
             }


 SDL_BlitSurface( bg , NULL , ecran , &positionbg) ;
  SDL_BlitSurface( ImageSLoaders , NULL , ecran , &positionsd) ;
    SDL_BlitSurface( img_screen , NULL , ecran , &pos_screen) ;
    SDL_BlitSurface( img_full ,NULL,ecran,&pos_full);
     SDL_BlitSurface( img_check1 ,NULL,ecran,&pos_check1);
      SDL_BlitSurface( img_sfull ,NULL,ecran,&pos_sfull);
      SDL_BlitSurface( img_check2 ,NULL,ecran,&pos_check2);
SDL_Flip(ecran);
    switch (e.type) {                
           case SDL_MOUSEBUTTONDOWN :
                   
           if (e.button.button == SDL_BUTTON_LEFT) 
{  
  printf("x=%d\ny=%d\n",e.motion.x,e.motion.y);
  if (((e.button.x>=309) && (e.button.x<=359)) && ((e.button.y>=215) && (e.button.y<=225)))
                               {

                            printf("a=%d\n",a);
                           if(a==0){
                           
                               ImageSLoaders=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/sound_track/5.png");
                               SDL_BlitSurface( ImageSLoaders , NULL , ecran , &positionsd) ;
                               SDL_Flip(ecran);
                               Mix_VolumeMusic( MIX_MAX_VOLUME/2);

                            //Mix_Volume(0,0);

                            a++;
                            }
                            else if (a==1)
                            {
                              ImageSLoaders=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/sound_track/4.png");
                               SDL_BlitSurface( ImageSLoaders , NULL , ecran , &positionsd) ;
                               SDL_Flip(ecran);
                               Mix_VolumeMusic( MIX_MAX_VOLUME/4);

                                a++;
        }
                            else if (a==2)
                            {
                              ImageSLoaders=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/sound_track/3.png");
                               SDL_BlitSurface( ImageSLoaders, NULL , ecran , &positionsd) ;
                               SDL_Flip(ecran);
                              Mix_VolumeMusic( MIX_MAX_VOLUME/8);
                                a++;
        }
                            else if (a==3)
                            {
                              ImageSLoaders=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/sound_track/2.png");
                               SDL_BlitSurface( ImageSLoaders, NULL , ecran , &positionsd) ;
                               SDL_Flip(ecran);
Mix_VolumeMusic( MIX_MAX_VOLUME/16);
                                a++;
        }
                            else if (a==4)
                            {
                              ImageSLoaders=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/sound_track/1.png");
                               SDL_BlitSurface( ImageSLoaders , NULL , ecran , &positionsd) ;
                               SDL_Flip(ecran);

         Mix_VolumeMusic( MIX_MAX_VOLUME/32);    
         a++;                   
        }
           else if (a==5)
                            {
                              ImageSLoaders=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/sound_track/0.png");
                               SDL_BlitSurface( ImageSLoaders , NULL , ecran , &positionsd) ;
                               SDL_Flip(ecran);

      Mix_VolumeMusic( MIX_MAX_VOLUME/999999);                   
        }
                            
        }
        if (((e.button.x>=485) && (e.button.x<=520)) && ((e.button.y>=206) && (e.button.y<=235)))
                               {

                            printf("a=%d\n",a);
                               if (a==5)
                            {
                              ImageSLoaders=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/sound_track/1.png");
                               SDL_BlitSurface( ImageSLoaders , NULL , ecran , &positionsd) ;
                               SDL_Flip(ecran);

        Mix_VolumeMusic( MIX_MAX_VOLUME/32);    
        a--;                  
        }
                          else if(a==4){
                           
                               ImageSLoaders=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/sound_track/2.png");
                               SDL_BlitSurface( ImageSLoaders, NULL , ecran , &positionsd) ;
                               SDL_Flip(ecran);
                               Mix_VolumeMusic( MIX_MAX_VOLUME/16);

                            //Mix_Volume(0,0);

                            a--;
                            }
                            else if (a==3)
                            {
                              ImageSLoaders=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/sound_track/3.png");
                               SDL_BlitSurface( ImageSLoaders , NULL , ecran , &positionsd) ;
                               SDL_Flip(ecran);
Mix_VolumeMusic( MIX_MAX_VOLUME/8);
                                a--;
        }
                            else if (a==2)
                            {
                              ImageSLoaders=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/sound_track/4.png");
                               SDL_BlitSurface( ImageSLoaders , NULL , ecran , &positionsd) ;
                               SDL_Flip(ecran);
Mix_VolumeMusic( MIX_MAX_VOLUME/4);
                                a--;
        }
                            else if (a==1)
                            {
                              ImageSLoaders=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/sound_track/5.png");
                               SDL_BlitSurface( ImageSLoaders , NULL , ecran , &positionsd) ;
                               SDL_Flip(ecran);
Mix_VolumeMusic( MIX_MAX_VOLUME/2);
                                a--;
        }
                            else if (a==0)
                            {
                              ImageSLoaders=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/sound_track/6.png");
                               SDL_BlitSurface( ImageSLoaders, NULL , ecran , &positionsd) ;
                               SDL_Flip(ecran);
Mix_VolumeMusic( MIX_MAX_VOLUME);
                                
        }
                            
        }
        if (((e.button.x>=590) && (e.button.x<=680)) && ((e.button.y>=300) && (e.button.y<=390))&&(k==0))
       
                          {   
                              SDL_Flip(ecran);
                             img_check2=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/buttons_op/check_box.png");
                                 img_check1=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/buttons_op/empty_box.png"); 
                                 ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_FULLSCREEN | SDL_DOUBLEBUF);
                                  
                                   
                                // SDL_BlitSurface( waw, NULL , ecran , &poswaw) ; 
                                 printf("test\n");                             
                                       SDL_Flip(ecran);
                                 k=1; }
         else if  (((e.button.x>=310) && (e.button.x<=400)) && ((e.button.y>=300) && (e.button.y<=390))&&(k==1))
{
    SDL_Flip(ecran);
                                img_check1=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/buttons_op/check_box.png");
                                img_check2=IMG_Load("/home/thepytro/Bureau/Projet jeu_init/img/buttons_op/empty_box.png");
 printf("k=%d\n",k);
ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                               
                               
                                      SDL_Flip(ecran);
                                 k=0;
}                           

}      

          
   case SDL_KEYDOWN : 
                      if (e.key.keysym.sym==SDLK_F10){
                        printf("b=%d\n" , b);
                   
                                 if (b==0){

                                 ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_FULLSCREEN | SDL_DOUBLEBUF);
                                 b++;

                                              }                         
                                else if (b==1) {

      ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
             b=0;
                            }              
                           
                        
                    }
                    }

 





}
SDL_FreeSurface(bg);
SDL_FreeSurface(ImageSLoaders);


}

