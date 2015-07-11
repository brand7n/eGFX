#include "eGFX.h"
#include "eGFX_Driver_LedMatrix.h"

#define BLACK (0)
#define RED (0x7 << 5)
#define GREEN (0x7 << 2)
#define BLUE (0x3)
#define WHITE (0xff)

int main() 
{
    eGFX_InitDriver();
    eGFX_DrawLine(&eGFX_BackBuffer, 0, 0, 32, 16, RED);
    eGFX_DrawCircle(&eGFX_BackBuffer, 32, 16, 8, WHITE);
    eGFX_DrawFilledCircle(&eGFX_BackBuffer, 48, 16, 8, BLUE);
    eGFX_DrawLine(&eGFX_BackBuffer, 32, 0, 32, 32, GREEN);
    eGFX_Dump(&eGFX_BackBuffer);
}
