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
	uint16_t c2 = rgb_2_565(19, 32, 190);
	uint16_t c3 = rgb_2_565(179, 180, 175);
	uint16_t c4 = rgb_2_565(179, 180, 175);

 	clut_set(0, c1);  
 	clut_set(1, c2);
 	clut_set(2, c3);
    clut_set(3, c4);

    clut_set(15, 0x00);	// Black Background
	loadAllSprites();
	
	uint8_t x_trans = 0;
	uint8_t y_trans = 0;
	uint16_t time = 0;

	char buf[255];
	char greets[] = "                                                GREETS TO CHARLIEX ~ COINE ~ DATAGRAM ~ FSPHIL ~ HOTDOGS ~ JAMIS ~ JBUM ~ JKING ~ MMCA ~ MR1337357                                                                        ";
    
    uint8_t flipper = 0;

    uint8_t mod_value = 5;

    // Draw
	while (1) 
	{
		#ifdef DOUBLE_BUFFERED
			swapBuffers();  // Before drawing the next frame, we must swap buffers
		#endif

		// DRAW FRAME
        //----------------------------------------------------------------------
		if(frames < 500)					// Fake loading screen
		{
			rcc_color(2);
			rcc_draw(60, 200, 200, 40);

			rcc_color(0);
			rcc_draw(62, 204, 196, 32);

			rcc_color(2);
			rcc_draw(64, 208, (uint8_t)(frames*0.2), 24);

			rcc_color(0);
		}
		else if(frames < 680)				// Fake loading screen
		{
			rcc_color(2);
			rcc_draw(60, 200, 200, 40);

			rcc_color(0);
			rcc_draw(62, 204, 196, 32);

			rcc_color(2);
			rcc_draw(64, 208, 150 - (uint8_t)(frames*0.1), 24);

			rcc_color(0);
		}
		else if(frames < 1380)		// BSOD - lol
		{
			rcc_color(1);
			rcc_draw(1, 0, HOR_RES-3, VER_RES-1);

			rcc_color(2);
			rcc_draw(HOR_RES/2 - 30, 100, 60, 20);

			chr_fg_color(2);
			chr_bg_color(3);
			sprintf(buf, "A fatal excepetion 0x24D has occurred at 00FC");
			chr_print(buf,20,150,1);
			sprintf(buf, " 	* Current application will be terminated.");
			chr_print(buf,20,190,1);
			sprintf(buf, " 	* ERROR: CPU refused to load shit demo.");
			chr_print(buf,20,210,1);
			sprintf(buf, " 	* Press any key or just give up already.");
			chr_print(buf,20,230,1);
			sprintf(buf, " 	* Press CTRL + ALT + DEL for fun!");
			chr_print(buf,20,250,1);

			sprintf(buf, "*** SHITDEMO.EXE -  Address 0x49DAFUK");
			chr_print(buf,20,300,1);

	        sprintf(buf, "Press any key to continue...");
			chr_print(buf,HOR_RES/2 - 80,400,1);

			chr_fg_color(1);
			chr_bg_color(2);
			sprintf(buf, "WINDOWS");
			chr_print(buf,HOR_RES/2 - 20,105,1);
		}
		else if(frames < 1440)
		{
			if(flipper == 0)
			{
				loadSpriteCLUT(1);
				flipper++;
			}
			else if(flipper == 1)
			{
				blank_background();
				flipper++;
			}
			else
			{
				drawSprite(58, 83, 1, 0, 1);
				flipper++;
			}
		}
		else if(frames < 1500)
		{
			flipper = 0;
		}
		else if(frames < 2000)
		{
			if(flipper == 0)
			{
				loadSpriteCLUT(0);
				flipper++;
			}
			else if(flipper == 1)
			{
				blank_background();
				flipper++;
			}
			else
			{
				drawSprite(120,220, 0, 0, 0);
				sprintf(buf, "HOPE YOU ENJOYED THAT INTRO SCREEN...");
				chr_print(buf,50,150,1);
				sprintf(buf, "... CUZ WE'RE OUT OF PROGRAM MEMORY!");
				chr_print(buf,50,180,1);

				sprintf(buf, "...OK ...ALMOST.");
				chr_print(buf,50,280,1);
			}
		}
		else if(frames < 2600)
		{
			drawSprite(rand()%280 ,rand()%445, 0, 0, 0);
		}
		else if(frames < 2606)
		{
			blank_background();

			uint8_t clut_idx = 0;
			for(clut_idx=0; clut_idx<15; clut_idx++)
			{
				clut_set(clut_idx, rgb_2_565(clut_idx*(255/15),0,0));
			}
			clut_set(14, rgb_2_565(255,255,255));
		}
		else if(frames < 3200)
		{
			static uint16_t lfsr_a = 0;
			static uint16_t lfsr_b = 45;

			line(100,200,cos((lfsr_a%360)*3.14f/180)*310,sin((lfsr_b%360)*3.14f/180)*310, lfsr_a%16); 
			
			lfsr_a++;
			lfsr_b++;

			drawSprite(200,130, 2, 0, 0);

			chr_fg_color(14);
			sprintf(buf, "Loading Eagle PCB...");
			chr_print(buf,100,350,1);
		}
		else if(frames < 3201)
		{
			blank_background();

			uint8_t clut_idx = 0;
			for(clut_idx=0; clut_idx<15; clut_idx++)
			{
				clut_set(clut_idx, rgb_2_565(0,clut_idx*(127/15),0));
			}

			uint8_t n = 0;
			uint8_t color = 0;
			for(n=0; n<mod_value; n++)
			{
				color = n*255/(mod_value-1);
				clut_set(n, rgb_2_565(color,color,color));
			}

			mod_value = mod_value + 5;
		}
		else if(frames < 3230)
		{
			uint16_t y = 1;
			uint16_t x = 1;
			for(y=1; y < VER_RES-1; y++)
			{
				for(x=1; x < HOR_RES-1; x++)
				{
					rcc_color((x^y) % mod_value);
					fast_pixel(x,y);
				}
			}

			mod_value++;
		}
		else if(frames < 3236)
		{
			blank_background();
			clut_set(14, rgb_2_565(255,255,255));
			// PS crt mode and rgb text
		}
		else if(frames < 3600)
		{
			rcc_color(14);
			chr_fg_color(14);
			sprintf(buf, "OK... THAT WASN'T EAGLE PCB:");
			chr_print(buf,100,240,1);
			sprintf(buf, "JUST SOME MATH:");
			chr_print(buf,100,290,1);
			sprintf(buf, "color = (x^y) mod count;");
			chr_print(buf,100,330,1);
			sprintf(buf, "count++;");
			chr_print(buf,100,350,1);
		}
		else if(frames < 3606)
		{
			blank_background();

			clut_set(0, rgb_2_565(0,0,0));
			clut_set(1, rgb_2_565(0,0,255));
			clut_set(2, rgb_2_565(0,255,0));
			clut_set(3, rgb_2_565(255,0,0));
			clut_set(4, rgb_2_565(120,120,120));
			clut_set(5, rgb_2_565(255,255,255));

			uint16_t l = 4;
			for(l = 4; l < VER_RES-4; l=l+4)
			{
				rcc_color(4);
				rcc_draw(4, l, HOR_RES-4, 1);
			}

			rcc_color(0);
			rcc_draw(110, 100, 100, 140);
		}
		else if(frames < 40006)
		{
			static uint16_t wav_idx = 208;
			uint16_t tempb = PORTB;
			
			line(wav_idx, 180, wav_idx, 180-(tempb>>11), 5);
			line(wav_idx, 179, wav_idx, 179+(tempb>>11), 5);

			if(wav_idx>110)
			{
				wav_idx--;
			}
			else
			{
				wav_idx = 208;
				rcc_color(0);
				rcc_draw(110, 100, 100, 140);
			}

			
			static uint16_t ly = 290;
			uint16_t l = 4;
			for(l = ly; l < ly+180; l++)
			{
				if(l%4 == 0)
				{
					rcc_color(4);
					rcc_draw(4, l, HOR_RES-4, 1);
				}
				else
				{
					rcc_color(0);
					rcc_draw(4, l, HOR_RES-4, 1);
				}
			}
			
			
			static uint8_t i = 1;
			static uint8_t s = 0;
			for(i = 1; i < 64; i++)
			{
				buf[0] = greets[i+s];
  				buf[1] = '\0';

  				chr_fg_color(1);
				chr_print(buf,i*6,(sinetable_small[(uint8_t)(y_trans+(i*2))]>>9)+10+290,1);
				chr_fg_color(2);
				chr_print(buf,i*6+5,(sinetable_small[(uint8_t)(y_trans+(i*2))]>>9)+10+300,1);
				chr_fg_color(3);
				chr_print(buf,i*6+10,(sinetable_small[(uint8_t)(y_trans+(i*2))]>>9)+10+310,1);
			}
			
			y_trans++; 

			if(frames%20 == 0)
			{
				s++;
			}
			
			if(s > 150)
			{
				s = 0;
				i = 1;
				y_trans=0;
			}

			rcc_color(0);
			rcc_draw(0, 0, 4, VER_RES-1);
			rcc_draw(316, 0, 4, VER_RES-1);
			
			drawSprite(140,101, 3, 0, 0);
		}
		else if(frames < 42100)
		{
			sprintf(buf, "FIN");
			chr_print(buf,150,200,1);
		}

		drawBorder(15);
        //----------------------------------------------------------------------
		cleanup();              // Housekeeping for VGA signaling
		waitForBufferFlip();    // For next vsync
		frames++;               // Increment frame count
	}

	return 0;
}
