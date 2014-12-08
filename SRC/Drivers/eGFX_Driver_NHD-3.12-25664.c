
#ifdef  CORE_M4
	#include "System.h"
#endif
#include "Chip.h"
#include "eGFX_DataTypes.h"
#include "eGFX.h"
#include "eGFX_Driver_NHD-3.12-25664.h"
#include "IPC.h"

//Plumbing for the OLED display

void OLED_Init_25664();
void OLED_Clear_25664();

void Set_Linear_Gray_Scale_Table_25664();
void Set_Gray_Scale_Table_25664();
void Set_Command_Lock_25664(unsigned char d);
void Set_Display_Enhancement_B_25664(unsigned char d);
void Set_Multiplex_Ratio_25664(unsigned char d);
void Set_Master_Current_25664(unsigned char d);
void Set_Contrast_Current_25664(unsigned char d);
void Set_VCOMH_25664(unsigned char d);
void Set_VCOMH_25664(unsigned char d);
void Set_Precharge_Voltage_25664(unsigned char d);
void Set_Precharge_Period_25664(unsigned char d);
void Set_GPIO_25664(unsigned char d);
void Set_Display_Enhancement_A_25664(unsigned char a,
                                     unsigned char b);
void Set_Display_Clock_25664(unsigned char d);
void Set_Phase_Length_25664(unsigned char d);
void Set_Display_On_Off_25664(unsigned char d);
void Set_Function_Selection_25664(unsigned char d);
void Set_Partial_Display_25664(unsigned char a,
                               unsigned char b, unsigned char c);
void Set_Display_Mode_25664(unsigned char d);
void Set_Display_Offset_25664(unsigned char d);
void Set_Start_Line_25664(unsigned char d);
void Set_Remap_Format_25664(unsigned char d);
void Set_Write_RAM_25664();
void Set_Row_Address_25664(unsigned char a,
                           unsigned char b);
void Set_Column_Address_25664(unsigned char a,
                              unsigned char b);
void oled_Data_25664(unsigned char Data);
void oled_Command_25664(unsigned char Data);



//************************************************************************
//plumbing for Driver
//************************************************************************
void InitNHD_312_25664();
void TestNHD_312_25664();
void NHD_312_25664_Delay ();


//***********************************************************************************
//Linking Functions to The GFX main library
//***********************************************************************************


#ifdef CORE_M4

//#define WIN32_1BPP
#define DRV_4BPP
//#define WIN32_8BPP

eGFX_ImagePlane eGFX_BackBuffer;


#ifdef DRV_4BPP
__BSS(M4_1) uint8_t BackBufferStore[eGFX_CALCULATE_4BPP_IMAGE_STORAGE_SPACE_SIZE(eGFX_PHYSICAL_SCREEN_SIZE_X, eGFX_PHYSICAL_SCREEN_SIZE_Y)];
#endif

#ifdef DRV_8BPP
	uint8_t BackBufferStore[eGFX_CALCULATE_8BPP_IMAGE_STORAGE_SPACE_SIZE(eGFX_PHYSICAL_SCREEN_SIZE_X, eGFX_PHYSICAL_SCREEN_SIZE_Y)];
#endif


void eGFX_InitDriver()
{
    eGFX_ImagePlaneInit(&eGFX_BackBuffer,&BackBufferStore[0],eGFX_PHYSICAL_SCREEN_SIZE_X, eGFX_PHYSICAL_SCREEN_SIZE_Y,eGFX_IMAGE_PLANE_4BPP);

	InitNHD_312_25664();
}

#endif


//This function is executed by the M0 to dump the image
void eGFX_Dump2(eGFX_ImagePlane *Image)
{
    uint16_t x,y,DataOut;


    Set_Write_RAM_25664();

    for(y=0; y<64; y++)
    {
        for(x=0; x<128; x++)
        {
            DataOut = eGFX_ImagePlane_GetByte(Image,
            								   x<<1,
            								   y);

            oled_Data_25664(DataOut);
        }
    }


}

//This will flag the M0 to dump the image buffer
void eGFX_Dump(eGFX_ImagePlane *Image)
{

	MyIPC.eGFX_BackBuffer = Image;
	MyIPC.Msg_M4_M0 = IPC_MSG_DUMP_GFX;
    IPC_Poke();
}



