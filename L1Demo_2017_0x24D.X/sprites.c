#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <string.h>
#include <math.h>
#include "gpu.h"
#include "sprites.h"


struct Sprite s[MAX_SPRITES];

__eds__ struct Particle p[MAX_PARTICLES];

uint16_t color_array[8] = {0,0,0,0,0,0,0,0};

__prog__ uint16_t SpriteMap[] __attribute__((space(prog)))= {
// Sonic 40 x 51
0x0028,
0x0033,
0x0010,
0x07e0,
0x0000,
0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x6b56,0x6b56,0x6b56,0x6b56,0x6b56,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x6b56,0xb5ba,0xb5ba,0x6b56,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0xb5ba,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0xb5ba,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x6b56,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x6b56,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0xed71,0xed71,0x1973,0x1973,0x6b56,0x1973,0x1973,0x1973,0x1973,0x1973,0x7e0,0xb5ba,0x1973,0x1973,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0xb5ba,0xb5ba,0x1973,0x1973,0x1973,0x1973,0x1973,0x6b56,0xed71,0xed71,0x6b56,0x1973,0x6b56,0x6b56,0x6b56,0x6b56,0x1973,0x1973,0x6b56,0x1973,0x1973,0x1973,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x1973,0x1973,0x1973,0xed71,0xed71,0xed71,0xed71,0x6b56,0x1973,0x6b56,0x6b56,0x6b56,0x6b56,0x1973,0x1973,0x1973,0x1973,0x1973,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x6b56,0x1973,0x1973,0x1973,0xed71,0xed71,0xed71,0xed71,0xed71,0x1973,0x6b56,0x6b56,0x6b56,0x6b56,0x6b56,0x1973,0x1973,0x1973,0x1973,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x1973,0x1973,0x1973,0x1973,0x1973,0xed71,0xed71,0x6b56,0x1973,0x1973,0x6b56,0x6b56,0x6b56,0x6b56,0x6b56,0x6b56,0x6b56,0x1973,0x1973,0x1973,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x6b56,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x6b56,0x6b56,0x6b56,0xb5ba,0xb5ba,0x6b56,0x6b56,0x1973,0x1973,0x1973,0x1973,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x6b56,0x6b56,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x6b56,0x6b56,0x6b56,0x1973,0x6b56,0x6b56,0x6b56,0x6b56,0x1973,0x1973,0x1973,0x1973,0x1973,0x6b56,0x6b56,0x6b56,0x1973,0x1973,0x6b56,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x6b56,0x1973,0x1973,0x1973,0x1973,0x1973,0x6b56,0x1973,0x1973,0x1973,0x6b56,0x6b56,0xb5ba,0xb5ba,0x6b56,0x6b56,0x1973,0x1973,0x1973,0x6b56,0x6b56,0x6b56,0x6b56,0x6b56,0x1973,0x1973,0x1973,0x1973,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x6b56,0x1973,0x1973,0x1973,0x1973,0x6b56,0x1973,0x1973,0x1973,0x6b56,0x1973,0x1973,0x6b56,0xffff,0x6b56,0x1973,0x1973,0x1973,0x1973,0xb5ba,0xffff,0xffff,0xffff,0x6b56,0x1973,0x1973,0x1973,0x1973,0x6b56,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x6b56,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x6b56,0x6b56,0x1973,0x1973,0x1973,0xb5ba,0xffff,0xffff,0xffff,0xffff,0xffff,0x1973,0x1973,0x1973,0x6b56,0x6b56,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0xb5ba,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x1973,0x1973,0x1973,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0x6b56,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x6b56,0x1973,0x1973,0x1973,0x1973,0x1973,0xb5ba,0xffff,0xffff,0xffff,0xffff,0xffff,0x10a2,0x6b56,0x6b56,0x1973,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0xb5ba,0xb5ba,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x6b56,0x1973,0x1973,0x1973,0x6b56,0xb5ba,0xffff,0xffff,0xffff,0xffff,0x10a2,0x10a2,0x6b56,0x10a2,0x6b56,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x6b56,0x6b56,0x6b56,0xb5ba,0xffff,0xffff,0xffff,0xffff,0x10a2,0x6b56,0x6b56,0xed71,0x1973,0x6b56,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0xb5ba,0xed71,0xed71,0xed71,0xed71,0xb5ba,0xed71,0xffff,0xffff,0xffff,0xed71,0xed71,0xb5ba,0x10a2,0x10a2,0x6b56,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x1973,0x1973,0x6b56,0x1973,0x1973,0x1973,0x1973,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xb5ba,0xb5ba,0xed71,0xed71,0xed71,0x10a2,0x10a2,0x10a2,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0x10a2,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x1973,0x1973,0x1973,0x6b56,0x1973,0x6b56,0x6b56,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x1973,0x1973,0x6b56,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0xed71,0x6b56,0xed71,0xed71,0xed71,0xed71,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x6b56,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x6b56,0x1973,0x1973,0x1973,0xed71,0xed71,0xed71,0xed71,0x1973,0x1973,0x1973,0xed71,0xb5ba,0xb5ba,0xed71,0x7e0,0x7e0,0xb5ba,0xb5ba,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x1973,0x1973,0xed71,0xed71,0xed71,0xed71,0x1973,0x1973,0x1973,0xed71,0xed71,0xed71,0xffff,0xed71,0x6b56,0xb5ba,0xffff,0xb5ba,0xb5ba,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x1973,0x1973,0x1973,0xed71,0xed71,0xed71,0xed71,0x6b56,0x1973,0x6b56,0xed71,0xed71,0xed71,0xffff,0xffff,0xffff,0x6b56,0x6b56,0xffff,0xffff,0xb5ba,0xb5ba,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x1973,0xb5ba,0xed71,0xed71,0x6b56,0xb5ba,0xb5ba,0xffff,0xffff,0xffff,0xed71,0xed71,0xed71,0xed71,0xffff,0xed71,0x6b56,0x6b56,0xb5ba,0x6b56,0x6b56,0xb5ba,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x6b56,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0xffff,0xffff,0xb5ba,0xed71,0xed71,0xed71,0xed71,0xed71,0x6b56,0x6b56,0xb5ba,0x6b56,0xb5ba,0xb5ba,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x6b56,0x1973,0x6b56,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0xffff,0xb5ba,0xffff,0xb5ba,0xed71,0xed71,0xed71,0x1973,0x1973,0x6b56,0x6b56,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x6b56,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0x6b56,0x6b56,0x6b56,0xb5ba,0x6b56,0x6b56,0x6b56,0xb5ba,0x6b56,0x6b56,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x6b56,0x1973,0x6b56,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0x6b56,0x6b56,0x6b56,0x1973,0x1973,0x7e0,0x6b56,0x6b56,0x6b56,0x6b56,0x6b56,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x6b56,0x6b56,0x6b56,0xb5ba,0xb5ba,0xb5ba,0x6b56,0x6b56,0x6b56,0x1973,0x1973,0x1973,0x7e0,0x7e0,0x6b56,0x1973,0x6b56,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x6b56,0x6b56,0x6b56,0x6b56,0x6b56,0x1973,0xffff,0xb5ba,0x1973,0x1973,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x6b56,0x6b56,0x6b56,0x6b56,0x1973,0x6b56,0xffff,0x6b56,0x1973,0x1973,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x1973,0x1973,0x1973,0x6b56,0xb5ba,0xffff,0xffff,0x6b56,0x1973,0x1973,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x1973,0x1973,0x6b56,0xffff,0xffff,0xffff,0x1973,0x1973,0x1973,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x6b56,0xb5ba,0x1973,0x1973,0x6b56,0xffff,0xffff,0xb5ba,0x6b56,0x1973,0x1973,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x6b56,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0x6b56,0x6b56,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x6b56,0x6b56,0xb5ba,0xb5ba,0xb5ba,0x6b56,0x6b56,0x6b56,0xb5ba,0xb5ba,0xb5ba,0x6b56,0x6b56,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0xc0a2,0x6b56,0xb5ba,0xb5ba,0xc0a2,0x1973,0xc0a2,0xc0a2,0xc0a2,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x6b56,0x10a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0x6b56,0x10a2,0x6b56,0x6b56,0x6b56,0x10a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xb5ba,0xb5ba,0xc0a2,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x10a2,0x10a2,0xc0a2,0xb5ba,0xffff,0xffff,0xffff,0xffff,0xffff,0xc0a2,0xc0a2,0xc0a2,0x10a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xb5ba,0xb5ba,0xb5ba,0xc0a2,0xc0a2,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x10a2,0xc0a2,0xb5ba,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xffff,0xc0a2,0x10a2,0xc0a2,0xc0a2,0xc0a2,0x6b56,0xb5ba,0xb5ba,0xb5ba,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x10a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xb5ba,0xc0a2,0xc0a2,0xc0a2,0x10a2,0xc0a2,0xc0a2,0xc0a2,0x6b56,0xb5ba,0xb5ba,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xb5ba,0xc0a2,0xc0a2,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x10a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0x10a2,0xc0a2,0xc0a2,0x6b56,0x6b56,0x6b56,0xb5ba,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x10a2,0x10a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0x10a2,0x10a2,0xc0a2,0xc0a2,0x6b56,0x6b56,0x6b56,0x6b56,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,

// Sonic 40 x 51
0x0028,
0x0033,
0x0010,
0x07e0,
0x0000,
0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x6b56,0x6b56,0x6b56,0x6b56,0x6b56,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x6b56,0xb5ba,0xb5ba,0x6b56,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0xb5ba,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0xb5ba,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x6b56,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x6b56,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0xed71,0xed71,0x1973,0x1973,0x6b56,0x1973,0x1973,0x1973,0x1973,0x1973,0x7e0,0xb5ba,0x1973,0x1973,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0xb5ba,0xb5ba,0x1973,0x1973,0x1973,0x1973,0x1973,0x6b56,0xed71,0xed71,0x6b56,0x1973,0x6b56,0x6b56,0x6b56,0x6b56,0x1973,0x1973,0x6b56,0x1973,0x1973,0x1973,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x1973,0x1973,0x1973,0xed71,0xed71,0xed71,0xed71,0x6b56,0x1973,0x6b56,0x6b56,0x6b56,0x6b56,0x1973,0x1973,0x1973,0x1973,0x1973,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x6b56,0x1973,0x1973,0x1973,0xed71,0xed71,0xed71,0xed71,0xed71,0x1973,0x6b56,0x6b56,0x6b56,0x6b56,0x6b56,0x1973,0x1973,0x1973,0x1973,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x1973,0x1973,0x1973,0x1973,0x1973,0xed71,0xed71,0x6b56,0x1973,0x1973,0x6b56,0x6b56,0x6b56,0x6b56,0x6b56,0x6b56,0x6b56,0x1973,0x1973,0x1973,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x6b56,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x6b56,0x6b56,0x6b56,0xb5ba,0xb5ba,0x6b56,0x6b56,0x1973,0x1973,0x1973,0x1973,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x6b56,0x6b56,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x6b56,0x6b56,0x6b56,0x1973,0x6b56,0x6b56,0x6b56,0x6b56,0x1973,0x1973,0x1973,0x1973,0x1973,0x6b56,0x6b56,0x6b56,0x1973,0x1973,0x6b56,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x6b56,0x1973,0x1973,0x1973,0x1973,0x1973,0x6b56,0x1973,0x1973,0x1973,0x6b56,0x6b56,0xb5ba,0xb5ba,0x6b56,0x6b56,0x1973,0x1973,0x1973,0x6b56,0x6b56,0x6b56,0x6b56,0x6b56,0x1973,0x1973,0x1973,0x1973,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x6b56,0x1973,0x1973,0x1973,0x1973,0x6b56,0x1973,0x1973,0x1973,0x6b56,0x1973,0x1973,0x6b56,0xffff,0x6b56,0x1973,0x1973,0x1973,0x1973,0xb5ba,0xffff,0xffff,0xffff,0x6b56,0x1973,0x1973,0x1973,0x1973,0x6b56,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x6b56,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x6b56,0x6b56,0x1973,0x1973,0x1973,0xb5ba,0xffff,0xffff,0xffff,0xffff,0xffff,0x1973,0x1973,0x1973,0x6b56,0x6b56,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0xb5ba,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x1973,0x1973,0x1973,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0x6b56,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x6b56,0x1973,0x1973,0x1973,0x1973,0x1973,0xb5ba,0xffff,0xffff,0xffff,0xffff,0xffff,0x10a2,0x6b56,0x6b56,0x1973,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0xb5ba,0xb5ba,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x6b56,0x1973,0x1973,0x1973,0x6b56,0xb5ba,0xffff,0xffff,0xffff,0xffff,0x10a2,0x10a2,0x6b56,0x10a2,0x6b56,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x6b56,0x6b56,0x6b56,0xb5ba,0xffff,0xffff,0xffff,0xffff,0x10a2,0x6b56,0x6b56,0xed71,0x1973,0x6b56,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0xb5ba,0xed71,0xed71,0xed71,0xed71,0xb5ba,0xed71,0xffff,0xffff,0xffff,0xed71,0xed71,0xb5ba,0x10a2,0x10a2,0x6b56,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x1973,0x1973,0x6b56,0x1973,0x1973,0x1973,0x1973,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xb5ba,0xb5ba,0xed71,0xed71,0xed71,0x10a2,0x10a2,0x10a2,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0x10a2,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x1973,0x1973,0x1973,0x6b56,0x1973,0x6b56,0x6b56,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0xed71,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x1973,0x1973,0x6b56,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0xed71,0x6b56,0xed71,0xed71,0xed71,0xed71,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x6b56,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x1973,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x6b56,0x1973,0x1973,0x1973,0xed71,0xed71,0xed71,0xed71,0x1973,0x1973,0x1973,0xed71,0xb5ba,0xb5ba,0xed71,0x7e0,0x7e0,0xb5ba,0xb5ba,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x1973,0x1973,0xed71,0xed71,0xed71,0xed71,0x1973,0x1973,0x1973,0xed71,0xed71,0xed71,0xffff,0xed71,0x6b56,0xb5ba,0xffff,0xb5ba,0xb5ba,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x1973,0x1973,0x1973,0xed71,0xed71,0xed71,0xed71,0x6b56,0x1973,0x6b56,0xed71,0xed71,0xed71,0xffff,0xffff,0xffff,0x6b56,0x6b56,0xffff,0xffff,0xb5ba,0xb5ba,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x1973,0xb5ba,0xed71,0xed71,0x6b56,0xb5ba,0xb5ba,0xffff,0xffff,0xffff,0xed71,0xed71,0xed71,0xed71,0xffff,0xed71,0x6b56,0x6b56,0xb5ba,0x6b56,0x6b56,0xb5ba,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x6b56,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0xffff,0xffff,0xb5ba,0xed71,0xed71,0xed71,0xed71,0xed71,0x6b56,0x6b56,0xb5ba,0x6b56,0xb5ba,0xb5ba,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x6b56,0x1973,0x6b56,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0xffff,0xb5ba,0xffff,0xb5ba,0xed71,0xed71,0xed71,0x1973,0x1973,0x6b56,0x6b56,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x6b56,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0x6b56,0x6b56,0x6b56,0xb5ba,0x6b56,0x6b56,0x6b56,0xb5ba,0x6b56,0x6b56,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x6b56,0x1973,0x6b56,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0x6b56,0x6b56,0x6b56,0x1973,0x1973,0x7e0,0x6b56,0x6b56,0x6b56,0x6b56,0x6b56,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x6b56,0x6b56,0x6b56,0xb5ba,0xb5ba,0xb5ba,0x6b56,0x6b56,0x6b56,0x1973,0x1973,0x1973,0x7e0,0x7e0,0x6b56,0x1973,0x6b56,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x6b56,0x6b56,0x6b56,0x6b56,0x6b56,0x1973,0xffff,0xb5ba,0x1973,0x1973,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x6b56,0x6b56,0x6b56,0x6b56,0x1973,0x6b56,0xffff,0x6b56,0x1973,0x1973,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x1973,0x1973,0x1973,0x6b56,0xb5ba,0xffff,0xffff,0x6b56,0x1973,0x1973,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x1973,0x1973,0x6b56,0xffff,0xffff,0xffff,0x1973,0x1973,0x1973,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x6b56,0xb5ba,0x1973,0x1973,0x6b56,0xffff,0xffff,0xb5ba,0x6b56,0x1973,0x1973,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x6b56,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0x6b56,0x6b56,0xb5ba,0xb5ba,0xb5ba,0xb5ba,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x1973,0x6b56,0x6b56,0xb5ba,0xb5ba,0xb5ba,0x6b56,0x6b56,0x6b56,0xb5ba,0xb5ba,0xb5ba,0x6b56,0x6b56,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0xb5ba,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0xc0a2,0x6b56,0xb5ba,0xb5ba,0xc0a2,0x1973,0xc0a2,0xc0a2,0xc0a2,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x6b56,0x10a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0x6b56,0x10a2,0x6b56,0x6b56,0x6b56,0x10a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xb5ba,0xb5ba,0xc0a2,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x10a2,0x10a2,0xc0a2,0xb5ba,0xffff,0xffff,0xffff,0xffff,0xffff,0xc0a2,0xc0a2,0xc0a2,0x10a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xb5ba,0xb5ba,0xb5ba,0xc0a2,0xc0a2,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x10a2,0xc0a2,0xb5ba,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xffff,0xc0a2,0x10a2,0xc0a2,0xc0a2,0xc0a2,0x6b56,0xb5ba,0xb5ba,0xb5ba,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x10a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xb5ba,0xc0a2,0xc0a2,0xc0a2,0x10a2,0xc0a2,0xc0a2,0xc0a2,0x6b56,0xb5ba,0xb5ba,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xb5ba,0xc0a2,0xc0a2,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x10a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0x10a2,0xc0a2,0xc0a2,0x6b56,0x6b56,0x6b56,0xb5ba,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x10a2,0x10a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0x10a2,0x10a2,0xc0a2,0xc0a2,0x6b56,0x6b56,0x6b56,0x6b56,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0xc0a2,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0,0x7e0

};

