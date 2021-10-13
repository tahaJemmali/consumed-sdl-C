#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "jeuu.h"


void scrolling (game *g,int bouton,SDL_Rect *camera)
{int val=25;

               switch (bouton)
                {
                      case SDLK_RIGHT :

                        if(camera->x <0)
                                camera->x = 0;
                        if (camera->y <0)
                                camera->y = 0;

                        camera->x+=2+g->P.vitesse;
                        camera->y-=1+g->P.vitesse;
                        


                       break;

                     case SDLK_LEFT :

                        if(camera->x <0)
                                camera->x = 0;
                        if (camera->y <0)
                                camera->y = 0;

                        camera->x-=2+g->P.vitesse;
                        camera->y+=1+g->P.vitesse;

                       break;

                      case SDLK_UP :

                         if(camera->x <0)
                                camera->x = 0;
                        if (camera->y <0)
                                camera->y = 0;

                        camera->x-=2+g->P.vitesse;
                        camera->y-=1+g->P.vitesse;
                       break;

                      case SDLK_DOWN :

                         if(camera->x <0)
                                camera->x = 0;
                        if (camera->y <0)
                                camera->y = 0;

                        camera->x+=2+g->P.vitesse;
                        camera->y+=1+g->P.vitesse;
                      break;
		}

}