void OLED_Clear_25664()
{
   uint16_t x,y;

    Set_Write_RAM_25664();

    for(y=0; y<64; y++)
    {
        for(x=0; x<128; x++)
        {
            oled_Data_25664(0);
        }
    }
}


//************************************************************************
//Functions/Macros for porting to other CPUS...
//************************************************************************

#define DB0_GPIO	7,0
#define DB0_PIN		0xE,0
#define DB0_MUX		FUNC4

#define DB1_GPIO	7,1
#define DB1_PIN		0xE,1
#define DB1_MUX		FUNC4

#define DB2_GPIO	7,2
#define DB2_PIN		0xE,2
#define DB2_MUX		FUNC4

#define DB3_GPIO	7,3
#define DB3_PIN		0xE,3
#define DB3_MUX		FUNC4

#define DB4_GPIO	7,4
#define DB4_PIN		0xE,4
#define DB4_MUX		FUNC4

#define DB5_GPIO	7,5
#define DB5_PIN		0xE,5
#define DB5_MUX		FUNC4

#define DB6_GPIO	7,6
#define DB6_PIN		0xE,6
#define DB6_MUX		FUNC4

#define DB7_GPIO	7,7
#define DB7_PIN		0xE,7
#define DB7_MUX		FUNC4

#define RW_GPIO		7,9
#define RW_PIN		0xE,9
#define RW_MUX		FUNC4

#define DC_GPIO		7,10
#define DC_PIN		0xE,10
#define DC_MUX		FUNC4

#define RES_GPIO	7,11
#define RES_PIN		0xE,11
#define RES_MUX		FUNC4

#define E_GPIO		7,8
#define E_PIN		0xE,8
#define E_MUX		FUNC4

#define CS_GPIO		7,13
#define CS_PIN		0xE,13
#define CS_MUX		FUNC4


void PutNHD_312_25664_DataBits(uint8_t Data);
uint8_t GetNHD_312_25664_DataBits();
void SetNHD_312_25664_DataBusAsOutputs();
void SetNHD_312_25664_DataBusAsInputs();
void InitNHD_312_25664_Interface();

#define NHD_312_25664_DELAY_MS(x)	//Delay_mS(x)
#define NHD_312_25664_DELAY_US(x)	//Delay_uS(x)

#define NHD_312_25664_SET_DC		Chip_GPIO_WritePortBit(LPC_GPIO_PORT,DC_GPIO, 1)
#define NHD_312_25664_CLEAR_DC		Chip_GPIO_WritePortBit(LPC_GPIO_PORT,DC_GPIO, 0)

#define NHD_312_25664_SET_RES		Chip_GPIO_WritePortBit(LPC_GPIO_PORT,RES_GPIO, 1)
#define NHD_312_25664_CLEAR_RES		Chip_GPIO_WritePortBit(LPC_GPIO_PORT,RES_GPIO, 0)

#define NHD_312_25664_SET_RW		Chip_GPIO_WritePortBit(LPC_GPIO_PORT,RW_GPIO, 1)
#define NHD_312_25664_CLEAR_RW		Chip_GPIO_WritePortBit(LPC_GPIO_PORT,RW_GPIO, 0)

#define NHD_312_25664_SET_E			Chip_GPIO_WritePortBit(LPC_GPIO_PORT,E_GPIO, 1)
#define NHD_312_25664_CLEAR_E		Chip_GPIO_WritePortBit(LPC_GPIO_PORT,E_GPIO, 0)

#define NHD_312_25664_SET_CS			Chip_GPIO_WritePortBit(LPC_GPIO_PORT,CS_GPIO, 1)
#define NHD_312_25664_CLEAR_CS			Chip_GPIO_WritePortBit(LPC_GPIO_PORT,CS_GPIO, 0)