/* Sprites */
void loadAllSprites(void) 
{
	uint16_t id, off;
	off = 0;

	for (id=0; id < MAX_SPRITES; id++) 
	{
		s[id].width  =  SpriteMap[off + SPR_OFF_WIDTH];
		s[id].height =  SpriteMap[off + SPR_OFF_HEIGHT];
		s[id].bitres =  SpriteMap[off + SPR_OFF_BITRES];
		s[id].trans  =  SpriteMap[off + SPR_OFF_TRANS];
		s[id].rotate =  SpriteMap[off + SPR_OFF_ROTATE];
		s[id].data   = &SpriteMap[off + SPR_OFF_DATA];

		off += s[id].width * s[id].height + SPR_HEAD;
	}
}
 
void inline loadSpriteCLUT(uint16_t id)
{
	unsigned int w,h,c;
	uint16_t color;
	uint8_t new_color_idx = 0;

	for (h=0; h < s[id].height; h++) 
	{
		for (w=0; w < s[id].width; w++) 
		{
			color = s[id].data[w + s[id].width*h];

			if(new_color_idx == 0)
			{
				color_array[new_color_idx] = color;
				new_color_idx++;
			}
			else
			{
				// Search
				for(c=0; c<8; c++)
				{
					if(color_array[c] == color)
					{
						c = 10;
					}
					else if(c == 7)
					{
						color_array[new_color_idx] = color;
						if(new_color_idx < 7)
						{
							new_color_idx++;
						}
					}
				}
			}
		}
	}

	uint8_t clut_idx = 4;
	for(clut_idx=4; clut_idx<12; clut_idx++)
	{
		clut_set(clut_idx, color_array[clut_idx-4]);
	}
}

