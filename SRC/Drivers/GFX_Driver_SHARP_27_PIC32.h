#include "..\eGFX_DataTypes.h"

#ifndef GFX_DRIVER_SHARP_27_PIC32_H_
#define GFX_DRIVER_SHARP_27_PIC32_H_

#define SHARP_SS_ACTIVE               LATAbits.LATA2 = 1
#define SHARP_SS_INACTIVE             LATAbits.LATA2 = 0
#define SHARP_SPI_WRITE_REG           SPI2BUF
#define SHARP_SPI_READ_REG            SPI2BUF
#define WAIT_FOR_LCD_SPI_COMPLETE       while(SPI2STATbits.SPIRBF == 0){}

//LCD GFX Driver Configuration.
// The Symbols below must be defined for the GFX library to work.

#define GFX_DRIVER_PRESENT				//This is must be define for the main GFX library to compile
#define eGFX_PHYSICAL_SCREEN_SIZE_X	((uint16_t)400)		//This is the actual X and Y size of the physical screen in *pixels*
#define eGFX_PHYSICAL_SCREEN_SIZE_Y	((uint16_t)240)


#define GFX_BACKBUFFER_SIZE_X           ((((GFX_PHYSICAL_SCREEN_SIZE_X+8)>>3))<<3)		//This must be *at least* the physical screen size *rounded up* to the next multiple of 8
//to ensure each line in the backbuffer is on a byte boundary.  This is required for the
//bit manipulation functions to work correctly
#define GFX_BACKBUFFER_SIZE_Y       	GFX_PHYSICAL_SCREEN_Y		//This should always be the same as GFX_PHYSICAL_SCREEN_Y

//These are the prototypes for the GFX HAL
extern eGFX_ImagePlane eGFX_BackBuffer;
void GFX_InitPhysicalScreen();
void eGFX_Dump(eGFX_ImagePlane *Image);
void eGFX_InitDriver();
void GFX_PowerUpScreen();
void GFX_PowerDownScreen();

#endif