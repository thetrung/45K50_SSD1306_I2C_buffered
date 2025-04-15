#define SSD1306_128_64

#include "main.h"
#include "ssd1306_buffered.c"

void testdrawcircle(void) {
  for (i8 i = 0; i < SSD1306_LCDHEIGHT; i += 2) {
    SSD1306_DrawCircle(SSD1306_LCDWIDTH/2, SSD1306_LCDHEIGHT/2, i);
    SSD1306_Display();
    // delay(1);
  }
}
 
void testfillrect(void) {
  bool color = true;
  for (i8 i = 0; i < SSD1306_LCDHEIGHT/2; i += 3) {
    // alternate colors
    SSD1306_FillRect(i, i, SSD1306_LCDWIDTH - i*2, SSD1306_LCDHEIGHT - i*2, color);
    SSD1306_Display();
    // delay(1);
    if(color)  color = false;
    else       color = true;
  }
}
 
void testdrawtriangle(void) {
  for (i8 i = 0; i < SSD1306_LCDHEIGHT/2; i += 5) {
    SSD1306_DrawTriangle(SSD1306_LCDWIDTH/2,     SSD1306_LCDHEIGHT/2 - i,
                         SSD1306_LCDWIDTH/2 - i, SSD1306_LCDHEIGHT/2 + i,
                         SSD1306_LCDWIDTH/2 + i, SSD1306_LCDHEIGHT/2 + i);
    SSD1306_Display();
    // delay(1);
  }
}
 
void testfilltriangle(void) {
  bool color = true;
  for (i16 i = SSD1306_LCDHEIGHT/2; i > 0; i -= 5) {
    SSD1306_FillTriangle(SSD1306_LCDWIDTH/2,     SSD1306_LCDHEIGHT/2 - i,
                         SSD1306_LCDWIDTH/2 - i, SSD1306_LCDHEIGHT/2 + i,
                         SSD1306_LCDWIDTH/2 + i, SSD1306_LCDHEIGHT/2 + i, color);
    if(color)  color = false;
    else       color = true;
    SSD1306_Display();
    // delay(1);
  }
}
 
void testdrawroundrect(void) {
  for (i8 i = 0; i < SSD1306_LCDHEIGHT/2 - 2; i += 2) {
    SSD1306_DrawRoundRect(i, i, SSD1306_LCDWIDTH - 2*i, SSD1306_LCDHEIGHT - 2*i, SSD1306_LCDHEIGHT/4 - i/2);
    SSD1306_Display();
    // delay(1);
  }
}
 
void testfillroundrect(void) {
  bool color = true;
  for (i8 i = 0; i < SSD1306_LCDHEIGHT/2 - 2; i += 2) {
    SSD1306_FillRoundRect(i, i, SSD1306_LCDWIDTH - 2*i, SSD1306_LCDHEIGHT - 2*i, SSD1306_LCDHEIGHT/4 - i/2, color);
    if(color)  color = false;
    else       color = true;
    SSD1306_Display();
    // delay(1);
  }
}
   
void testdrawrect(void) {
  for (i8 i = 0; i < SSD1306_LCDHEIGHT/2; i += 2) {
    SSD1306_DrawRect(i, i, SSD1306_LCDWIDTH - 2*i, SSD1306_LCDHEIGHT - 2*i);
    SSD1306_Display();
    // delay(1);
  }
}
 
