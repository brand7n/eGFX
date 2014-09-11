
#include "eGFX_DataTypes.h"
#include "eGFX.h"
#include "eGFX_Driver_Win32.h"

//#define WIN32_1BPP
#define WIN32_4BPP
//#define WIN32_8BPP


eGFX_ImagePlane eGFX_BackBuffer;

#ifdef WIN32_1BPP
	uint8_t BackBufferStore[eGFX_CALCULATE_1BPP_IMAGE_STORAGE_SPACE_SIZE(eGFX_PHYSICAL_SCREEN_SIZE_X, eGFX_PHYSICAL_SCREEN_SIZE_Y)];
#endif

#ifdef WIN32_4BPP
	uint8_t BackBufferStore[eGFX_CALCULATE_4BPP_IMAGE_STORAGE_SPACE_SIZE(eGFX_PHYSICAL_SCREEN_SIZE_X, eGFX_PHYSICAL_SCREEN_SIZE_Y)];
#endif

#ifdef WIN32_8BPP
	uint8_t BackBufferStore[eGFX_CALCULATE_8BPP_IMAGE_STORAGE_SPACE_SIZE(eGFX_PHYSICAL_SCREEN_SIZE_X, eGFX_PHYSICAL_SCREEN_SIZE_Y)];
#endif


void eGFX_InitDriver()
{

	#ifdef WIN32_1BPP
		eGFX_ImagePlaneInit(&eGFX_BackBuffer, BackBufferStore, eGFX_PHYSICAL_SCREEN_SIZE_X, eGFX_PHYSICAL_SCREEN_SIZE_Y, eGFX_IMAGE_PLANE_1BPP);
	#endif

	#ifdef WIN32_4BPP
		eGFX_ImagePlaneInit(&eGFX_BackBuffer, BackBufferStore, eGFX_PHYSICAL_SCREEN_SIZE_X, eGFX_PHYSICAL_SCREEN_SIZE_Y, eGFX_IMAGE_PLANE_4BPP);
	#endif
		
	#ifdef WIN32_8BPP
		eGFX_ImagePlaneInit(&eGFX_BackBuffer, BackBufferStore, eGFX_PHYSICAL_SCREEN_SIZE_X, eGFX_PHYSICAL_SCREEN_SIZE_Y, eGFX_IMAGE_PLANE_8BPP);
	#endif
}

void eGFX_Dump(eGFX_ImagePlane *Image)
{
    
}

