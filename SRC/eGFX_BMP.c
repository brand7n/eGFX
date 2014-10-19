#include "eGFX.h"

#ifdef WIN32

#include <stdio.h>

#endif

#ifdef FAT_FS

#include "FF.h"

#endif

#pragma pack(1)
typedef struct tagBITMAPFILEHEADER {
  uint16_t  bfType;
  uint32_t bfSize;
  uint16_t  bfReserved1;
  uint16_t  bfReserved2;
  uint32_t bfOffBits;
} BITMAPFILEHEADER;

#pragma pack(1)
typedef struct tagBITMAPINFOHEADER {
  uint32_t biSize;
  int32_t  biWidth;
  int32_t  biHeight;
  uint16_t  biPlanes;
  uint16_t  biBitCount;
  uint32_t biCompression;
  uint32_t biSizeImage;
  int32_t  biXPelsPerMeter;
  int32_t  biYPelsPerMeter;
  uint32_t biClrUsed;
  uint32_t biClrImportant;
} BITMAPINFOHEADER;



void ImagePlaneToGrayScaleBMP(char *FileName,eGFX_ImagePlane * IP)
{
	BITMAPFILEHEADER MyBMP_FileHeader;
	BITMAPINFOHEADER MyBMP_InfoHeader;
	uint32_t i, j, k, PixelOut;

	#ifdef WIN32
	FILE *MyFile;
	#endif
	
	#ifdef FAT_FS

	FIL MyFile;

	#endif

	MyBMP_FileHeader.bfType =  0x4D42;
	
	i = sizeof(BITMAPFILEHEADER);
	i = sizeof(BITMAPINFOHEADER);

	MyBMP_FileHeader.bfSize = sizeof(BITMAPFILEHEADER) +
							  sizeof(BITMAPINFOHEADER) + 
								4 * 256 +// This routine uses index color, 8-bit for gray scale.    4 bytes per palette entry
								(IP->SizeX * IP->SizeY) + 4;  //Compute the size of the bit map data assuming 1 byte per pixel
								
	MyBMP_FileHeader.bfReserved1 = 0;
	MyBMP_FileHeader.bfReserved2 = 0;
	
	MyBMP_FileHeader.bfOffBits = sizeof(BITMAPFILEHEADER)+
								sizeof(BITMAPINFOHEADER)+
								(4 * 256) + 4;// This routine uses indexed color, 8-bit for grey scale.    4 bytes per palette entry
	

	MyBMP_InfoHeader.biSize = sizeof(BITMAPINFOHEADER);
	MyBMP_InfoHeader.biWidth = IP->SizeX;
	MyBMP_InfoHeader.biHeight = IP->SizeY;

	MyBMP_InfoHeader.biPlanes = 1;
	MyBMP_InfoHeader.biBitCount = 8;
	MyBMP_InfoHeader.biCompression = 0;
	MyBMP_InfoHeader.biSizeImage = IP->SizeX * IP->SizeY;
	MyBMP_InfoHeader.biXPelsPerMeter = 10000;
	MyBMP_InfoHeader.biYPelsPerMeter = 10000;
	MyBMP_InfoHeader.biClrUsed = 256;
	MyBMP_InfoHeader.biClrImportant = 0;

	



	#ifdef WIN32
	MyFile = fopen(FileName, "w");
	if (MyFile == NULL)
		return
	#endif
#	ifdef CHAN_FAT_FS
	if (f_open(&MyFile, Filname, FA_WRITE))
		return;	
	#endif


	fwrite((const void *)&MyBMP_FileHeader, sizeof(uint8_t), 14, MyFile);
	fwrite((const void *)&MyBMP_InfoHeader, sizeof(uint8_t), 40, MyFile);

    //Write out the grey scale color data

	for (i = 0; i < 256; i++)
	{
			#ifdef WIN32
					//Write and RGBQUAD
					fputc(i, MyFile);
					fputc(i, MyFile);
					fputc(i, MyFile);
					fputc(i, MyFile);
			#endif

			#ifdef CHAN_FAT_FS
					fputc(i, &MyFile);
					fputc(i, &MyFile);
					fputc(i, &MyFile);
					fputc(i, &MyFile);
			#endif
	}

	//Write out the Bitmap Data

	for (i = 0; i < IP->SizeY; i++)
	{
		for (j = 0; j < IP->SizeX; j++)
		{
			PixelOut = eGFX_GetPixel(IP, j, IP->SizeY - i  - 1);

			switch (IP->Type)
			{
				case eGFX_IMAGE_PLANE_1BPP:

					break;

				case eGFX_IMAGE_PLANE_4BPP:
					PixelOut = (PixelOut << 4) & 0xFF;
					break;

				default:
				case eGFX_IMAGE_PLANE_8BPP:

					break;
			}

		#ifdef WIN32
			fputc((uint8_t)PixelOut, MyFile);
		#endif
		#ifdef CHAN_FAT_FS
			f_putc((uint8_t)PixelOut, &MyFile);
		#endif
		}

		//BMPs must be on a 32-bit boundary.  Pad with some zeros.

		if (IP->SizeX & 0x3)
		{
			for (k = 0; k < 0x4 - (IP->SizeX & 0x3); k++)
			{
				fputc(0, MyFile);
			}
		}
	}

	#ifdef WIN32
		fclose(MyFile);
	#endif

	#ifdef CHAN_FAT_FS
		fclose(&MyFile);
	#endif

}