void InitNHD_312_25664_Interface()
{
    Chip_SCU_PinMux(RES_PIN, SCU_PINIO_FAST  , RES_MUX);
    Chip_GPIO_WriteDirBit(LPC_GPIO_PORT,RES_GPIO	, true);
    Chip_SCU_PinMux(RW_PIN,SCU_PINIO_FAST, RW_MUX);
    Chip_GPIO_WriteDirBit(LPC_GPIO_PORT,RW_GPIO	, true);
    Chip_SCU_PinMux(DC_PIN, SCU_PINIO_FAST , DC_MUX);
    Chip_GPIO_WriteDirBit(LPC_GPIO_PORT,DC_GPIO, true);
    Chip_SCU_PinMux(E_PIN,SCU_PINIO_FAST , E_MUX);
    Chip_GPIO_WriteDirBit(LPC_GPIO_PORT,E_GPIO, true);
    Chip_SCU_PinMux(CS_PIN,SCU_PINIO_FAST , CS_MUX);
    Chip_GPIO_WriteDirBit(LPC_GPIO_PORT,CS_GPIO, true);
    SetNHD_312_25664_DataBusAsOutputs();
    NHD_312_25664_SET_CS;
    NHD_312_25664_CLEAR_E;
    NHD_312_25664_CLEAR_RW;
    NHD_312_25664_CLEAR_DC;
    NHD_312_25664_SET_RES;
    NHD_312_25664_Delay ();
    NHD_312_25664_CLEAR_RES;
    NHD_312_25664_Delay ();
    NHD_312_25664_SET_RES;
    NHD_312_25664_Delay ();
    OLED_Init_25664();
}

//This function set the data pins D0-D7 as Inputs
void SetNHD_312_25664_DataBusAsInputs()
{
    Chip_SCU_PinMux(DB0_PIN, SCU_PINIO_FAST , DB0_MUX);
    Chip_GPIO_WriteDirBit(LPC_GPIO_PORT,DB0_GPIO, false);
    Chip_SCU_PinMux(DB1_PIN, SCU_PINIO_FAST , DB1_MUX);
    Chip_GPIO_WriteDirBit(LPC_GPIO_PORT,DB1_GPIO, false);
    Chip_SCU_PinMux(DB2_PIN, SCU_PINIO_FAST , DB2_MUX);
    Chip_GPIO_WriteDirBit(LPC_GPIO_PORT,DB2_GPIO, false);
    Chip_SCU_PinMux(DB3_PIN, SCU_PINIO_FAST , DB3_MUX);
    Chip_GPIO_WriteDirBit(LPC_GPIO_PORT,DB3_GPIO, false);
    Chip_SCU_PinMux(DB4_PIN,SCU_PINIO_FAST, DB4_MUX);
    Chip_GPIO_WriteDirBit(LPC_GPIO_PORT,DB4_GPIO, false);
    Chip_SCU_PinMux(DB5_PIN, SCU_PINIO_FAST , DB5_MUX);
    Chip_GPIO_WriteDirBit(LPC_GPIO_PORT,DB5_GPIO, false);
    Chip_SCU_PinMux(DB6_PIN, SCU_PINIO_FAST , DB6_MUX);
    Chip_GPIO_WriteDirBit(LPC_GPIO_PORT,DB6_GPIO, false);
    Chip_SCU_PinMux(DB7_PIN, SCU_PINIO_FAST , DB7_MUX);
    Chip_GPIO_WriteDirBit(LPC_GPIO_PORT,DB7_GPIO, false);
}

//This function set the data pins D0-D7 as outputs
void SetNHD_312_25664_DataBusAsOutputs()
{
    Chip_SCU_PinMux(DB0_PIN,SCU_PINIO_FAST , DB0_MUX);
    Chip_GPIO_WriteDirBit(LPC_GPIO_PORT,DB0_GPIO, true);
    Chip_SCU_PinMux(DB1_PIN, SCU_PINIO_FAST , DB1_MUX);
    Chip_GPIO_WriteDirBit(LPC_GPIO_PORT,DB1_GPIO, true);
    Chip_SCU_PinMux(DB2_PIN, SCU_PINIO_FAST , DB2_MUX);
    Chip_GPIO_WriteDirBit(LPC_GPIO_PORT,DB2_GPIO, true);
    Chip_SCU_PinMux(DB3_PIN, SCU_PINIO_FAST , DB3_MUX);
    Chip_GPIO_WriteDirBit(LPC_GPIO_PORT,DB3_GPIO, true);
    Chip_SCU_PinMux(DB4_PIN, SCU_PINIO_FAST, DB4_MUX);
    Chip_GPIO_WriteDirBit(LPC_GPIO_PORT,DB4_GPIO, true);
    Chip_SCU_PinMux(DB5_PIN,SCU_PINIO_FAST , DB5_MUX);
    Chip_GPIO_WriteDirBit(LPC_GPIO_PORT,DB5_GPIO, true);
    Chip_SCU_PinMux(DB6_PIN, SCU_PINIO_FAST , DB6_MUX);
    Chip_GPIO_WriteDirBit(LPC_GPIO_PORT,DB6_GPIO, true);
    Chip_SCU_PinMux(DB7_PIN, SCU_PINIO_FAST , DB7_MUX);
    Chip_GPIO_WriteDirBit(LPC_GPIO_PORT,DB7_GPIO, true);
}


