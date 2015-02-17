#include "..\eGFX_DataTypes.h"

#ifndef GFX_DRIVER_NHD_3_12__25664
#define GFX_DRIVER_NHD_3_12__25664


#define eGFX_PHYSICAL_SCREEN_SIZE_X	((uint16_t) 240)	//This is the actual X and Y size of the physical screen in *pixels*
#define eGFX_PHYSICAL_SCREEN_SIZE_Y	((uint16_t) 320)


//These are the prototypes for the GFX HAL
extern void	eGFX_InitDriver();
extern void	eGFX_Dump(eGFX_ImagePlane *Image);

//A Driver *Must* have a backbuffer exposed
extern eGFX_ImagePlane eGFX_BackBuffer;

void eGFX_Dump2(eGFX_ImagePlane *Image);

#endif