void testdrawline() {  
  for (int i = 0; i < SSD1306_LCDWIDTH; i += 4) {
    SSD1306_DrawLine(0, 0, i, SSD1306_LCDHEIGHT - 1, true);
    SSD1306_Display();
    // delay(1);
  }
  for (int i = 0; i < SSD1306_LCDHEIGHT; i += 4) {
    SSD1306_DrawLine(0, 0, SSD1306_LCDWIDTH - 1, i, true);
    SSD1306_Display();
    // delay(1);
  }
  delay(250);
  
  SSD1306_ClearDisplay();
  for (int i = 0; i < SSD1306_LCDWIDTH; i += 4) {
    SSD1306_DrawLine(0, SSD1306_LCDHEIGHT - 1, i, 0, true);
    SSD1306_Display();
    // delay(1);
  }
  for (int i = SSD1306_LCDHEIGHT - 1; i >= 0; i -= 4) {
    SSD1306_DrawLine(0, SSD1306_LCDHEIGHT - 1, SSD1306_LCDWIDTH - 1, i, true);
    SSD1306_Display();
    // delay(1);
  }
  delay(250);
  
  SSD1306_ClearDisplay();
  for (int i = SSD1306_LCDWIDTH - 1; i >= 0; i -= 4) {
    SSD1306_DrawLine(SSD1306_LCDWIDTH - 1, SSD1306_LCDHEIGHT - 1, i, 0, true);
    SSD1306_Display();
    // delay(1);
  }
  for (int i = SSD1306_LCDHEIGHT - 1; i >= 0; i -= 4) {
    SSD1306_DrawLine(SSD1306_LCDWIDTH - 1, SSD1306_LCDHEIGHT - 1, 0, i, true);
    SSD1306_Display();
    // delay(1);
  }
  delay(250);
 
  SSD1306_ClearDisplay();
  for (int i = 0; i < SSD1306_LCDHEIGHT; i += 4) {
    SSD1306_DrawLine(SSD1306_LCDWIDTH - 1, 0, 0, i, true);
    SSD1306_Display();
    delay(1);
  }
  for (int i = 0; i < SSD1306_LCDWIDTH; i += 4) {
    SSD1306_DrawLine(SSD1306_LCDWIDTH - 1, 0, i, SSD1306_LCDHEIGHT - 1, true); 
    SSD1306_Display();
    delay(1);
  }
  delay(250);
}
 
void testscrolltext(void) {
  SSD1306_ClearDisplay();
  SSD1306_DrawText(58, 8, "scroll", 2);
  SSD1306_Display();
  delay(1);
 
  SSD1306_StartScrollRight(0x00, 0x0F);
  delay(2000);
  SSD1306_StopScroll();
  delay(1000);
  SSD1306_StartScrollLeft(0x00, 0x0F);
  delay(2000);
  SSD1306_StopScroll();
  delay(1000);    
  SSD1306_StartScrollDiagRight(0x00, 0x07);
  delay(2000);
  SSD1306_StartScrollDiagLeft(0x00, 0x07);
  delay(2000);
  SSD1306_StopScroll();
}

/*==============================================================================
 * Main routine
 *  - Initialize system
 *  - Loop forever
 *============================================================================*/
void main(void) {
    init();
    delay(100);
      
    SSD1306_Begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);       
    delay(100);
   
    // draw many lines
    testdrawline();
    SSD1306_Display();
    delay(2000);
    SSD1306_ClearDisplay();

    // draw rectangles
    testdrawrect();
    SSD1306_Display();
    delay(2000);
    SSD1306_ClearDisplay();

    // draw multiple rectangles
    testfillrect();
    SSD1306_Display();
    delay(2000);
    SSD1306_ClearDisplay();

    // draw multiple circles
    testdrawcircle();
    SSD1306_Display();
    delay(2000);
    SSD1306_ClearDisplay();

    // draw a white circle, 10 pixel radius
    SSD1306_FillCircle(SSD1306_LCDWIDTH/2, SSD1306_LCDHEIGHT/2, 10, true);
    SSD1306_Display();
    delay(2000);
    SSD1306_ClearDisplay();

    
    testdrawroundrect();
    SSD1306_Display();
    delay(2000);
    SSD1306_ClearDisplay();

    testfillroundrect();
    SSD1306_Display();
    delay(2000);
    SSD1306_ClearDisplay();

    testdrawtriangle();
    SSD1306_Display();
    delay(2000);
    SSD1306_ClearDisplay();

    testfilltriangle();
    SSD1306_Display();
    delay(2000);
    SSD1306_ClearDisplay();

    // draw scrolling text
    testscrolltext();
    SSD1306_Display();
    delay(2000);
    SSD1306_ClearDisplay();

    // text display tests
    char txt[9];
    SSD1306_DrawText(2, 7, "Hello, world!", 1);

    sprintf(txt, "%.6f", 3.141592);
    SSD1306_DrawText(2, 16, txt, 1);

    SSD1306_DrawText(2, 26, "0x", 2);

    sprintf(txt, "%LX", 0xDEADBEEF);
    SSD1306_DrawText(26, 26, txt, 2);
    SSD1306_Display();
    delay(2000);

    //Loop
    while(1) loop();
}

/*==============================================================================
 * Loop routine
 *============================================================================*/
void loop(void) { delay(1000);}