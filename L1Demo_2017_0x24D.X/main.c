/*
 Event>>  			Layerone Demo Party 2017
 Title>>  			NO TITLE YET
 Group>>			0x24D
 By>>     			Arko & Davo
 Base Libraries>>	Datagram & Hotdogs & Jamis
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
 	
 	uint16_t c1 = 0x0000;
	uint16_t c2 = 0x0FF0;
	uint16_t c3 = 0xF00F;
	uint16_t c4 = 0xFFFF;

 	clut_set(0, c1);  
 	clut_set(1, c2);
 	clut_set(2, c3);
    clut_set(3, c4);

    // Load and Initialize
    /*
    int d;
	for(d = 0; d < MAX_PARTICLES; d++)
		addParticle();
    */

	loadAllSprites();
	
	uint8_t x_trans = 0;
	uint8_t y_trans = 20;
	uint16_t time = 0;

	char buf[255];
	char greets[] = "          GREETS TO CHARLIEX ~ COINE ~ DATAGRAM ~ FSPHIL ~ JKING ~ JAMIS ~ MMCA ~ MR1337357               ";
    // Draw
	while (1) 
	{
		swapBuffers();  // Before drawing the next frame, we must swap buffers
		
		// DRAW FRAME
        //----------------------------------------------------------------------
		
		int x,y = 0;
		time = 0;

		for(y = 0; y < 470; y++)
		{
			y=y+10;
	        for(x = 2; x < 318; x++)
	        {
	        	x=x+10;
	            rcc_color(x+y);
	            fast_pixel(x,y);
	            if(time < 4)
	            {
	            	time++;
	            }
	            else
	            {
	            	time = 0;
	            }
	        }
	    }
		
		rcc_color(255);
		fast_pixel(318,240);

	    sprintf(buf, "ONE");
		chr_print(buf,0,0);

		sprintf(buf, "TWO");
		chr_print(buf,0,10);

		sprintf(buf, "THREE");
		chr_print(buf,0,20);

		sprintf(buf, "FOUR");
		chr_print(buf,0,30);

		sprintf(buf, "FIVE");
		chr_print(buf,0,40);

		sprintf(buf, "LAST");
		chr_print(buf,0,470);
        //----------------------------------------------------------------------
        
		//drawBorder(0x92);       // Draw border around demo
		cleanup();              // Housekeeping for VGA signaling
		waitForBufferFlip();    // For next vsync
		frames++;               // Increment frame count
	}

	return 0;
}
