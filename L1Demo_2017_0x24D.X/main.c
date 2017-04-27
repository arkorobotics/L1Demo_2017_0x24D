/*
 Event>>  			Layerone Demo Party 2017
 Title>>  			NO TITLE YET
 Group>>			0x24D
 By>>     			Arko & Davo
 Base Libraries>>	Datagram & Hotdogs & Jamis
 ---------------------------------------------------------
 Warning>>			Don't take any of this code seriously
 Danger>>			We're super cereal
 ---------------------------------------------------------
 [ INSERT ASCII ART HERE ]
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <string.h>
#include <math.h>
#include "gpu.h"
#include "audio.h"
#include "color.h"
#include "music.h"
#include "sprites.h"
 
#define  FCY    16000000UL    // Instruction cycle frequency, Hz
#include <libpic30.h>
 
#pragma config FWDTEN = OFF , GWRP = OFF , GCP = OFF , JTAGEN = OFF
#pragma config POSCMOD = HS , FCKSM = CSDCMD , FNOSC = PRIPLL , PLL96MHZ = ON , PLLDIV = DIV2
#pragma config ALTPMP = ALTPMPEN , SOSCSEL = EC

int main(void) 
{
    // Configuation
	ANSB = 0x0000;
	ANSC = 0x0000;
	ANSD = 0x0000;
	ANSF = 0x0000;
	ANSG = 0x0000;
	TRISB = 0x0000;

	_VMRGNIF = 0;
	_VMRGNIE = 1;
	_GFX1IE = 1;

	config_graphics();
	config_clut();
	config_chr();
	config_timer();
	clearbuffers();
 	
 	uint16_t c1 = 0;
	uint16_t c2 = rgb_2_565(1, 3, 240);
	uint16_t c3 = rgb_2_565(179, 180, 175);
	uint16_t c4 = rgb_2_565(179, 180, 175);

 	clut_set(0, c1);  
 	clut_set(1, c2);
 	clut_set(2, c3);
    clut_set(3, c4);

	loadAllSprites();
	
	uint8_t x_trans = 0;
	uint8_t y_trans = 20;
	uint16_t time = 0;

	char buf[255];
	char greets[] = "GREETS TO CHARLIEX ~ COINE ~ DATAGRAM ~ FSPHIL ~ HOTDOGS ~ JKING ~ JAMIS ~ MMCA ~ MR1337357";
    
    // Draw
	while (1) 
	{
		swapBuffers();  // Before drawing the next frame, we must swap buffers
		
		// DRAW FRAME
        //----------------------------------------------------------------------
		if(frames < 60*5)					// Fake loading screen
		{
			rcc_color(2);
			rcc_draw(60, 200, 200, 40);

			rcc_color(0);
			rcc_draw(62, 204, 196, 32);

			rcc_color(2);
			rcc_draw(64, 208, (uint8_t)(frames*0.5), 24);

			rcc_color(0);
		}
		else if(frames < 60*8)				// Fake loading screen
		{
			rcc_color(2);
			rcc_draw(60, 200, 200, 40);

			rcc_color(0);
			rcc_draw(62, 204, 196, 32);

			rcc_color(2);
			rcc_draw(64, 208, 150 - (uint8_t)(frames*0.1), 24);

			rcc_color(0);
		}
		else if(frames < 60*(5+8+10))		// BSOD - lol
		{
			rcc_color(1);
			rcc_draw(0, 0, HOR_RES-1, VER_RES-1);

			rcc_color(2);
			rcc_draw(HOR_RES/2 - 30, 100, 60, 20);



			chr_fg_color(2);
			chr_bg_color(3);
			sprintf(buf, "A fatal excepetion 0x24D has occurred at 00FC");
			chr_print(buf,20,150,1);
			sprintf(buf, " 	* Current application will be terminated.");
			chr_print(buf,20,190,1);
			sprintf(buf, " 	* ERROR: CPU refused to open shit demos.");
			chr_print(buf,20,210,1);
			sprintf(buf, " 	* Press any key or just give up already.");
			chr_print(buf,20,230,1);
			sprintf(buf, " 	* Press CTRL + ALT + DEL for fun!");
			chr_print(buf,20,250,1);

			sprintf(buf, "*** SHITDEMO.EXE -  Address 0x49DUCFA");
			chr_print(buf,20,300,1);

	        sprintf(buf, "Press any key to continue...");
			chr_print(buf,HOR_RES/2 - 80,400,1);

			chr_fg_color(1);
			chr_bg_color(2);
			sprintf(buf, "WINDOWS");
			chr_print(buf,HOR_RES/2 - 20,105,1);
		}
		
		drawBorder(0);
        //----------------------------------------------------------------------
        
		//drawBorder(0x92);       // Draw border around demo
		cleanup();              // Housekeeping for VGA signaling
		waitForBufferFlip();    // For next vsync
		frames++;               // Increment frame count
	}

	return 0;
}