//Need for read/write strobe setup timing
//Just need a pinch to get a 1uS cycle timing
void NHD_312_25664_Delay ()
{
    uint32_t t;

    for(t=0; t<1; t++)
    {
    }
}

//This function should put data on D0-D7
//This function is need in case the data pins are not in nice, orderly location ie. P0.0 to P0.7
//   Each bit in the data byte will be test and the GPIO will be set/Cleared
void PutNHD_312_25664_DataBits(uint8_t Data)
{
	Chip_GPIO_SetPortMask(LPC_GPIO_PORT, 7,~0xFF);
	Chip_GPIO_SetMaskedPortValue(LPC_GPIO_PORT,7,Data);
	/*
    if(Data&0x01)
        Chip_GPIO_WritePortBit(LPC_GPIO_PORT,DB0_GPIO, 1);

    else
        Chip_GPIO_WritePortBit(LPC_GPIO_PORT,DB0_GPIO, 0);

    if(Data&0x02)
        Chip_GPIO_WritePortBit(LPC_GPIO_PORT,DB1_GPIO, 1);

    else
        Chip_GPIO_WritePortBit(LPC_GPIO_PORT,DB1_GPIO, 0);

    if(Data&0x04)
        Chip_GPIO_WritePortBit(LPC_GPIO_PORT,DB2_GPIO, 1);

    else
        Chip_GPIO_WritePortBit(LPC_GPIO_PORT,DB2_GPIO, 0);

    if(Data&0x08)
        Chip_GPIO_WritePortBit(LPC_GPIO_PORT,DB3_GPIO, 1);

    else
        Chip_GPIO_WritePortBit(LPC_GPIO_PORT,DB3_GPIO, 0);

    if(Data&0x10)
        Chip_GPIO_WritePortBit(LPC_GPIO_PORT,DB4_GPIO, 1);

    else
        Chip_GPIO_WritePortBit(LPC_GPIO_PORT,DB4_GPIO, 0);

    if(Data&0x20)
        Chip_GPIO_WritePortBit(LPC_GPIO_PORT,DB5_GPIO, 1);

    else
        Chip_GPIO_WritePortBit(LPC_GPIO_PORT,DB5_GPIO, 0);

    if(Data&0x40)
        Chip_GPIO_WritePortBit(LPC_GPIO_PORT,DB6_GPIO, 1);

    else
        Chip_GPIO_WritePortBit(LPC_GPIO_PORT,DB6_GPIO, 0);

    if(Data&0x80)
        Chip_GPIO_WritePortBit(LPC_GPIO_PORT,DB7_GPIO, 1);

    else
        Chip_GPIO_WritePortBit(LPC_GPIO_PORT,DB7_GPIO, 0);*/
}

//This function should return the data at D0-D7
//It is currently implemented in case the IO are not in a nice orderly arrangement
uint8_t GetNHD_312_25664_DataBits()
{
    uint8_t Data = 0;

    if(Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,DB0_GPIO) == true)
        Data |= 1<<0;

    if(Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,DB1_GPIO) == true)
        Data |= 1<<1;

    if(Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,DB2_GPIO) == true)
        Data |= 1<<2;

    if(Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,DB3_GPIO) == true)
        Data |= 1<<3;

    if(Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,DB4_GPIO) == true)
        Data |= 1<<4;

    if(Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,DB5_GPIO) == true)
        Data |= 1<<5;

    if(Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,DB6_GPIO) == true)
        Data |= 1<<6;

    if(Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,DB7_GPIO) == true)
        Data |= 1<<7;

    return Data;
}


