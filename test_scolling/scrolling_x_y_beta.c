
#include <SDL/SDL_image.h>	
#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>


void main(int argc, char *argv[])
{
SDL_Surface *background=NULL;
        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_Surface *ecran=NULL;
        // screen = SDL_SetVideoMode(500, 153, 32, SDL_SWSURFACE);
//SDL_HWSURFACE | SDL_DOUBLEBUF         
     ecran = SDL_SetVideoMode(1000,600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF|SDL_FULLSCREEN );
        int running = 1;
        const int FPS = 30;
        const int speedx =8;
	const int speedy =8;
        Uint32 start;
        int x,y;
        x = 0;
        y = 0;
        //background = SDL_LoadBMP("8000-600px stage1.bmp");
	background = IMG_Load ("waw.jpg");
        
       
        
        SDL_Rect camera;
        camera.x = 0;
        camera.y = 0;
        camera.w = 1000;
        camera.h = 600;
        int b[3] = {0,0,0};
        while(running) {
                start = SDL_GetTicks();
                SDL_Event event;
  	              while(SDL_PollEvent(&event)) {
                        switch(event.type) {
                                case SDL_QUIT:
                                        running = 0;
                                        break;
                                case SDL_KEYDOWN:
                                        switch(event.key.keysym.sym)
                                        {
                                                case SDLK_RIGHT:
                                                        b[0] = 1;
                                                        break;
                                                case SDLK_LEFT:
                                                        b[1] = 1;
                                                        break;
						case SDLK_UP:
							b[2] = 1;
							break;
						case SDLK_DOWN:
							b[3] = 1;
							break;
                                                case SDLK_ESCAPE:
                                                        running = 0;
                                                        break;
                                        }
                                        break;
                                case SDL_KEYUP:
                                        switch(event.key.keysym.sym)
                                        {
                                                case SDLK_RIGHT:
                                                        b[0] = 0;
                                                        break;
                                                case SDLK_LEFT:
                                                        b[1] = 0;
						case SDLK_UP:
							b[2] = 0;
						case SDLK_DOWN:
							b[3] = 0;
                                                        break;
                                        }
                                        break;
                        }
                }
 
                
                if(b[0])
                {
                        x += speedx;
                        camera.x += speedx;
                        if(camera.x >= 8000-1000)
                                camera.x = 0;
                }
                else if(b[1])
                {
                        x -= speedx;
                        camera.x -= speedx;
                        if(camera.x <= 0)
                                camera.x = 8000-1000;
                }
		else if(b[3])
		{

                        y += speedy;
                        camera.y += speedy;
                        if(camera.y >= 8000-600)
                                camera.y = 0;
		}
		else if(b[2])
		{

                        y -= speedy;
                        camera.y -= speedy;
                        if(camera.y <= 0)
                                camera.y = 8000-600;
		}
 
                
 
                
                SDL_BlitSurface(background, &camera, ecran, NULL);
                SDL_Flip(ecran);
                if(1000/FPS > SDL_GetTicks()-start) {
                        SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
                }
fprintf (stderr,"camera x : %d \n camera y : %d \n",camera.x,camera.y);
        }
        SDL_FreeSurface(background);
        
        SDL_Quit();
        
}
