#include <stdint.h>
#include "pano_io.h"

uint8_t gCrtRow = 3;
uint8_t gCrtCol;
volatile uint32_t *gVram = VRAM;

void term_clear(void);
void term_putchar(char c);
void term_print(const char *cp);
void SetVramPtr(void);

void main() 
{
   LEDS = LED_RED;
   SetVramPtr();
   term_print("Hello world compiled " __DATE__ " " __TIME__ "\n");
   term_print("Hello Pano World!\n");
   LEDS = LED_GREEN;
   for( ; ; );
}



void term_clear() 
{
   gVram = VRAM;
   for(int i = 0; i < SCREEN_X * SCREEN_Y; i++) {
      *gVram++ = 0x20;
   }
   gVram = VRAM;
   gCrtRow = 0;
   gCrtCol = 0;
}

void SetVramPtr()
{
   gVram = VRAM + gCrtCol + (gCrtRow * SCREEN_X);
}

void term_putchar(char c)
{
   if(c == '\n') {
      gCrtRow++;
      if(gCrtRow >= SCREEN_Y) {
         gCrtRow = 0;
      }
      gCrtCol = 0;
      SetVramPtr();
   }
   else if(c == '\r') {
      gCrtCol = 0;
      SetVramPtr();
   }
   else {
      *gVram++ = c;
   }
}

void term_print(const char *cp)
{
   while(*cp) {
      term_putchar(*cp++);
   }
}

