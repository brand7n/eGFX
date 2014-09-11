
#include "eGFX_DataTypes.h"
#include "eGFX.h"
#include "eGFX_Driver_Win32.h"
#include "TestSprites_1BPP.h"
#include "TestSprites_4BPP.h"
#include "TestSprites_8BPP.h"
#include "Arial__24px__Regular__AntiAliasGridFit_4BPP.h"
#include "Arial__24px__Regular__SingleBitPerPixelGridFit_4BPP.h" 
#include "FONT_3_5_1BPP.h"
#include "FONT_3_5_4BPP.h"
#include "FONT_3_5_8BPP.h"

#include "FONT_5_7_1BPP.h"
#include "FONT_5_7_4BPP.h"
#include "FONT_5_7_8BPP.h"


eGFX_PointF_BisectAnimator MyPBA[4];
eGFX_PointF_LinearAnimator MyPLA[4];

eGFX_ScalarF_LinearAnimator MySLA[2];
eGFX_ScalarF_BisectAnimator MySBA[2];


eGFX_Obj_TextF	MyTextF[4];
eGFX_Obj_LineF	MyLineF[2];
eGFX_Obj_SpriteF MySpriteF;
eGFX_Obj_ScaledSpriteF MyScaledSpriteF;
eGFX_Obj_ShadedTextF MyShadedTextF;
eGFX_Obj_BoxF MyBoxF[2];
eGFX_Obj_CircleF MyCircleF[2];

float Scale = 0.1f;

