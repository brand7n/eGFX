#include "Board.h"
#include "Chip.h"
#include "eGFX_DataTypes.h"
#include "eGFX.h"
#include "eGFX_Driver_MCB4300.h"

eGFX_ImagePlane eGFX_BackBuffer;


#ifdef DRV_4BPP
__BSS(M4_1) uint8_t BackBufferStore[eGFX_CALCULATE_4BPP_IMAGE_STORAGE_SPACE_SIZE(eGFX_PHYSICAL_SCREEN_SIZE_X, eGFX_PHYSICAL_SCREEN_SIZE_Y)];
#endif

#ifdef DRV_8BPP
	uint8_t BackBufferStore[eGFX_CALCULATE_8BPP_IMAGE_STORAGE_SPACE_SIZE(eGFX_PHYSICAL_SCREEN_SIZE_X, eGFX_PHYSICAL_SCREEN_SIZE_Y)];
#endif

uint16_t *framebuffer = FRAMEBUFFER_ADDR;

static uint16_t *framebuffer1 = (uint16_t *) FRAMEBUFFER_ADDR;
static uint16_t *framebuffer2 = (uint16_t *) FRAMEBUFFER_ADDR + (320 * 240 * 4);



void eGFX_InitDriver()
{
    eGFX_ImagePlaneInit(&eGFX_BackBuffer,(uint8_t *)framebuffer,eGFX_PHYSICAL_SCREEN_SIZE_X, eGFX_PHYSICAL_SCREEN_SIZE_Y,eGFX_IMAGE_PLANE_16BPP);


	Board_LCD_Init();
	Chip_LCD_Init(LPC_LCD, (LCD_CONFIG_T *) &BOARD_LCD);
	Board_InitTouchController();
	Chip_LCD_SetUPFrameBuffer(LPC_LCD,  (void *) framebuffer);
	Chip_LCD_PowerOn(LPC_LCD);
	/* Turn on backlight */
	Board_SetLCDBacklight(1);
}

//This will flag the M0 to dump the image buffer
void eGFX_Dump(eGFX_ImagePlane *Image)
{
	Chip_LCD_SetUPFrameBuffer(LPC_LCD,  Image->Data);

	if(Image->Data == (uint8_t *)framebuffer1)
		 Image->Data  = (uint8_t *)framebuffer2;
	  else
		  Image->Data  = (uint8_t *)framebuffer1;
}

