#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "jeuu.h"

/*int collisionAB(SDL_Surface *iA,SDL_Surface *iB,SDL_Rect pA,SDL_Rect pB)
{
  int i;
  if  ((pA.y + iA->h) < pB.y ) i = 0;
    else if ( pA.y > (pB.y + iB->h)) i = 0;
    else if ( (pA.x + iA->w) < pB.x ) i = 0;
    else if ( pA.x > (pB.x +  iB->w)) i = 0;
    else i=1;
return i;
}*/

SDL_Color GetPixel(SDL_Surface *surface,int x,int y)
{
	SDL_Color color ;
	Uint32 col = 0 ;

	//determine position
	char* pPosition = ( char* ) surface->pixels ;

	//offset by y
	pPosition += ( surface->pitch * y ) ;

	//offset by x
	pPosition += ( surface->format->BytesPerPixel * x ) ;

	//copy pixel data
	memcpy ( &col , pPosition , surface->format->BytesPerPixel ) ;

	//convert color
	SDL_GetRGB ( col , surface->format , &color.r , &color.g , &color.b ) ;

	return ( color ) ;

}

int collision_Parfaite(game g,int d)
{
  SDL_Color col;

if(d==0)//imin
  {
if (g.B.numbg==0)
col=GetPixel(g.B.img_bg_collide[g.B.numbg],g.P.REALPOS.x,g.P.REALPOS.y);
else
col=GetPixel(g.B.img_bg_collide[g.B.numbg],g.P.POS.x+47,g.P.POS.y);
  }
  else  if(d==1)//issarr
  {

if (g.B.numbg==0)
col=GetPixel(g.B.img_bg_collide[g.B.numbg],g.P.REALPOS.x,g.P.REALPOS.y);
else
col=GetPixel(g.B.img_bg_collide[g.B.numbg],g.P.POS.x,g.P.POS.y+52);

  }
else  if(d==2)//lfou9
  {

if (g.B.numbg==0)

col=GetPixel(g.B.img_bg_collide[g.B.numbg],g.P.REALPOS.x,g.P.REALPOS.y);
else
col=GetPixel(g.B.img_bg_collide[g.B.numbg],g.P.POS.x+(37),g.P.POS.y);

  }
else  if(d==3)//louta
  {
if (g.B.numbg==0)
col=GetPixel(g.B.img_bg_collide[g.B.numbg],g.P.REALPOS.x,g.P.REALPOS.y);
else
col=GetPixel(g.B.img_bg_collide[g.B.numbg],g.P.POS.x+(37),g.P.POS.y+62);

  }
fprintf (stderr,"\nmap %d \n r =%d g =%d b =%d \n",g.B.numbg,col.r,col.g,col.b);

//fprintf(stderr,"\n r=%d g=%d b=%d \n",col.r,col.g,col.b);

if ((col.r==0)&&(col.b==0)&&(col.g==0))
{
  return 0;
}
else if ((col.r==0)&&(col.b==0)&&(col.g==255))//trja3 lel map
{
return 4;
}
else if ((col.r==254)&&(col.b==0)&&(col.g==0)) //tod5ol fi stage
{
return 2;
}
else if ((col.r==0)&&(col.b==254)&&(col.g==0)) // tetla3 enigme
{
return 3;
}
else
 return 1;
}