void inline drawSprite(uint16_t x, uint16_t y, uint16_t id, uint16_t rotation) 
{
	unsigned int w,h;
	uint16_t x1,y1;
	uint16_t color;

	if (x >= HOR_RES-1 || y >= VER_RES-1 || x <= 0|| y <= 0) return;

	for (h=0; h < s[id].height; h++) {
		for (w=0; w < s[id].width; w++) {
			color = s[id].data[w + s[id].width*h];
			// don't draw if it matches transparency color
			if (color == s[id].trans) continue;
			
			uint8_t clut_idx = 4;
			for(clut_idx=4; clut_idx<12; clut_idx++)
			{
				if(color_array[clut_idx-4] == color)
				{
					rcc_color(clut_idx);
					clut_idx = 12;
				}
			}


			//rcc_color(color);
			//rcc_color(rand()); tv screen effect

			switch(rotation) {
				//  00 deg      0,0 1,0 2,0 ... 0,1
				//  90 deg CCW  7,0 7,1 7,2 ... 6,0
				// 180 deg      7,7 6,7 5,7 ... 7,6
				//  90 deg CW   0,7 0,6 0,5 ... 1,6
				case 0: // 0 degree
					x1 = x + w;
					y1 = y + h; // (h<<2) + (h<<1);//y+(PIX_H*h);
					if (x1 >= HOR_RES-2) continue; //br
					if (y1 >= VER_RES-PIX_H) return; //ret
					fast_pixel(x1, y1);
					break;
				case 1: // 90 degree CW
					x1 = x+(s[id].width-h-1);
					y1 = y+(PIX_H*(w));
					if (x1 >= HOR_RES-1 || x1 <= 0) continue;
					if (y1 >= VER_RES-PIX_H || y1 <= 0) continue;
					fast_pixel(x1, y1);
					break;
				case 2: // 180 degree CW
					x1 = x+(s[id].width-w-1);
					y1 = y+(PIX_H*(s[id].height-h-1));
					if (x1 >= HOR_RES-1) continue;
					if (y1 >= VER_RES-PIX_H) continue;
					fast_pixel(x1, y1);
					break;
				case 3: // 90 degree CCW
					break;
				default:
					break;
			}
			
		}
	}
	//Nop();
}