#define SETUP_FOR_DISPLAY_DATA			NHD_312_25664_SET_DC
#define SETUP_FOR_COMMAND_STATUS		NHD_312_25664_CLEAR_DC


void TestNHD_312_25664()
{
    //uint8_t TestData = 0;
    //SetNHD_312_25664_DataBusAsOutputs();
    /*
    while(1)
    {
    	SETUP_FOR_DISPLAY_DATA;


    	NHD_312_25664_Delay();
    	SETUP_FOR_COMMAND_STATUS;
    	NHD_312_25664_CLEAR_RES;
    	NHD_312_25664_SET_RW;
    	 NHD_312_25664_SET_E;

    	 NHD_312_25664_Delay();
    	 SETUP_FOR_DISPLAY_DATA;
    	 NHD_312_25664_SET_RES;
    	 NHD_312_25664_CLEAR_RW;
    	 NHD_312_25664_CLEAR_E;


    	 PutNHD_312_25664_DataBits(TestData++);
    }
    */
}


void InitNHD_312_25664()
{
    InitNHD_312_25664_Interface();
}

/***
 *    .__   __.  __    __   _______          _______.     ___      .___  ___. .______    __       _______      ______   ______    _______   _______
 *    |  \ |  | |  |  |  | |       \        /       |    /   \     |   \/   | |   _  \  |  |     |   ____|    /      | /  __  \  |       \ |   ____|
 *    |   \|  | |  |__|  | |  .--.  |      |   (----`   /  ^  \    |  \  /  | |  |_)  | |  |     |  |__      |  ,----'|  |  |  | |  .--.  ||  |__
 *    |  . `  | |   __   | |  |  |  |       \   \      /  /_\  \   |  |\/|  | |   ___/  |  |     |   __|     |  |     |  |  |  | |  |  |  ||   __|
 *    |  |\   | |  |  |  | |  '--'  |   .----)   |    /  _____  \  |  |  |  | |  |      |  `----.|  |____    |  `----.|  `--'  | |  '--'  ||  |____
 *    |__| \__| |__|  |__| |_______/    |_______/    /__/     \__\ |__|  |__| | _|      |_______||_______|    \______| \______/  |_______/ |_______|
 *
 */

//--------------------------------------------------------------------------
//send Command to OLED
//--------------------------------------------------------------------------
void oled_Command_25664(unsigned char Data)
{
    SETUP_FOR_COMMAND_STATUS;
    NHD_312_25664_Delay ();
    PutNHD_312_25664_DataBits(Data);
    NHD_312_25664_Delay ();
    NHD_312_25664_CLEAR_CS;
    NHD_312_25664_Delay ();
    NHD_312_25664_CLEAR_RW;
    NHD_312_25664_Delay ();
    NHD_312_25664_SET_E;
    NHD_312_25664_Delay ();
    NHD_312_25664_CLEAR_E;
    NHD_312_25664_Delay ();
    NHD_312_25664_SET_CS;
    NHD_312_25664_Delay ();
    //unsigned char i;	  //3-wire serial mode
    //GPIO_ResetBits(GPIOC, RS);
    //GPIO_ResetBits(GPIOC, RW);
    //GPIO_ResetBits(GPIOC, E1);
    //GPIO_ResetBits(GPIOC, CS1);
    //
    //GPIO_ResetBits(GPIOB, GPIO_Pin_1);//D/C = Command
    //GPIO_ResetBits(GPIOB, GPIO_Pin_0);
    //GPIO_SetBits(GPIOB, GPIO_Pin_0);
    //	for (i=0; i<8; i++)
    //	{
    //		GPIO_ResetBits(GPIOB, GPIO_Pin_0);
    //		if((Data&0x80)>>7==1){GPIO_SetBits(GPIOB, GPIO_Pin_1);}
    //		else {GPIO_ResetBits(GPIOB, GPIO_Pin_1);}
    //		Data = Data << 1;
    //		GPIO_SetBits(GPIOB, GPIO_Pin_0);
    //	}
    //GPIO_SetBits(GPIOC, CS1); //end 3-wire serial mode
    //unsigned char i;	  //begin 4-wire serial mode
    //GPIO_ResetBits(GPIOC, RS);
    //GPIO_ResetBits(GPIOC, RW);
    //GPIO_ResetBits(GPIOC, E1);
    //GPIO_ResetBits(GPIOC, CS1);
    //
    //	for (i=0; i<8; i++)
    //	{
    //		GPIO_ResetBits(GPIOB, GPIO_Pin_0);
    //		if((Data&0x80)>>7==1){GPIO_SetBits(GPIOB, GPIO_Pin_1);}
    //		else {GPIO_ResetBits(GPIOB, GPIO_Pin_1);}
    //		Data = Data << 1;
    //		GPIO_SetBits(GPIOB, GPIO_Pin_0);
    //	}
    //GPIO_SetBits(GPIOC, RS);
    //GPIO_SetBits(GPIOC, CS1); //end 4-wire serial mode
}

