/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLUE);

  //drawString5x7(20,20, "hello", COLOR_GREEN, COLOR_RED);

  // fillRectangle(30,30, 60, 60, COLOR_ORANGE);
  createDiamond();
  createStar();
  }
  void createDiamond(){
     int fcol=screenWidth/2-20, frow=screenHeight/2;
     for(int i=0; i <20;i++){
        for(int j=0; j <i;j++){
	  drawPixel(fcol+i,frow+j,COLOR_BLACK);
	  drawPixel(fcol+i,frow-j,COLOR_BLACK);
	  drawPixel(fcol-i+39,frow+j,COLOR_BLACK);
	  drawPixel(fcol-i+39,frow-j,COLOR_BLACK);
	}
     }
  }
void createStar(){
  int fcol=20, frow=20;
  for(int i=0; i<20; i++){
    drawPixel(fcol+i,frow+i,COLOR_BLACK); // ** \ **bottom right
    drawPixel(fcol+i,frow-i,COLOR_BLACK); // ** / ** top right 
    drawPixel(fcol+i,frow,COLOR_BLACK);  // ** -- ** right side
    drawPixel(fcol,frow-i,COLOR_BLACK); // ** | **top center
    drawPixel(fcol-i,frow,COLOR_BLACK); // **--**left center
    drawPixel(fcol-i,frow-i,COLOR_BLACK); //  **\ **top left
    drawPixel(fcol-i,frow+i,COLOR_BLACK); // ** / **bottom left
    drawPixel(fcol,frow+i,COLOR_BLACK); // ** | ** bottom center
  }
}