void eGFX_InitTestDrawLoop(uint32_t Mode)
{
	eGFX_PointF P;
	switch (Mode)
	{


	case 21:

		eGFX_ClearObjects();

		eGFX_AddObjectCircleF(&MyCircleF[0], (eGFX_PointF){ eGFX_PHYSICAL_SCREEN_SIZE_X / 3, eGFX_PHYSICAL_SCREEN_SIZE_Y / 2 },0.0f,eGFX_PIXEL_ON, eGFX_CIRCLEF_RENDER_OPTION_OUTLINE);
		eGFX_AddObjectCircleF(&MyCircleF[1], (eGFX_PointF){ ( eGFX_PHYSICAL_SCREEN_SIZE_X* 2) / 3, eGFX_PHYSICAL_SCREEN_SIZE_Y / 2 }, 0.0f, eGFX_PIXEL_ON, eGFX_CIRCLEF_RENDER_OPTION_FILLED);

		eGFX_ClearAnimators();

		eGFX_AddScalarF_LinearAnimator(&MySLA[0], 32.0f, &MyCircleF[0].Radius, 128, 1.0f);
		eGFX_AddScalarF_LinearAnimator(&MySLA[1], 32.0f, &MyCircleF[1].Radius, 128, 1.0f);

		break;

	case 20:

		eGFX_ClearObjects();

		eGFX_AddObjectBoxF(&MyBoxF[0], (eGFX_PointF){ 0, 0 }, (eGFX_PointF){ 0, 0 }, eGFX_PIXEL_ON, eGFX_BOXF_RENDER_OPTION_OUTLINE);
		eGFX_AddObjectBoxF(&MyBoxF[1], (eGFX_PointF){ 0, 0 }, (eGFX_PointF){ 0, 0 }, eGFX_PIXEL_ON, eGFX_BOXF_RENDER_OPTION_FILLED);


		eGFX_ClearAnimators();

		P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
		P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

		eGFX_AddPointF_BisectAnimator(&MyPBA[0], P, &MyBoxF[0].P1, 128, 0.2f);

		P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
		P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

		eGFX_AddPointF_BisectAnimator(&MyPBA[1], P, &MyBoxF[0].P2, 128, 0.2f);

		P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
		P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

		eGFX_AddPointF_BisectAnimator(&MyPBA[2], P, &MyBoxF[1].P1, 128, 0.2f);

		P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
		P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

		eGFX_AddPointF_BisectAnimator(&MyPBA[3], P, &MyBoxF[1].P2, 128, 0.2f);

		
		break;

	case 19:

		eGFX_ClearObjects();

		eGFX_AddObjectShadedTextF(&MyShadedTextF, (eGFX_PointF){ 64.0, 32 }, &FONT_5_7_4BPP, "Shaded", 0);
		
		eGFX_ClearAnimators();

		eGFX_AddScalarF_LinearAnimator(&MySLA[0], 1.0f, &MyShadedTextF.Shading, 128, .0625f);

		break;


	case 18:


		eGFX_ClearObjects();

		eGFX_AddObjectScaledSpriteF(&MyScaledSpriteF, (eGFX_PointF){ eGFX_PHYSICAL_SCREEN_SIZE_X / 2, eGFX_PHYSICAL_SCREEN_SIZE_Y / 2 }, &Sprite_4BPP_Rocket, 0.1f);

		eGFX_ClearAnimators();

		eGFX_AddScalarF_BisectAnimator(&MySBA[0], 2.0, &MyScaledSpriteF.Scale, 128, 0.5);

		break;


	case 17:


		eGFX_ClearObjects();

		eGFX_AddObjectSpriteF(&MySpriteF, (eGFX_PointF){ eGFX_PHYSICAL_SCREEN_SIZE_X / 2, eGFX_PHYSICAL_SCREEN_SIZE_Y / 2 }, &Sprite_4BPP_Rocket);

		eGFX_ClearAnimators();

		P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X/2);
		P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y/2);

		//eGFX_AddPointF_BisectAnimator(&MyPBA[0],P, &MySpriteF.Position, 128, 0.2f);

		break;



	case 16:

		eGFX_ClearObjects();

		eGFX_AddObjectLineF(&MyLineF[0], (eGFX_PointF){ 0, 0 }, (eGFX_PointF){ 0, 0 }, eGFX_PIXEL_ON);
		eGFX_AddObjectLineF(&MyLineF[1], (eGFX_PointF){ 0, 0 }, (eGFX_PointF){ 0, 0 }, eGFX_PIXEL_ON);

		eGFX_ClearAnimators();

		P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
		P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

		eGFX_AddPointF_BisectAnimator(&MyPBA[0], P, &MyLineF[0].Start, 128, 0.2f);

		P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
		P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

		eGFX_AddPointF_BisectAnimator(&MyPBA[1], P, &MyLineF[0].End, 128, 0.2f);

		P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
		P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

		eGFX_AddPointF_BisectAnimator(&MyPBA[2], P, &MyLineF[1].Start, 128, 0.2f);

		P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
		P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

		eGFX_AddPointF_BisectAnimator(&MyPBA[3], P, &MyLineF[1].End, 128, 0.2f);

		break;

	case 15:


		eGFX_ClearObjects();

		eGFX_AddObjectTextF(&MyTextF[0], (eGFX_PointF){ 0.0, 0.0 }, &FONT_5_7_4BPP, "test1");
		eGFX_AddObjectTextF(&MyTextF[1], (eGFX_PointF){ 0.0, 0.0 }, &FONT_5_7_4BPP, "test2");
		eGFX_AddObjectTextF(&MyTextF[2], (eGFX_PointF){ 0.0, 0.0 }, &FONT_5_7_4BPP, "test3");
		eGFX_AddObjectTextF(&MyTextF[3], (eGFX_PointF){ 0.0, 0.0 }, &FONT_5_7_4BPP, "test4");

		eGFX_ClearAnimators();

		P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
		P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

		eGFX_AddPointF_LinearAnimator(&MyPLA[0], P, &MyTextF[0].Position, 128, 4.0f,7.9f);

		P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
		P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

		eGFX_AddPointF_LinearAnimator(&MyPLA[1], P, &MyTextF[1].Position, 128, 5.0f,4.4f);

		P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
		P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

		eGFX_AddPointF_LinearAnimator(&MyPLA[2], P, &MyTextF[2].Position, 128, 9.0f,5.0f);

		P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
		P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

		eGFX_AddPointF_LinearAnimator(&MyPLA[3], P, &MyTextF[3].Position, 128, 5.0f,5.0f);

		break;

	case 14:


		eGFX_ClearObjects();

		eGFX_AddObjectTextF(&MyTextF[0], (eGFX_PointF){ 0.0, 0.0 }, &FONT_5_7_4BPP, "test1");
		eGFX_AddObjectTextF(&MyTextF[1], (eGFX_PointF){ 0.0, 0.0 }, &FONT_5_7_4BPP, "test2");
		eGFX_AddObjectTextF(&MyTextF[2], (eGFX_PointF){ 0.0, 0.0 }, &FONT_5_7_4BPP, "test3");
		eGFX_AddObjectTextF(&MyTextF[3], (eGFX_PointF){ 0.0, 0.0 }, &FONT_5_7_4BPP, "test4");

		eGFX_ClearAnimators();

		P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
		P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

		eGFX_AddPointF_BisectAnimator(&MyPBA[0], P, &MyTextF[0].Position, 128, 0.2f);

		P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
		P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

		eGFX_AddPointF_BisectAnimator(&MyPBA[1], P, &MyTextF[1].Position, 128, 0.2f);

		P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
		P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

		eGFX_AddPointF_BisectAnimator(&MyPBA[2], P, &MyTextF[2].Position, 128, 0.2f);

		P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
		P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

		eGFX_AddPointF_BisectAnimator(&MyPBA[3], P, &MyTextF[3].Position, 128, 0.2f);

		break;

		
		default:

			break;


	}

}