//--------------------------------------------------------------------------
//send Data to OLED
//--------------------------------------------------------------------------
void oled_Data_25664(unsigned char Data)
{
    SETUP_FOR_DISPLAY_DATA;
    PutNHD_312_25664_DataBits(Data);
    NHD_312_25664_CLEAR_RW;
    NHD_312_25664_CLEAR_CS;
    NHD_312_25664_Delay ();
    NHD_312_25664_SET_E;
    NHD_312_25664_Delay ();
    NHD_312_25664_CLEAR_E;
    NHD_312_25664_Delay ();
    NHD_312_25664_SET_CS;
}


//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

void Set_Column_Address_25664(unsigned char a,
                              unsigned char b)
{
    oled_Command_25664(0x15);			// Set Column Address
    oled_Data_25664(a);				//   Default => 0x00
    oled_Data_25664(b);				//   Default => 0x77
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

void Set_Row_Address_25664(unsigned char a, unsigned char b)
{
    oled_Command_25664(0x75);			// Set Row Address
    oled_Data_25664(a);				//   Default => 0x00
    oled_Data_25664(b);				//   Default => 0x7F
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

void Set_Write_RAM_25664()
{
    oled_Command_25664(0x5C);			// Enable MCU to Write into RAM
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

void Set_Remap_Format_25664(unsigned char d)
{
    oled_Command_25664(
        0xA0);			// Set Re-Map / Dual COM Line Mode
    oled_Data_25664(d);				//   Default => 0x40
    //     Horizontal Address Increment
    //     Column Address 0 Mapped to SEG0
    //     Disable Nibble Remap
    //     Scan from COM0 to COM[N-1]
    //     Disable COM Split Odd Even
    oled_Data_25664(
        0x11);			//   Default => 0x01 (Disable Dual COM Mode)
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

void Set_Start_Line_25664(unsigned char d)
{
    oled_Command_25664(0xA1);			// Set Vertical Scroll by RAM
    oled_Data_25664(d);				//   Default => 0x00
}

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
void Set_Display_Offset_25664(unsigned char d)
{
    oled_Command_25664(0xA2);			// Set Vertical Scroll by Row
    oled_Data_25664(d);				//   Default => 0x00
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

void Set_Display_Mode_25664(unsigned char d)
{
    oled_Command_25664(0xA4|d);			// Set Display Mode
    //   Default => 0xA4
    //     0xA4 (0x00) => Entire Display Off, All Pixels Turn Off
    //     0xA5 (0x01) => Entire Display On, All Pixels Turn On at GS Level 15
    //     0xA6 (0x02) => Normal Display
    //     0xA7 (0x03) => Inverse Display
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

void Set_Partial_Display_25664(unsigned char a,
                               unsigned char b, unsigned char c)
{
    oled_Command_25664(0xA8|a);

    // Default => 0x8F
    //   Select Internal Booster at Display On
    if(a == 0x00)
    {
        oled_Data_25664(b);
        oled_Data_25664(c);
    }
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

void Set_Function_Selection_25664(unsigned char d)
{
    oled_Command_25664(0xAB);			// Function Selection
    oled_Data_25664(d);				//   Default => 0x01
    //     Enable Internal VDD Regulator
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

void Set_Display_On_Off_25664(unsigned char d)
{
    oled_Command_25664(0xAE|d);			// Set Display On/Off
    //   Default => 0xAE
    //     0xAE (0x00) => Display Off (Sleep Mode On)
    //     0xAF (0x01) => Display On (Sleep Mode Off)
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

void Set_Phase_Length_25664(unsigned char d)
{
    oled_Command_25664(
        0xB1);			// Phase 1 (Reset) & Phase 2 (Pre-Charge) Period Adjustment
    oled_Data_25664(
        d);				//   Default => 0x74 (7 Display Clocks [Phase 2] / 9 Display Clocks [Phase 1])
    //     D[3:0] => Phase 1 Period in 5~31 Display Clocks
    //     D[7:4] => Phase 2 Period in 3~15 Display Clocks
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

void Set_Display_Clock_25664(unsigned char d)
{
    oled_Command_25664(
        0xB3);			// Set Display Clock Divider / Oscillator Frequency
    oled_Data_25664(d);				//   Default => 0xD0
    //     A[3:0] => Display Clock Divider
    //     A[7:4] => Oscillator Frequency
}

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
void Set_Display_Enhancement_A_25664(unsigned char a,
                                     unsigned char b)
{
    oled_Command_25664(0xB4);			// Display Enhancement
    oled_Data_25664(0xA0|a);			//   Default => 0xA2
    //     0xA0 (0x00) => Enable External VSL
    //     0xA2 (0x02) => Enable Internal VSL (Kept VSL Pin N.C.)
    oled_Data_25664(0x05|b);			//   Default => 0xB5
    //     0xB5 (0xB0) => Normal
    //     0xFD (0xF8) => Enhance Low Gray Scale Display Quality
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

void Set_GPIO_25664(unsigned char d)
{
    oled_Command_25664(0xB5);			// General Purpose IO
    oled_Data_25664(
        d);				//   Default => 0x0A (GPIO Pins output Low Level.)
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

void Set_Precharge_Period_25664(unsigned char d)
{
    oled_Command_25664(0xB6);			// Set Second Pre-Charge Period
    oled_Data_25664(
        d);				//   Default => 0x08 (8 Display Clocks)
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

void Set_Precharge_Voltage_25664(unsigned char d)
{
    oled_Command_25664(0xBB);			// Set Pre-Charge Voltage Level
    oled_Data_25664(d);				//   Default => 0x17 (0.50*VCC)
}

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
void Set_VCOMH_25664(unsigned char d)
{
    oled_Command_25664(
        0xBE);			// Set COM Deselect Voltage Level
    oled_Data_25664(d);				//   Default => 0x04 (0.80*VCC)
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

void Set_Contrast_Current_25664(unsigned char d)
{
    oled_Command_25664(0xC1);			// Set Contrast Current
    oled_Data_25664(d);				//   Default => 0x7F
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

void Set_Master_Current_25664(unsigned char d)
{
    oled_Command_25664(
        0xC7);			// Master Contrast Current Control
    oled_Data_25664(d);				//   Default => 0x0f (Maximum)
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

void Set_Multiplex_Ratio_25664(unsigned char d)
{
    oled_Command_25664(0xCA);			// Set Multiplex Ratio
    oled_Data_25664(d);				//   Default => 0x7F (1/128 Duty)
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

void Set_Display_Enhancement_B_25664(unsigned char d)
{
    oled_Command_25664(0xD1);			// Display Enhancement
    oled_Data_25664(0x82|d);			//   Default => 0xA2
    //     0x82 (0x00) => Reserved
    //     0xA2 (0x20) => Normal
    oled_Data_25664(0x20);
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

void Set_Command_Lock_25664(unsigned char d)
{
    oled_Command_25664(0xFD);			// Set Command Lock
    oled_Data_25664(0x12|d);			//   Default => 0x12
    //     0x12 => Driver IC interface is unlocked from entering command.
    //     0x16 => All Commands are locked except 0xFD.
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------


//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//  Gray Scale Table Setting (Full Screen)
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
void Set_Gray_Scale_Table_25664()
{
    oled_Command_25664(0xB8);			// Set Gray Scale Table
    oled_Data_25664(0x0C);			//   Gray Scale Level 1
    oled_Data_25664(0x18);			//   Gray Scale Level 2
    oled_Data_25664(0x24);			//   Gray Scale Level 3
    oled_Data_25664(0x30);			//   Gray Scale Level 4
    oled_Data_25664(0x3C);			//   Gray Scale Level 5
    oled_Data_25664(0x48);			//   Gray Scale Level 6
    oled_Data_25664(0x54);			//   Gray Scale Level 7
    oled_Data_25664(0x60);			//   Gray Scale Level 8
    oled_Data_25664(0x6C);			//   Gray Scale Level 9
    oled_Data_25664(0x78);			//   Gray Scale Level 10
    oled_Data_25664(0x84);			//   Gray Scale Level 11
    oled_Data_25664(0x90);			//   Gray Scale Level 12
    oled_Data_25664(0x9C);			//   Gray Scale Level 13
    oled_Data_25664(0xA8);			//   Gray Scale Level 14
    oled_Data_25664(0xB4);			//   Gray Scale Level 15
    oled_Command_25664(0x00);			// Enable Gray Scale Table
}

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
void Set_Linear_Gray_Scale_Table_25664()
{
    oled_Command_25664(
        0xB9);			// Set Default Linear Gray Scale Table
}


//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//  Initialization
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
void OLED_Init_25664()
{
    Set_Command_Lock_25664(
        0x12);			// Unlock Basic Commands (0x12/0x16)
    Set_Display_On_Off_25664(0x00);		// Display Off (0x00/0x01)
    Set_Column_Address_25664(0x1C,0x5B);
    Set_Row_Address_25664(0x00,0x3F);
    Set_Display_Clock_25664(
        0x91);		// Set Clock as 80 Frames/Sec
    Set_Multiplex_Ratio_25664(0x3F);		// 1/64 Duty (0x0F~0x3F)
    Set_Display_Offset_25664(
        0x00);		// Shift Mapping RAM Counter (0x00~0x3F)
    Set_Start_Line_25664(
        0x00);			// Set Mapping RAM Display Start Line (0x00~0x7F)
    Set_Remap_Format_25664(
        0x14);			// Set Horizontal Address Increment
    //     Column Address 0 Mapped to SEG0
    //     Disable Nibble Remap
    //     Scan from COM[N-1] to COM0
    //     Disable COM Split Odd Even
    //     Enable Dual COM Line Mode
    Set_GPIO_25664(0x00);				// Disable GPIO Pins Input
    Set_Function_Selection_25664(
        0x01);		// Enable Internal VDD Regulator
    Set_Display_Enhancement_A_25664(0xA0,
                                    0xFD);	// Enable External VSL
    Set_Contrast_Current_25664(
        0x9F);		// Set Segment Output Current
    Set_Master_Current_25664(
        0x0F);		// Set Scale Factor of Segment Output Current Control
    //Set_Gray_Scale_Table();			// Set Pulse Width for Gray Scale Table
    Set_Linear_Gray_Scale_Table_25664();	//set default linear gray scale table
    Set_Phase_Length_25664(
        0xE2);			// Set Phase 1 as 5 Clocks & Phase 2 as 14 Clocks
    Set_Display_Enhancement_B_25664(
        0x20);	// Enhance Driving Scheme Capability (0x00/0x20)
    Set_Precharge_Voltage_25664(
        0x1F);		// Set Pre-Charge Voltage Level as 0.60*VCC
    Set_Precharge_Period_25664(
        0x08);		// Set Second Pre-Charge Period as 8 Clocks
    Set_VCOMH_25664(
        0x07);			// Set Common Pins Deselect Voltage Level as 0.86*VCC
    Set_Display_Mode_25664(
        0x02);			// Normal Display Mode (0x00/0x01/0x02/0x03)
    Set_Partial_Display_25664(0x01,0x00,
                              0x00);	// Disable Partial Display

    OLED_Clear_25664();
    Set_Display_On_Off_25664(0x01);
}