int inline nrange(double a, double b) 
{
	return (int)((a >= b) ? a-b : b-a);
}

void drawSpriteRotation(uint16_t x, uint16_t y, uint16_t id, float rotation) 
{
	int x1,y1,x2,y2;
	unsigned int w,h, real_x, real_y;
	uint16_t color;
	unsigned int shade = 0;
	float r_s,r_c;

	r_s = sin(rotation);
	r_c = cos(rotation);
 
	for (h=0; h < s[id].height; h++) {
		for (w=0; w < s[id].width; w++) {
			color = s[id].data[w + s[id].width*h];
			if (color == s[id].trans) continue;
			rcc_color(color+shade);

			x1 = -(s[id].width/2-w); // negative for origin centering 
			y1 = (s[id].height/2-h);
			x2 = x1*r_c - y1*r_s;
			y2 = x1*r_s + y1*r_c;

			real_x = x+nrange(x1,x2);
			real_y = y + PIX_H*nrange(y1,y2);

			if (real_x >= HOR_RES-1 || real_x <= 0) continue;
			if (real_y >= VER_RES-PIX_H || real_y <= 0) continue; // PIX_H for screen bordered setup
			//rcc_draw(real_x, real_y, 1, PIX_H);
			fast_pixel(real_x, real_y);
		}
	}
}

/* Particles */
int numPart=0;

void addParticle(void)
{
    p[numPart].size = 1;
    p[numPart].posx = rand() % (HOR_RES-2);
    p[numPart].posy = 1+(rand() % (VER_RES-7));
    p[numPart].speedx = 1+(rand() % 2);
    p[numPart].speedy = 0;
    p[numPart].color = rand();
    numPart++;
}