void eGFX_TestDrawLoop(uint32_t Mode)
{
	eGFX_PointF P;



	switch (Mode)
	{

	case 21:

		eGFX_ImagePlane_Clear(&eGFX_BackBuffer);

		eGFX_DrawObjects(&eGFX_BackBuffer);

		eGFX_ProcessAnimators();

		if (eGFX_AnimatorsComplete() == TRUE)
		{
			MyCircleF[0].Radius = 0.0;
			MyCircleF[1].Radius = 0.0;

			eGFX_InitScalarF_LinearAnimator(&MySLA[0], 32.0f, &MyCircleF[0].Radius, 128, 1.0f);
			eGFX_InitScalarF_LinearAnimator(&MySLA[1], 32.0f, &MyCircleF[1].Radius, 128, 1.0f);
		}

		break;


	case 20:
		
		eGFX_ImagePlane_Clear(&eGFX_BackBuffer);

		eGFX_DrawObjects(&eGFX_BackBuffer);

		eGFX_ProcessAnimators();


		if (eGFX_AnimatorsComplete() == TRUE)
		{
			P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
			P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

			eGFX_InitPointF_BisectAnimator(&MyPBA[0], P, &MyBoxF[0].P1, 128, 0.3f);

			P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
			P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

			eGFX_InitPointF_BisectAnimator(&MyPBA[1], P, &MyBoxF[0].P2, 128, 0.5f);

			P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
			P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

			eGFX_InitPointF_BisectAnimator(&MyPBA[2], P, &MyBoxF[1].P1, 128, 0.4f);

			P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
			P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

			eGFX_InitPointF_BisectAnimator(&MyPBA[3], P, &MyBoxF[1].P2, 128, 0.4f);
		}


		break;



	case 19:


		eGFX_ImagePlane_Clear(&eGFX_BackBuffer);

		eGFX_DrawObjects(&eGFX_BackBuffer);

		eGFX_ProcessAnimators();

		if (eGFX_AnimatorsComplete() == TRUE)
		{
			MyShadedTextF.Shading = 0.0;

			eGFX_InitScalarF_LinearAnimator(&MySLA[0], 1.0f, &MyShadedTextF.Shading, 128, 0.0625f);
		}

		break;



	case 18:

		eGFX_ImagePlane_Clear(&eGFX_BackBuffer);

		eGFX_DrawObjects(&eGFX_BackBuffer);

		eGFX_ProcessAnimators();

		if (eGFX_AnimatorsComplete() == TRUE)
		{
			MyScaledSpriteF.Scale = 0.05f;
			eGFX_InitScalarF_BisectAnimator(&MySBA[0], 2.0f, &MyScaledSpriteF.Scale, 128, 0.05f);
		}
		break;


	case 17:

		eGFX_ImagePlane_Clear(&eGFX_BackBuffer);

		eGFX_DrawObjects(&eGFX_BackBuffer);

		/*eGFX_ProcessAnimators();

		if (eGFX_AnimatorsComplete() == FALSE)
		{

		}
		else
		{
			P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
			P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

			eGFX_InitPointF_BisectAnimator(&MyPBA[0], P, &MySpriteF.Position, 128, 0.2f);
		}
		break;
		*/

		break;

	case 16:
		eGFX_ImagePlane_Clear(&eGFX_BackBuffer);

		eGFX_DrawObjects(&eGFX_BackBuffer);

		eGFX_ProcessAnimators();

		if (eGFX_AnimatorsComplete() == FALSE)
		{

		}
		else
		{
			P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
			P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

			eGFX_InitPointF_BisectAnimator(&MyPBA[0], P, &MyLineF[0].Start, 128, 0.2f);

			P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
			P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

			eGFX_InitPointF_BisectAnimator(&MyPBA[1], P, &MyLineF[0].End, 128, 0.2f);

			P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
			P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

			eGFX_InitPointF_BisectAnimator(&MyPBA[2], P, &MyLineF[1].Start, 128, 0.2f);

			P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
			P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

			eGFX_InitPointF_BisectAnimator(&MyPBA[3], P, &MyLineF[1].End, 128, 0.2f);

		}
		break;

	case 15:

		eGFX_ImagePlane_Clear(&eGFX_BackBuffer);

		eGFX_DrawObjects(&eGFX_BackBuffer);

		eGFX_ProcessAnimators();

		if (eGFX_AnimatorsComplete() == FALSE)
		{

		}
		else
		{
			P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
			P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

			eGFX_InitPointF_LinearAnimator(&MyPLA[0], P, &MyTextF[0].Position, 128, 1.0f,1.0f);
			
			P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
			P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

			eGFX_InitPointF_LinearAnimator(&MyPLA[1], P, &MyTextF[1].Position, 128, 2.0f,3.0f);

			P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
			P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

			eGFX_InitPointF_LinearAnimator(&MyPLA[2], P, &MyTextF[2].Position, 128, 3.0f,5.0f);

			P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
			P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

			eGFX_InitPointF_LinearAnimator(&MyPLA[3], P, &MyTextF[3].Position, 128, 5.0f,5.0f);

		}
		break;


	case 14:
		eGFX_ImagePlane_Clear(&eGFX_BackBuffer);

		eGFX_DrawObjects(&eGFX_BackBuffer);

		eGFX_ProcessAnimators();

		if (eGFX_AnimatorsComplete() == FALSE)
		{
			
		}
		else
		{
			P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
			P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

			eGFX_InitPointF_BisectAnimator(&MyPBA[0], P, &MyTextF[0].Position, 128, 0.1f);

			P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
			P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

			eGFX_InitPointF_BisectAnimator(&MyPBA[1], P, &MyTextF[1].Position, 128, 0.2f);

			P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
			P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

			eGFX_InitPointF_BisectAnimator(&MyPBA[2], P, &MyTextF[2].Position, 128, 0.3f);

			P.X = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_X);
			P.Y = (float)(rand() % eGFX_PHYSICAL_SCREEN_SIZE_Y);

			eGFX_InitPointF_BisectAnimator(&MyPBA[3], P, &MyTextF[3].Position, 128, 0.4f);

		}
		break;

	default:
		case 0:
			eGFX_ImagePlane_Clear(&eGFX_BackBuffer);
			eGFX_DrawLine(&eGFX_BackBuffer, 0, 0, eGFX_PHYSICAL_SCREEN_SIZE_X - 1, eGFX_PHYSICAL_SCREEN_SIZE_Y - 1, eGFX_PIXEL_ON);
			eGFX_DrawLine(&eGFX_BackBuffer, 0, eGFX_PHYSICAL_SCREEN_SIZE_Y - 1, eGFX_PHYSICAL_SCREEN_SIZE_X - 1,0 , eGFX_PIXEL_ON);
		break;

		case 1:
			eGFX_ImagePlane_Clear(&eGFX_BackBuffer);
			eGFX_DrawHline(&eGFX_BackBuffer, 0, eGFX_PHYSICAL_SCREEN_SIZE_X - 1, eGFX_PHYSICAL_SCREEN_SIZE_Y >> 1, eGFX_PIXEL_ON);
			eGFX_DrawVline(&eGFX_BackBuffer, 0, eGFX_PHYSICAL_SCREEN_SIZE_Y - 1, eGFX_PHYSICAL_SCREEN_SIZE_X >> 1, eGFX_PIXEL_ON);
		break;

		case 2:
			eGFX_ImagePlane_Clear(&eGFX_BackBuffer);
			eGFX_DrawCircle(&eGFX_BackBuffer, eGFX_PHYSICAL_SCREEN_SIZE_X >> 1, eGFX_PHYSICAL_SCREEN_SIZE_Y >> 1, 10, eGFX_PIXEL_ON);
			eGFX_DrawCircle(&eGFX_BackBuffer, eGFX_PHYSICAL_SCREEN_SIZE_X >> 1, eGFX_PHYSICAL_SCREEN_SIZE_Y >> 1, 20, eGFX_PIXEL_ON);
			eGFX_DrawCircle(&eGFX_BackBuffer, eGFX_PHYSICAL_SCREEN_SIZE_X >> 1, eGFX_PHYSICAL_SCREEN_SIZE_Y >> 1, 30, eGFX_PIXEL_ON);

			break;

		case 3:
			eGFX_ImagePlane_Clear(&eGFX_BackBuffer);
			eGFX_Blit(&eGFX_BackBuffer, 0, 0, &Sprite_1BPP_SheldonFace);

			break;

		case 4:
			eGFX_ImagePlane_Clear(&eGFX_BackBuffer);
			eGFX_Blit(&eGFX_BackBuffer, 0, 0, &Sprite_4BPP_SheldonFace);

			break;

		case 5:
			eGFX_ImagePlane_Clear(&eGFX_BackBuffer);
			eGFX_Blit(&eGFX_BackBuffer, 0, 0, &Sprite_8BPP_SheldonFace);

			break;

		case 6:
			eGFX_ImagePlane_Clear(&eGFX_BackBuffer);
			eGFX_DrawString(&eGFX_BackBuffer, "Test!", 10, 10, &Arial__24px__Regular__AntiAliasGridFit_4BPP);

			break;

		case 7:
			eGFX_ImagePlane_Clear(&eGFX_BackBuffer);
			eGFX_DrawString(&eGFX_BackBuffer, "Test!", 10, 10, &Arial__24px__Regular__SingleBitPerPixelGridFit_4BPP);
			break;

		case 8:
			eGFX_ImagePlane_Clear(&eGFX_BackBuffer);
			eGFX_DrawString(&eGFX_BackBuffer, "Test!", 10, 10, &FONT_3_5_1BPP);
			break;

		case 9:
			eGFX_ImagePlane_Clear(&eGFX_BackBuffer);
			eGFX_DrawString(&eGFX_BackBuffer, "Test!", 10, 10, &FONT_3_5_4BPP);
			break;

		case 10:
			eGFX_ImagePlane_Clear(&eGFX_BackBuffer);
			eGFX_DrawString(&eGFX_BackBuffer, "Test!", 10, 10, &FONT_3_5_8BPP);
			break;


		case 11:
			eGFX_ImagePlane_Clear(&eGFX_BackBuffer);
			eGFX_DrawString(&eGFX_BackBuffer, "Test!", 10, 10, &FONT_5_7_1BPP);
			break;

		case 12:
			eGFX_ImagePlane_Clear(&eGFX_BackBuffer);
			eGFX_DrawString(&eGFX_BackBuffer, "Test!", 10, 10, &FONT_5_7_4BPP);
			break;

		case 13:
			eGFX_ImagePlane_Clear(&eGFX_BackBuffer);
			eGFX_DrawString(&eGFX_BackBuffer, "Test!", 10, 10, &FONT_5_7_8BPP);
			break;

	}
	
	//now need to call eGFX_Dump.... the windows code will do the operation later

}